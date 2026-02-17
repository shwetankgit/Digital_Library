/*
 * sa_pll_3ph_srf.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Shwetank
 */

#ifndef INC_SA_PLL_3PH_SRF_H_
#define INC_SA_PLL_3PH_SRF_H_

#ifdef __cplusplus
extern "C" {
#endif


// includes the defines used in Shwetank Agrawal(SA) Library
#include "stm32f4xx.h"
#include "arm_math.h"

//!--- The Bilinear(Tustin) Discretization Method used  ---------------
//!    to convert from continuous to discrete domain

//! PLL 3PH SRF Structure
typedef struct{
	float32_t LF_B1;	//! Loop Filter Coefficient
	float32_t LF_B0;	//! Loop Filter Coefficient
	float32_t v_q[2];	//! Q-axis value in Rotating Reference
	float32_t y_lf[2];	//! Loop filter output Data Buffer
	float32_t fo[2]; 	//! Output frequency of PLL
	float32_t fn; 		//! Nominal Frequency
	float32_t theta[2];	//! Phase Angle
	float32_t Ts;		//! Sampling time(Inverse of ISR Frequency) or Delta_T
}SA_PLL_3PH_SRF;


//! Used to reset the PLL 3PH SRF pointer
extern void SA_PLL_3PH_SRF_reset(SA_PLL_3PH_SRF *pll_obj);

//! Used to configure the PLL 3PH SRF pointer
extern void SA_PLL_3PH_SRF_config(SA_PLL_3PH_SRF *pll_obj, float32_t isrFreq, float32_t nominalFreq,
								float32_t lf_b1, float32_t lf_b0);

//! Used to run the PLL 3PH SRF driver
extern void SA_PLL_3PH_SRF_run(SA_PLL_3PH_SRF *pll_obj, float32_t v_q);


#ifdef __cplusplus
}
#endif


#endif /* INC_SA_PLL_3PH_SRF_H_ */
