/*
 * sa_power_3ph.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Shwetank
 */


#include "sa_power_3ph.h"
#include "userDefine.h"

#ifndef SA_POWER_3PH_DEFINE
#define SA_POWER_3PH_DEFINE
#define VAC_MAX_SENSE_VOLTS 0U
#define IAC_MAX_SENSE_AMPS 0U
#endif

void SA_POWER_3PH_reset(SA_POWER_3PH *power_obj){
	power_obj->active_pwr_3ph[0] = 0.0f;
	power_obj->active_pwr_3ph[1] = 0.0f;

	power_obj->reactive_pwr_3ph[0] = 0.0f;
	power_obj->reactive_pwr_3ph[1] = 0.0f;

	power_obj->avg_active_pwr_3ph[0] = 0.0f;
	power_obj->avg_active_pwr_3ph[1] = 0.0f;

	power_obj->avg_reactive_pwr_3ph[0] = 0.0f;
	power_obj->avg_reactive_pwr_3ph[1] = 0.0f;

}

void SA_POWER_3PH_config(SA_POWER_3PH *power_obj, float32_t k1, float32_t k2){
	power_obj->lpf_k1 = k1;
	power_obj->lpf_k2 = k2;

	power_obj->active_pwr_3ph[0] = 0.0f;
	power_obj->active_pwr_3ph[1] = 0.0f;

	power_obj->reactive_pwr_3ph[0] = 0.0f;
	power_obj->reactive_pwr_3ph[1] = 0.0f;

	power_obj->avg_active_pwr_3ph[0] = 0.0f;
	power_obj->avg_active_pwr_3ph[1] = 0.0f;

	power_obj->avg_reactive_pwr_3ph[0] = 0.0f;
	power_obj->avg_reactive_pwr_3ph[1] = 0.0f;

}

void SA_POWER_3PH_run(SA_POWER_3PH *power_obj, float32_t v_d, float32_t v_q, float32_t i_d, float32_t i_q){

	//!- Calculating three phase Power
	power_obj->active_pwr_3ph[0] = (v_d * i_d + v_q * i_q)*(VAC_MAX_SENSE_VOLTS * IAC_MAX_SENSE_AMPS)*(3.0f/2.0f);
	power_obj->reactive_pwr_3ph[0] = (v_d * i_q - v_q * i_d)*(VAC_MAX_SENSE_VOLTS * IAC_MAX_SENSE_AMPS)*(3.0f/2.0f);

	//!- LPF using bilinear discretization method
	power_obj->avg_active_pwr_3ph[0] = (power_obj->lpf_k1 * power_obj->active_pwr_3ph[0])
									 + (power_obj->lpf_k1 * power_obj->active_pwr_3ph[1])
									 - (power_obj->lpf_k2 * power_obj->avg_active_pwr_3ph[1]);
	power_obj->avg_reactive_pwr_3ph[0] = (power_obj->lpf_k1 * power_obj->reactive_pwr_3ph[0])
									   + (power_obj->lpf_k1 * power_obj->reactive_pwr_3ph[1])
									   - (power_obj->lpf_k2 * power_obj->avg_reactive_pwr_3ph[1]);

	//!- Updating values
	power_obj->avg_active_pwr_3ph[1] = power_obj->avg_active_pwr_3ph[0];
	power_obj->active_pwr_3ph[1] = power_obj->active_pwr_3ph[0];
	power_obj->avg_reactive_pwr_3ph[1] = power_obj->avg_reactive_pwr_3ph[0];
	power_obj->reactive_pwr_3ph[1] = power_obj->reactive_pwr_3ph[0];

}
