/*
 * app.c
 *
 *  Created on: 19 de jun de 2023
 *      Author: mateu
 */


#include "app.h"
#include <stdint.h>
#include "main.h"
#include "vl53l1_sensor.h"
#include "i2c-lcd.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if(GPIO_Pin == GPIO_LASER1_Pin){

	}
	else if(GPIO_Pin == GPIO_LASER2_Pin){

	}
	else{

	}
}


void app_init(void){

	//Ler o potenciometro e salvar o valor da distancia dos sensores



	//Definir o offset de leitura Thrshold

	//Inicializar os sensores
	lcd_init ();

	ConfigAndStartSensor();

}

void app_loop(void){

	//Mostrar Contagem e velocidade instantea

}
