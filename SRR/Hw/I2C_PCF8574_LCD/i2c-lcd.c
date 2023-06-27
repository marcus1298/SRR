/*
 * i2c-lcd.c
 *
 *  Created on: Jun 23, 2023
 *      Author: Author: Marcus e Mateus
 */



/** Put this in the src folder **/

#include "i2c-lcd.h"
#include <string.h>
#include <stdio.h>

extern I2C_HandleTypeDef hi2c3;  // change your handler here accordingly

#define SLAVE_ADDRESS_LCD 0x4E // change this according to ur setup

void lcd_send_cmd (char cmd)
{
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c3, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c3, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_clear (void)
{
	lcd_send_cmd (0x80);
	for (int i=0; i<70; i++)
	{
		lcd_send_data (' ');
	}
}

void lcd_put_cur(int row, int col)
{
    switch (row)
    {
        case 0:
            col |= 0x80;
            break;
        case 1:
            col |= 0xC0;
            break;
    }

    lcd_send_cmd (col);
}


void lcd_init (void)
{
	// 4 bit initialisation
	HAL_Delay(50);  // wait for >40ms
	lcd_send_cmd (0x30);
	HAL_Delay(5);  // wait for >4.1ms
	lcd_send_cmd (0x30);
	HAL_Delay(1);  // wait for >100us
	lcd_send_cmd (0x30);
	HAL_Delay(10);
	lcd_send_cmd (0x20);  // 4bit mode
	HAL_Delay(10);

  // dislay initialisation
	lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	HAL_Delay(1);
	lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	HAL_Delay(1);
	lcd_send_cmd (0x01);  // clear display
	HAL_Delay(1);
	HAL_Delay(1);
	lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	HAL_Delay(1);
	lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
}

void lcd_send_string (char *str)
{
	while (*str) lcd_send_data (*str++);
}


void showSensorDistance(uint32_t sensorDistanciaEmCm){
	char sensorDistanciaPrint[20];

	lcd_clear();
	lcd_put_cur(0, 0);
	lcd_send_string ("D Sensores: ");
	lcd_put_cur(0, 13);
	sprintf(sensorDistanciaPrint, "%lu", (unsigned long)sensorDistanciaEmCm);
	lcd_send_string(sensorDistanciaPrint);
}

void showVelocityAndCount(uint32_t count, uint32_t velocity, char MeasurementUnity[20]){

	char contagem[20];
	char velMed[20];

	lcd_clear();
	lcd_put_cur(0, 0);
	lcd_send_string ("Count: ");
	lcd_put_cur(0, 8);
	sprintf(contagem, "%lu", (unsigned long)count);
	lcd_send_string (contagem);
	lcd_put_cur(1, 0);
	lcd_send_string ("Vel Med: ");
	lcd_put_cur(1, 10);
	sprintf(velMed, "%lu", (unsigned long)velocity);
	lcd_send_string (velMed);
	lcd_put_cur(1, 13);
	lcd_send_string (MeasurementUnity);

}

