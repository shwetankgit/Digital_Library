/*
 * sa_sensor_manage.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Shwetank
 */

#ifndef INC_SA_SENSOR_MANAGE_H_
#define INC_SA_SENSOR_MANAGE_H_

#ifdef __cplusplus
extern "C" {
#endif


// includes the defines used in Shwetank Agrawal(SA) Library
#include "stm32f4xx.h"
#include "arm_math.h"

//typedef enum {
//    acCurrent = 0,
//    acVoltage = 1,
//	dcCurrent  = 2,
//    dcVoltage =3,
//	temperature = 4,
//}SA_SENSOR_TYPE;
//
////! SENSOR Structure
//typedef  struct{
//	float32_t offset_pu;
//	float32_t pu;
//	float32_t intantaneous;
//	float32_t rms;
//	float32_t avg;
//	SA_SENSOR_TYPE sensor_type;
//
//}SA_SENSOR_MANAGE;
//
////! Used to reset the SENSOR pointer
//extern void SA_SENSOR_reset(SA_SENSOR_MANAGE *sensor);
//
////! Used to configure the SENSOR pointer
//extern void SA_SENSOR_config(SA_SENSOR_MANAGE *sensor, uint16_t adc_offset_pu, SA_SENSOR_TYPE sensorType);
//
////! Used to run the SENSOR drive
//extern void SA_SENSOR_READ_run(SA_SENSOR_MANAGE *sensor, float32_t adc_val);
//
//
//#ifdef __cplusplus
//extern }
//#endif


#endif /* INC_SA_SENSOR_MANAGE_H_ */
