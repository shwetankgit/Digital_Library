/*
 * sa_power_3ph.h
 *
 *  Created on: Nov 3, 2022
 *      Author: Shwetank
 */

#ifndef INC_SA_POWER_3PH_H_
#define INC_SA_POWER_3PH_H_

#ifdef __cplusplus
extern "C" {
#endif

// includes the defines used in Shwetank Agrawal(SA) Library
#include "stm32f4xx.h"
#include "arm_math.h"

//!--- The Bilinear(Tustin) Discretization Method used  ---------------
//!    to convert from continuous to discrete domain

typedef struct{
	float32_t lpf_k1;
	float32_t lpf_k2;
	float32_t active_pwr_3ph[2];
	float32_t reactive_pwr_3ph[2];
	float32_t avg_active_pwr_3ph[2];
	float32_t avg_reactive_pwr_3ph[2];
}SA_POWER_3PH;

extern void SA_POWER_3PH_reset(SA_POWER_3PH *power_obj);

extern void SA_POWER_3PH_config(SA_POWER_3PH *power_obj, float32_t k1, float32_t k2);

extern void SA_POWER_3PH_run(SA_POWER_3PH *power_obj, float32_t v_d, float32_t v_q, float32_t i_d, float32_t i_q);


#ifdef __cplusplus
 }
#endif


#endif /* INC_SA_POWER_3PH_H_ */
