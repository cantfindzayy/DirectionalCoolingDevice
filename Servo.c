/*
 * servo.c
 *
 * Servo driver for STM32L476
 *
 * Servo signal:
 *   PA6 = TIM3_CH1
 *
 * PWM requirements:
 *   Frequency: 50 Hz
 *   Period: 20 ms
 *
 * Pulse width:
 *   1000 us = 0 degrees
 *   1500 us = 90 degrees
 *   2000 us = 180 degrees
 */

#include "servo.h"

/* ----------------------------------------------------
 * Servo_Init()
 *
 * Configures PA6 as TIM3_CH1 PWM output.
 * ---------------------------------------------------- */
void Servo_Init(void)
{
    /* Enable GPIOA clock */
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    /* Enable TIM3 clock */
    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM3EN;

    /* Set PA6 to alternate function mode */
    GPIOA->MODER &= ~(0b11 << (2 * 6));
    GPIOA->MODER |=  (0b10 << (2 * 6));

    /* Select AF2 for PA6 = TIM3_CH1 */
    GPIOA->AFR[0] &= ~(0b1111 << (4 * 6));
    GPIOA->AFR[0] |=  (0b0010 << (4 * 6));

    /*
     * Timer setup:
     * System clock = 16 MHz
     * Prescaler = 16 - 1
     * Timer clock = 1 MHz
     * 1 count = 1 microsecond
     */
    TIM3->PSC = 40 - 1;

    /*
     * Servo period = 20 ms = 20000 us
     */
    TIM3->ARR = 20000 - 1;

    /*
     * PWM mode 1 on channel 1.
     */
    TIM3->CCMR1 &= ~TIM_CCMR1_OC1M;
    TIM3->CCMR1 |=  (6 << TIM_CCMR1_OC1M_Pos);

    /*
     * Enable preload for channel 1.
     */
    TIM3->CCMR1 |= TIM_CCMR1_OC1PE;

    /*
     * Enable TIM3 channel 1 output.
     */
    TIM3->CCER |= TIM_CCER_CC1E;

    /*
     * Enable auto-reload preload.
     */
    TIM3->CR1 |= TIM_CR1_ARPE;

    /*
     * Start at 0 degrees.
     */
    TIM3->CCR1 = 1000;

    /*
     * Start timer.
     */
    TIM3->CR1 |= TIM_CR1_CEN;
}

/* ----------------------------------------------------
 * Servo_SetAngle()
 *
 * Converts angle to PWM pulse width:
 *
 *   angle 0   -> 1000 us
 *   angle 90  -> 1500 us
 *   angle 180 -> 2000 us
 * ---------------------------------------------------- */
void Servo_SetAngle(uint8_t angle)
{
    uint16_t pulse;

    if (angle > 180)
    {
        angle = 180;
    }

    pulse = 1000 + ((angle * 1000) / 180);

    TIM3->CCR1 = pulse;
}
