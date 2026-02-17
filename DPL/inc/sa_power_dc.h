/*
 * sa_power_dc.h
 *
 *  Created on: Nov 3, 2022
 *      Author: Shwetank
 */

#ifndef INC_SA_POWER_DC_H_
#define INC_SA_POWER_DC_H_

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
	float32_t active_pwr_dc[2];
	float32_t avg_active_pwr_dc[2];
}SA_POWER_DC;

extern void SA_POWER_DC_reset(SA_POWER_DC *power_obj);

extern void SA_POWER_DC_config(SA_POWER_DC *power_obj, float32_t k1, float32_t k2);

extern void SA_POWER_DC_run(SA_POWER_DC *power_obj, float32_t v_dc, float32_t i_dc);



#ifdef __cplusplus
}
#endif


#endif /* INC_SA_POWER_DC_H_ */
