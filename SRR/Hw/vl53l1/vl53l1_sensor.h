/*
 * vl53l1_sensor.h
 *
 *  Created on: 22 de jun de 2023
 *      Author: mateu
 */

#ifndef VL53L1_VL53L1_SENSOR_H_
#define VL53L1_VL53L1_SENSOR_H_
#include <stdint.h>

void ConfigAndStartSensor(void);

void GetRangingMeasurementData_Sensor(uint16_t GPIO_Pin);

#endif /* VL53L1_VL53L1_SENSOR_H_ */
