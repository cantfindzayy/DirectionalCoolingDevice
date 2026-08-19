/*
 * lcd.c
 *
 * 16x2 HD44780 LCD driver for STM32L476
 *
 * This file provides:
 *   - LCD_Init()
 *   - lcd_clear()
 *   - lcd_put_cur()
 *   - lcd_send_string()
 *
 * LCD mode:
 *   4-bit parallel mode
 *
 * IMPORTANT:
 * Change the pin definitions below to match your wiring.
 *
 * Example wiring used here:
 *   LCD RS -> PB0
 *   LCD EN -> PB1
 *   LCD D4 -> PB2
 *   LCD D5 -> PB3
 *   LCD D6 -> PB4
 *   LCD D7 -> PB5
 */

#include "stm32l476xx.h"
#include <stdint.h>

/* ----------------------------------------------------
 * LCD pin definitions
 *
 * Change these if your LCD is wired differently.
 * ---------------------------------------------------- */
#define LCD_PORT GPIOB

#define LCD_RS 0
#define LCD_EN 1
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 8
#define LCD_D7 7

/* ----------------------------------------------------
 * Small delay functions
 *
 * These are simple blocking delays.
 * They are good enough for LCD timing.
 * ---------------------------------------------------- */
static void LCD_Delay(volatile uint32_t delay)
{
    while (delay--);
}

static void LCD_Delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        LCD_Delay(4000);
    }
}

/* ----------------------------------------------------
 * LCD_GPIO_Init()
 *
 * Configures LCD pins as GPIO outputs.
 * ---------------------------------------------------- */
static void LCD_GPIO_Init(void)
{
    /* Enable GPIOA clock */
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

    /* Set RS, EN, D4, D5, D6, D7 as output */
    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_RS));
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_RS));

    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_EN));
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_EN));

    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_D4));
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_D4));

    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_D5));
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_D5));

    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_D6));
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_D6));

    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_D7));
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_D7));

    /* Push-pull output */
    LCD_PORT->OTYPER &= ~(1 << LCD_RS);
    LCD_PORT->OTYPER &= ~(1 << LCD_EN);
    LCD_PORT->OTYPER &= ~(1 << LCD_D4);
    LCD_PORT->OTYPER &= ~(1 << LCD_D5);
    LCD_PORT->OTYPER &= ~(1 << LCD_D6);
    LCD_PORT->OTYPER &= ~(1 << LCD_D7);

    /* No pull-up / pull-down */
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_RS));
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_EN));
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_D4));
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_D5));
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_D6));
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_D7));
}

/* ----------------------------------------------------
 * LCD_Write_Pin()
 *
 * Writes HIGH or LOW to one LCD pin.
 * ---------------------------------------------------- */
static void LCD_Write_Pin(uint8_t pin, uint8_t value)
{
    if (value)
    {
        LCD_PORT->ODR |= (1 << pin);
    }
    else
    {
        LCD_PORT->ODR &= ~(1 << pin);
    }
}

/* ----------------------------------------------------
 * LCD_Enable_Pulse()
 *
 * Sends enable pulse to LCD.
 * LCD reads data on EN transition.
 * ---------------------------------------------------- */
static void LCD_Enable_Pulse(void)
{
    LCD_Write_Pin(LCD_EN, 1);
    LCD_Delay(100);
    LCD_Write_Pin(LCD_EN, 0);
    LCD_Delay(100);
}

/* ----------------------------------------------------
 * LCD_Send_4Bits()
 *
 * Sends 4 bits to LCD data pins D4-D7.
 * ---------------------------------------------------- */
static void LCD_Send_4Bits(uint8_t data)
{
    LCD_Write_Pin(LCD_D4, (data >> 0) & 0x01);
    LCD_Write_Pin(LCD_D5, (data >> 1) & 0x01);
    LCD_Write_Pin(LCD_D6, (data >> 2) & 0x01);
    LCD_Write_Pin(LCD_D7, (data >> 3) & 0x01);

    LCD_Enable_Pulse();
}

/* ----------------------------------------------------
 * LCD_Send_Command()
 *
 * Sends command byte to LCD.
 * RS = 0 means command mode.
 * ---------------------------------------------------- */
static void LCD_Send_Command(uint8_t cmd)
{
    LCD_Write_Pin(LCD_RS, 0);

    LCD_Send_4Bits(cmd >> 4);
    LCD_Send_4Bits(cmd & 0x0F);

    LCD_Delay_ms(2);
}

/* ----------------------------------------------------
 * LCD_Send_Data()
 *
 * Sends character data to LCD.
 * RS = 1 means data mode.
 * ---------------------------------------------------- */
static void LCD_Send_Data(uint8_t data)
{
    LCD_Write_Pin(LCD_RS, 1);

    LCD_Send_4Bits(data >> 4);
    LCD_Send_4Bits(data & 0x0F);

    LCD_Delay_ms(1);
}

/* ----------------------------------------------------
 * LCD_Init()
 *
 * Initializes LCD in 4-bit mode.
 * ---------------------------------------------------- */
void LCD_Init(void)
{
    LCD_GPIO_Init();

    LCD_Delay_ms(50);

    LCD_Write_Pin(LCD_RS, 0);
    LCD_Write_Pin(LCD_EN, 0);

    /* 4-bit initialization sequence */
    LCD_Send_4Bits(0x03);
    LCD_Delay_ms(5);

    LCD_Send_4Bits(0x03);
    LCD_Delay_ms(5);

    LCD_Send_4Bits(0x03);
    LCD_Delay_ms(1);

    LCD_Send_4Bits(0x02);
    LCD_Delay_ms(1);

    /* 4-bit mode, 2 lines, 5x8 font */
    LCD_Send_Command(0x28);

    /* Display ON, cursor OFF */
    LCD_Send_Command(0x0C);

    /* Entry mode: cursor moves right */
    LCD_Send_Command(0x06);

    /* Clear display */
    LCD_Send_Command(0x01);
    LCD_Delay_ms(2);
}

/* ----------------------------------------------------
 * lcd_clear()
 *
 * Clears LCD screen.
 * ---------------------------------------------------- */
void lcd_clear(void)
{
    LCD_Send_Command(0x01);
    LCD_Delay_ms(2);
}

/* ----------------------------------------------------
 * lcd_put_cur()
 *
 * Moves cursor to row and column.
 *
 * For 16x2 LCD:
 *   row 0 = first line
 *   row 1 = second line
 * ---------------------------------------------------- */
void lcd_put_cur(uint8_t row, uint8_t col)
{
    uint8_t address;

    if (row == 0)
    {
        address = 0x80 + col;
    }
    else
    {
        address = 0xC0 + col;
    }

    LCD_Send_Command(address);
}

/* ----------------------------------------------------
 * lcd_send_string()
 *
 * Sends string to LCD.
 * ---------------------------------------------------- */
void lcd_send_string(char *str)
{
    while (*str)
    {
        LCD_Send_Data((uint8_t)(*str));
        str++;
    }
}
