/*
 * i2c-lcd.h
 *
 *  Created on: Jun 23, 2023
 *      Author: mateu
 */

#ifndef I2C_PCF8574_LCD_I2C_LCD_H_
#define I2C_PCF8574_LCD_I2C_LCD_H_

#include "main.h"

void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_put_cur(int row, int col);  // put cursor at the entered position row (0 or 1), col (0-15);

void lcd_clear (void);

#endif /* I2C_PCF8574_LCD_I2C_LCD_H_ */

