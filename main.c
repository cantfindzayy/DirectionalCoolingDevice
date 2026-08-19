/*
 * main.c
 *
 * STM32L476 main program
 *
 * Uses:
 *   - DHT22 on D7 / PA8
 *   - LCD display
 *   - Servo on PA0 / TIM2_CH1
 *
 * This version tests the servo without a PIR sensor.
 */

#include "stm32l476xx.h"
#include "DHT22.h"
#include <stdint.h>
#include "Servo.h"

#define PB6  6
#define PB10 10
#define CNT_PSC	16
#define CNT_CLK_PERIOD_IN_MICRO_SECOND 1 //counter clock period in microsecond

volatile int overflow = 0;
volatile int current_CCR = 0;
volatile int previous_CCR = 0;
volatile int time_span = 0;
volatile float distance = 0;
volatile int new_measurement = 0;

void LCD_Init(void);
void lcd_clear(void);
void lcd_put_cur(uint8_t row, uint8_t col);
void lcd_send_string(char *str);

void FPU_Enable(){

    SCB->CPACR |= ((3UL << 20U) | (3UL << 22U));
}


void configure_PB6(){
  // 1. Enable the clock to GPIO Port B
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

	// 2. Configure GPIO Mode to 'Alternative Function' mode: Input(00), Output(01), Alternative Function(10), Analog(11)
	GPIOB->MODER &= ~(0b11<<(2*PB6));
	GPIOB->MODER |=   0b10<<(2*PB6);

	// 3. Select PA1's alternative function as TIM4_CH1, which is 'AF2', by configuring the GPIOA_AFRL register
	GPIOB->AFR[0] &= ~(0b1111 << (4*PB6));
	GPIOB->AFR[0] |= (0b0010 << (4*PB6));

}

void configure_PB10(){
  // 1. Enable the clock to GPIO Port B
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

	// 2. Configure GPIO Mode to 'Alternative Function' mode: Input(00), Output(01), Alternative Function(10), Analog(11)
	GPIOB->MODER &= ~(0b11<<(2*PB10));
	GPIOB->MODER |=   0b10<<(2*PB10);

	// 3. Select PA1's alternative function as TIM2_CH3, which is 'AF1', by configuring the GPIOA_AFRH register
	GPIOB->AFR[1] &= ~(0b1111 << (4*(PB10-8)));
	GPIOB->AFR[1] |= (0b0001 << (4*(PB10-8)));

	// 4. Configure GPIO Output Type to 'Push-Pull': Output push-pull (0), Output open drain (1)
	GPIOB->OTYPER &= ~(1<<PB10);      // Push-pull

	// 5. Configure GPIO Push-Pull to 'No Pull-up or Pull-down': No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOB->PUPDR  &= ~(0b11<<(2*PB10));  // No pull-up, no pull-down
}
void TIM2_CH3_Init(){//pb10 trigger PmW

		//1. Enable the clock to TIM2 by configuring RCC_APB1ENR1 register
    RCC->APB1ENR1	|= RCC_APB1ENR1_TIM2EN;

		//2. Configure TIM2 counting mode to upcounting (TIMx_CR1)
		TIM2->CR1 &= ~TIM_CR1_DIR;

		//3. Configure TIM5 Prescalar (TIMx_PSC) and ARR (TIMx_ARR) to generate a counter period of 100 ms
    TIM2->PSC = CNT_PSC-1;       // Prescaler
	  TIM2->ARR = 10000-1;   // Note: there are many possible combinations of PSC and ARR. This is just one solution

		//4. Configure TIMx_CCMR2 CC3S[1:0] bits to output mode for TIM2 Channel 3
		TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;

		//5. Configure TIMx_CCMR2 OC3M[3:0] bits to PWM mode 1 ('0110') for TIM2 Channel 3
		TIM2->CCMR2 &= ~TIM_CCMR2_OC3M;  // Clear ouput compare mode bits for channel 3
    TIM2->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1; // OC2M = 0110 for PWM Mode 1 output on ch3


    //6. Set TIMx_CCER CC3E bit to enable output signal on Channel 3
		TIM2->CCER |= TIM_CCER_CC3E;

		TIM2->CCR3  = 10;  // 10 us

		//7. Set TIMx_CR1 CEN bit to enable the TIM2 counter
		TIM2->CR1  |= TIM_CR1_CEN; // Enable counter
}

void TIM4_CH1_Init(void) {//pb6 echo

	//1. Enable the clock to TIM4 by configuring RCC_APB1ENR1 register
	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM4EN;

	//2. Configure TIM4 counting mode to upcounting (TIMx_CR1)
	TIM4->CR1 &= ~TIM_CR1_DIR;

	//3. Configure TIM4 Prescalar (TIMx_PSC) and ARR (TIMx_ARR) to generate a desired counter period
	TIM4->PSC = CNT_PSC-1;		// Set up an appropriate prescaler to slow down the clock or timer counter
	TIM4->ARR = 10000-1;

	//4. Configure TIMx_CCMR1 CC1S[1:0] bits for TIM4 Channel 1
	//   to set the Capture/Compare channel direction as input,
	//   and input channel (CC1) is mapped on Timer Input 1 (TI1)
	//   00 = output
	//   01 = input, CC1 is mapped on timer Input 1 (TI1)
	//   10 = input, CC1 is mapped on timer Input 2 (TI2)
	//   11 = input, CC1 is mapped on slave timer
	TIM4->CCMR1 &= ~TIM_CCMR1_CC1S;
	TIM4->CCMR1 |= TIM_CCMR1_CC1S_0;

	// 5. Disable digital filtering by configuring TIMx_CCMR1 IC1F[3:0] bits
	//    because we want to capture every event
	TIM4->CCMR1 &= ~TIM_CCMR1_IC1F;

	// 6. Program the input prescaler by configuring TIMx_CCMR1 IC1PSC[1:0] bits
	// To capture each valid transition, set the input prescaler to zero;
	TIM4->CCMR1 &= ~(TIM_CCMR1_IC1PSC); // Clear filtering because we need to capture every event

	// 7. Select the active edge(s) for trigger of input capture operaiton
	//    by configuring TIMx_CCER CC1NP and CC1P bits
	// CC1NP=0, CC1P=0: rising edge,
	// CC1NP=0, CC1P=1: falling edge,
	// CC1NP=1, CC1P=0: reserved,
	// CC1NP=1, CC1P=1: both edges
	TIM4->CCER |= (TIM_CCER_CC1NP | TIM_CCER_CC1P);		// Both rising and falling edges.

	// 8. Enable Input Capture mode by setting TIMx_CCER CC1E bit
	TIM4->CCER |= TIM_CCER_CC1E;

	// 9. Enable related interrupts by
	//		i. configuring TIMx_DIER register
	TIM4->DIER |= TIM_DIER_CC1IE;		// Enable Capture/Compare interrupts for channel 1
	TIM4->DIER |= TIM_DIER_UIE;			// Enable update interrupts

	//    ii. enable TIM4 interrupt source in NVIC
	NVIC_EnableIRQ(TIM4_IRQn);      // Enable TIM4 interrupt in NVIC

	//10. Set TIMx_CR1 CEN bit to enable the TIM4 counter
	TIM4->CR1 |= TIM_CR1_CEN;				// Enable the counter
}

//TIM4 ISR
void TIM4_IRQHandler(void) {

    if (TIM4->SR & TIM_SR_UIF) {
        TIM4->SR &= ~TIM_SR_UIF;
        overflow++;
    }

    if (TIM4->SR & TIM_SR_CC1IF) {
        current_CCR = TIM4->CCR1;
        TIM4->SR &= ~TIM_SR_CC1IF;

        time_span = ((current_CCR - previous_CCR) + (overflow * 10000)) * CNT_CLK_PERIOD_IN_MICRO_SECOND;
        previous_CCR = current_CCR;
        overflow = 0;
        new_measurement = 1;
    }
}


// Global state variable
volatile uint8_t fan_state = 0;

void init_hardware(void) {
    /* 1. Enable Clocks for GPIOA (Fan) and GPIOC (Button) */
    RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOAEN);

    /* 2. Configure PA5 as Output (Fan) */
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));
}

void SystemClock_Config(void)
{
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY));

    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_HSI;

    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);
}

/*

/ ----------------------------------------------------

Simple delay*
Rough delay for visible servo movement.
---------------------------------------------------- */
void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        for (volatile uint32_t j = 0; j < 4000; j++);
    }
}


/* ----------------------------------------------------

main()
---------------------------------------------------- */

int main(void)
{

    SystemClock_Config();
    FPU_Enable();

    init_hardware();

    configure_PB6();       // Echo
    configure_PB10();      // Trigger

    TIM4_CH1_Init();       // Echo input capture
    TIM2_CH3_Init();       // Trigger pulse

    DWT_Delay_Init();

    LCD_Init();
    DHT_SetPinInput();

    delay_us(3000000);


	while (1)
	{
	    if (new_measurement)
	    {
	        new_measurement = 0;

	        distance = ((float)time_span * 0.0343f) / 2.0f;

	        if (distance > 2.0f && distance <= 10.0f)
	        {
	            // Object detected: show DHT reading
	            DHT_Display();
	            GPIOA->BSRR = (1U << 5);
	        }
	        else
	        {
	            // Nothing detected: clear LCD
	            lcd_clear();
	            lcd_put_cur(0, 0);
	            lcd_send_string("No object");
	            GPIOA->BSRR = (1u << 21);
	        }
	    }

	    delay_ms(200);
	}

	}
