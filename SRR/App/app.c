/*
 * app.c
 *
 *  Created on: 19 de jun de 2023
 *      Author: Marcus e Mateus
 */


#include "app.h"
#include <stdint.h>
#include "main.h"
#include "vl53l1_sensor.h"
#include "i2c-lcd.h"
#include "potentiometer.h"
#include <stdio.h>
#include <string.h>

extern ADC_HandleTypeDef hadc1;


uint32_t t1[10];                          //Buffer de tempo que foram guardados quando passaram pelo sensor 1
uint32_t t2[10];						  //Buffer de tempo que foram guardados quando passaram pelo sensor 2
volatile uint32_t i = 0 , j = 0;		  //Variaveis auxiliares dos buffers de tempo
uint32_t deltat = 1;					  //Variacao de tempo
uint32_t count = 0;						  //Contador de objetos passados
uint32_t typeMeasurement = 0; 			  //Seletor de unidade de medida
uint32_t sensorDistanceCm;			      //Distância entre os sensores
volatile uint32_t start = 0;
char contagem[20];
char velMed[20];
char sensorDistanciaPrint[20];
char MeasurementUnity[20] = "";


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{   //Interrupcao do laser 1
	if(GPIO_Pin == GPIO_LASER1_Pin){

		if(i < 10){
			t1[i] = HAL_GetTick();
		}
		else{
			i = 0;
			t1[i] = HAL_GetTick();
		}
		i++;

	}
	//Interrupcao do laser 2
	else if(GPIO_Pin == GPIO_LASER2_Pin){
		if(j < 10){
			t2[j] = HAL_GetTick();
		}
		else{
			j = 0;
			t2[j] = HAL_GetTick();
		}

		deltat = t2[j]- t1[j];
		j++;
		count ++;
	}
	//Interrupcao do botao para ajustar a unidade de medida
	else if(GPIO_Pin == SWITCH_INFO_BUTTON_Pin){
		if(start == 1){

			if(typeMeasurement == 0){						//Metros por segundos
				typeMeasurement = 1;
				strcpy(MeasurementUnity, "M/s");
			}
			else if (typeMeasurement == 1){					//Kilometros por hora
				typeMeasurement = 0;
				strcpy(MeasurementUnity, "Km/h");
			}
		}
		else{

			start = 1;
		}


	}
}

//Calcula velocidade de acordo com a unidade de medida selecionada pelo usuario no botao
uint32_t VelocityCalculation(){
	if(typeMeasurement == 0){

		return sensorDistanceCm/deltat*1000;
	}
	else{
        return (sensorDistanceCm/deltat*1000) * 3.6;
	}


}


void app_init(void){


	lcd_init ();

	HAL_ADC_Start(&hadc1);
	//Trava o programa enquanto o usuario não aperta o botao para confirmar a regulagem do potenciometro(Distancia entre sensores)
	while(start == 0){

		sensorDistanceCm = GetDistanceSensor();
		showSensorDistance(sensorDistanceCm);
	}
	ConfigAndStartSensor();

}

void app_loop(void){
	//Mostra a quantidade de objetos que passou pelo radar, a velocidade do último objeto e a unidade de medida
	showVelocityAndCount(count, VelocityCalculation(), MeasurementUnity);

}
