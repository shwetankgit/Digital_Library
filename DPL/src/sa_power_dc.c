/*
 * sa_power_dc.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Shwetank
 */


#include "sa_power_dc.h"
#include "userDefine.h"
// Detail of the defined functions
#ifndef SA_POWER_DC_DEFINE
#define SA_POWER_DC_DEFINE 1U
#define VDC_MAX_SENSE_VOLTS 0U
#define IDC_MAX_SENSE_AMPS 0U
#endif


void SA_POWER_DC_reset(SA_POWER_DC *power_obj){
	power_obj->active_pwr_dc[0] = 0.0f;
	power_obj->active_pwr_dc[1] = 0.0f;

	power_obj->avg_active_pwr_dc[0] = 0.0f;
	power_obj->avg_active_pwr_dc[1] = 0.0f;

}

void SA_POWER_DC_config(SA_POWER_DC *power_obj, float32_t k1, float32_t k2){
	power_obj->lpf_k1 = k1;
	power_obj->lpf_k2 = k2;

	power_obj->active_pwr_dc[0] = 0.0f;
	power_obj->active_pwr_dc[1] = 0.0f;

	power_obj->avg_active_pwr_dc[0] = 0.0f;
	power_obj->avg_active_pwr_dc[1] = 0.0f;

}

void SA_POWER_DC_run(SA_POWER_DC *power_obj, float32_t v_dc, float32_t i_dc){

	//!- Calculating three phase Power
	power_obj->active_pwr_dc[0] = (v_dc * i_dc)*(VDC_MAX_SENSE_VOLTS * IDC_MAX_SENSE_AMPS);

	//!- LPF using bilinear discretization method
	power_obj->avg_active_pwr_dc[0] = (power_obj->lpf_k1 * power_obj->active_pwr_dc[0])
									 + (power_obj->lpf_k1 * power_obj->active_pwr_dc[1])
									 - (power_obj->lpf_k2 * power_obj->avg_active_pwr_dc[1]);

	//!- Updating values
	power_obj->avg_active_pwr_dc[1] = power_obj->avg_active_pwr_dc[0];
	power_obj->active_pwr_dc[1] = power_obj->active_pwr_dc[0];

}
