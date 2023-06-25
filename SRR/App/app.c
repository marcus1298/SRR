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


uint32_t v1[10];
uint32_t v2[10];
volatile uint32_t i = 0 , j = 0;
uint32_t deltat = 0;
uint32_t count = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	uint32_t deltat;
	if(GPIO_Pin == GPIO_LASER1_Pin){

		if(i < 10){
			v1[i] = HAL_GetTick();
		}
		else{
			i = 0;
			v1[i] = HAL_GetTick();
		}
		i++;

	}
	else if(GPIO_Pin == GPIO_LASER2_Pin){
		if(j < 10){
			v2[j] = HAL_GetTick();
				}
		else{
			j = 0;
			v2[j] = HAL_GetTick();
		}

		deltat = v2[j]- v1[j];
		j++;
		count ++;
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
