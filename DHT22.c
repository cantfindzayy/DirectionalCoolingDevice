/*
 * DHT22.c
 *
 * STM32L476 + DHT22 driver
 *
 * DHT22 DATA pin:
 *   D7 = PA8
 *
 * This version:
 *   - Does NOT use TIM4
 *   - Does NOT use PB6
 *   - Does NOT use SystemCoreClock
 *   - Assumes HSI clock = 16 MHz
 */

#include "DHT22.h"
#include <stdio.h>
#include "core_cm4.h"

/* ----------------------------------------------------
 * LCD function prototypes
 *
 * IMPORTANT:
 * These names must match your LCD driver.
 *
 * If your LCD file uses different names, change these
 * and all calls below.
 * ---------------------------------------------------- */
void lcd_clear(void);
void lcd_put_cur(uint8_t row, uint8_t col);
void lcd_send_string(char *str);

/* Raw DHT22 data bytes */
static uint8_t Rh_byte1;
static uint8_t Rh_byte2;
static uint8_t Temp_byte1;
static uint8_t Temp_byte2;

/* Combined raw values */
static uint16_t RH;
static uint16_t TEMP;

/* Public sensor values */
float Temperature = 0.0f;
float Humidity = 0.0f;

/* ----------------------------------------------------
 * DWT_Delay_Init()
 *
 * Enables the Cortex-M4 DWT cycle counter.
 * This lets us create accurate microsecond delays.
 * ---------------------------------------------------- */
void DWT_Delay_Init(void)
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    DWT->CYCCNT = 0;
}

/* ----------------------------------------------------
 * delay_us()
 *
 * Microsecond delay.
 *
 * This version assumes system clock = HSI 16 MHz.
 * At 16 MHz:
 *   1 microsecond = 16 CPU cycles
 * ---------------------------------------------------- */
void delay_us(uint32_t us)
{
    uint32_t start;
    uint32_t ticks;

    /*
     * Safety: make sure cycle counter is enabled.
     */
    if ((DWT->CTRL & DWT_CTRL_CYCCNTENA_Msk) == 0)
    {
        DWT_Delay_Init();
    }

    start = DWT->CYCCNT;
    ticks = us * 16U;

    while ((DWT->CYCCNT - start) < ticks)
    {
        /*
         * wait
         */
    }
}

/* ----------------------------------------------------
 * Configure D7 / PA8 as output open-drain.
 *
 * Used when STM32 pulls DHT22 DATA line LOW.
 * ---------------------------------------------------- */
static void DHT_SetPinOutput(void)
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

    DHT_PORT->MODER &= ~(0b11 << (2 * DHT_PIN));
    DHT_PORT->MODER |=  (0b01 << (2 * DHT_PIN));

    DHT_PORT->OTYPER |= (1 << DHT_PIN);          // open-drain
    DHT_PORT->PUPDR &= ~(0b11 << (2 * DHT_PIN)); // no pull

    DHT_PORT->OSPEEDR &= ~(0b11 << (2 * DHT_PIN));
    DHT_PORT->OSPEEDR |=  (0b10 << (2 * DHT_PIN));

    DHT_PORT->ODR &= ~(1 << DHT_PIN);            // drive low when output
}
/* ----------------------------------------------------
 * Configure D7 / PA8 as input with pull-up.
 *
 * This is the idle/listening state.
 * ---------------------------------------------------- */
void DHT_SetPinInput(void)
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

    DHT_PORT->MODER &= ~(0b11 << (2 * DHT_PIN));

    /* No internal pull-up/pull-down */
    DHT_PORT->PUPDR &= ~(0b11 << (2 * DHT_PIN));
}
/* Drive PA8 LOW */
static void DHT_PinLow(void)
{
    DHT_PORT->ODR &= ~(1 << DHT_PIN);
}

/* Release PA8 HIGH */
static void DHT_PinHigh(void)
{
    DHT_PORT->ODR |= (1 << DHT_PIN);
}

/* Read PA8 input state */
static uint8_t DHT_ReadPin(void)
{
    if (DHT_PORT->IDR & (1 << DHT_PIN))
        return 1;
    else
        return 0;
}

/* ----------------------------------------------------
 * Send start signal to DHT22.
 *
 * DHT22:
 *   DATA LOW for > 1 ms
 *   DATA HIGH for 20-40 us
 * ---------------------------------------------------- */
static void DHT_Start(void)
{
    DHT_SetPinOutput();

    DHT_PinLow();
    delay_us(2000);   // 2 ms for DHT22

    DHT_SetPinInput();

    delay_us(40);
}
/* ----------------------------------------------------
 * Check DHT22 response.
 *
 * Returns:
 *   1 = response received
 *   0 = no response
 * ---------------------------------------------------- */
static uint8_t wait_for_pin(uint8_t state, uint32_t timeout_us)
{
    while (timeout_us--)
    {
        if (DHT_ReadPin() == state)
        {
            return 1;
        }

        delay_us(1);
    }

    return 0;
}
/* ----------------------------------------------------
 * Simple millisecond delay.
 * Used only for LCD screen timing.
 * ---------------------------------------------------- */
static void delay_ms_simple(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        delay_us(1000);
    }
}

static uint8_t DHT_Check_Response(void)
{
    /* DHT22 should pull line LOW after host releases it */
    if (!wait_for_pin(0, 500))
    {
        return 0;
    }

    /* DHT22 then pulls line HIGH */
    if (!wait_for_pin(1, 500))
    {
        return 0;
    }

    /* DHT22 then pulls line LOW again before sending data bits */
    if (!wait_for_pin(0, 500))
    {
        return 0;
    }

    return 1;
}
/* ----------------------------------------------------
 * Read one byte from DHT22.
 *
 * Short HIGH pulse = 0
 * Long HIGH pulse  = 1
 * ---------------------------------------------------- */
static uint8_t DHT_Read(void)
{
    uint8_t data = 0;

    for (uint8_t i = 0; i < 8; i++)
    {
        if (!wait_for_pin(1, 200))
        {
            return 0;
        }

        delay_us(40);

        if (DHT_ReadPin() == 1)
        {
            data |= (1 << (7 - i));
        }

        if (!wait_for_pin(0, 200))
        {
            return 0;
        }
    }

    return data;
}
/* ----------------------------------------------------
 * Draw simple bar graph on LCD.
 * ---------------------------------------------------- */
static void draw_bar(uint8_t row,
                     uint8_t col,
                     uint8_t value,
                     uint8_t max_value,
                     uint8_t width)
{
    uint8_t filled;

    if (value > max_value)
    {
        value = max_value;
    }

    filled = (value * width) / max_value;

    lcd_put_cur(row, col);

    for (uint8_t i = 0; i < width; i++)
    {
        if (i < filled)
            lcd_send_string("#");
        else
            lcd_send_string("-");
    }
}


/* ----------------------------------------------------
 * DHT_Display()
 *
 * Reads DHT22 and displays:
 *   - Temperature
 *   - Humidity
 *   - Simple LCD bar graphs
 *
 * This avoids %f printing.
 * ---------------------------------------------------- */
void DHT_Display(void)
{
    char buffer[17];
    uint8_t checksum;
    uint8_t calculated;
    uint8_t Humidity;
	uint8_t temperature;

    lcd_clear();
    lcd_put_cur(0, 0);
    lcd_send_string("Reading DHT");

    DHT_Start();

    if (DHT_Check_Response())
    {
        /*
         * Read all 5 bytes immediately.
         * Do not put LCD prints or delays between these.
         */
        Rh_byte1   = DHT_Read();
        Rh_byte2   = DHT_Read();
        Temp_byte1 = DHT_Read();
        Temp_byte2 = DHT_Read();
        checksum   = DHT_Read();

        RH = ((uint16_t)Rh_byte1 << 8) | Rh_byte2;
        TEMP = ((uint16_t)Temp_byte1 << 8) | Temp_byte2;

        temperature = RH / 10;
        Humidity = TEMP / 10;

        calculated = (uint8_t)(Rh_byte1 + Rh_byte2 + Temp_byte1 + Temp_byte2);

        lcd_clear();

        lcd_put_cur(0, 0);
        snprintf(buffer,
                 sizeof(buffer),
                 "Humidity:%3d",
                 Humidity);
        lcd_send_string(buffer);

        lcd_put_cur(1, 0);
        snprintf(buffer,
                 sizeof(buffer),
                 "Temperature:%2d",
                 temperature);
        lcd_send_string(buffer);
    }
    else
    {
        lcd_clear();
        lcd_put_cur(0, 0);
        lcd_send_string("No Response");
    }

    delay_ms_simple(3000);
}
