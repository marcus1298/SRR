/*
 * vl53l1_sensor.c
 *
 *  Created on: 22 de jun de 2023
 *      Author: mateu
 */


#include "vl53l1_sensor.h"
#include "vl53l1_api.h"


extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

VL53L1_RangingMeasurementData_t data;

VL53L1_Dev_t                   devLeft;
VL53L1_Dev_t                   devRight;
VL53L1_DEV                     DevL = &devLeft;
VL53L1_DEV					   DevR = &devRight;


void ConfigAndStartSensor(){

	VL53L1_DetectionConfig_t DetectionConfig;
	uint8_t status;

	// Configurando o sensor da esquerda

	DevL->comms_speed_khz = 400;
	DevL->I2cHandle = &hi2c1;
	DevL->comms_type = 1;
	DevL->I2cDevAddr=0x52;

	// Configurando o sensor da direita
	DevR->comms_speed_khz = 400;
	DevR->I2cHandle = &hi2c2;
	DevR->comms_type = 1;
	DevR->I2cDevAddr=0x52;


	//Configurando o Threshold

	DetectionConfig.DetectionMode = 1;
	DetectionConfig.Distance.CrossMode = 0;
	DetectionConfig.Distance.Low = 1000;

	//Inicializa o sensor da esquerda

	VL53L1_WaitDeviceBooted(DevL);
	VL53L1_DataInit(DevL);
	VL53L1_StaticInit(DevL);
	VL53L1_SetDistanceMode(DevL, VL53L1_DISTANCEMODE_LONG);

	VL53L1_SetThresholdConfig(DevL, &DetectionConfig);

	VL53L1_StartMeasurement(DevL);


	//Inicializa o sensor da esquerda

	VL53L1_WaitDeviceBooted(DevR);
	VL53L1_DataInit(DevR);
	VL53L1_StaticInit(DevR);
	VL53L1_SetDistanceMode(DevR, VL53L1_DISTANCEMODE_LONG);

	VL53L1_SetThresholdConfig(DevR, &DetectionConfig);

	VL53L1_StartMeasurement(DevR);
}

void GetRangingMeasurementData_Sensor(uint16_t GPIO_Pin){

	if(GPIO_Pin == GPIO_LASER1_Pin){
		VL53L1_GetRangingMeasurementData(DevL, &data);
		VL53L1_ClearInterruptAndStartMeasurement(DevL);
	}
	else{
		VL53L1_GetRangingMeasurementData(DevR, &data);
		VL53L1_ClearInterruptAndStartMeasurement(DevR);
	}

}





