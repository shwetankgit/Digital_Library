/*
 * sa_sensor_manage.c
 *
 *  Created on: Nov 1, 2022
 *      Author: Shwetank
 */

#include "sa_sensor_manage.h"
#include "userDefine.h"

//#ifndef SA_SENSOR_MANAGE_DEFINE
//#define SA_POWER_DC_DEFINE 1U
//#define ADC_PU_FACTOR  0U
//#define VAC_MAX_SENSE_VOLTS 0U
//#define IAC_MAX_SENSE_AMPS 0U
//#define VDC_MAX_SENSE_VOLTS 0U
//#define IDC_MAX_SENSE_AMPS 0U
//#define TEMP_MAX 0U
//#endif
//
//// Detail of the defined functions
//
////! Used to reset the SENSOR pointer
//void SA_SENSOR_reset(SA_SENSOR_MANAGE *sensor){
//	sensor->pu = 0.0f;
//	sensor->rms = 0.0f;
//	sensor->avg = 0.0f;
//	sensor->intantaneous = 0.0f;
//
//}
//
////! Used to configure the SENSOR pointer
//void SA_SENSOR_config(SA_SENSOR_MANAGE *sensor, uint16_t adc_offset_pu, SA_SENSOR_TYPE sensorType){
//	sensor->offset_pu = adc_offset_pu;
//	sensor->pu = 0.0f;
//	sensor->rms = 0.0f;
//	sensor->avg = 0.0f;
//	sensor->intantaneous = 0.0f;
//	sensor->sensor_type = sensorType;
//}
//
////! Used to run the SENSOR driver
//void SA_SENSOR_run(SA_SENSOR_MANAGE *sensor, float32_t adc_val){
//
//	//!- converting in between (-1 to +1)
//	sensor->pu = (adc_val*ADC_PU_FACTOR - sensor->offset_pu) * 2.0f;
//	switch(sensor->sensor_type){
//	case acCurrent:
//		sensor->intantaneous =  sensor->pu * IAC_MAX_SENSE_AMPS;
//		break;
//	case acVoltage:
//		sensor->intantaneous =  sensor->pu * VAC_MAX_SENSE_VOLTS;
//		break;
//	case dcCurrent:
//		sensor->intantaneous =  sensor->pu * IDC_MAX_SENSE_AMPS;
//		break;
//	case dcVoltage:
//		sensor->intantaneous =  sensor->pu * VDC_MAX_SENSE_VOLTS;
//		break;
//	case temperature:
//		sensor->intantaneous =  sensor->pu * TEMP_MAX;
//		break;
//	default:
//	   // Do Nothing
//		 ;
//	}
//}
