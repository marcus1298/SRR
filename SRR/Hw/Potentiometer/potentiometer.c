/*
 * potentiometer.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Marcus e Mateus
 */

#include <stdint.h>
#include "potentiometer.h"
#include "main.h"


extern ADC_HandleTypeDef hadc1;

uint32_t GetDistanceSensor(){

	uint32_t readValue;
	uint32_t distancia;

	HAL_ADC_PollForConversion(&hadc1,1000);
	readValue = HAL_ADC_GetValue(&hadc1);

	distancia = (readValue*(500-10))/(4095+10);


	return distancia;
}
