/*
 * sa_pll_3ph_dsogi.h
 *
 *  Created on: Oct 30, 2022
 *      Author: Shwetank
 */

#ifndef INC_SA_PLL_3PH_DSOGI_H_
#define INC_SA_PLL_3PH_DSOGI_H_

#ifdef __cplusplus
extern "C" {
#endif


// includes the defines used in Shwetank Agrawal(SA) Library
#include "stm32f4xx.h"
#include "arm_math.h"

//!--- The Bilinear(Tustin) Discretization Method used  ---------------
//!    to convert from continuous to discrete domain

//! PLL 3PH DSOGI Structure
typedef struct{
	float32_t k;	//! SOGI gain
	float32_t w1;	//! SOGI bandpass frequency
	float32_t b0;	//! Bandpass Numerator Component
	float32_t b2; 	//! Bandpass Numerator Component
	float32_t a1; 	//! Bandpass and quadrature bandpass Denominator Component
	float32_t a2; 	//! Bandpass and quadrature bandpass Denominator Component
	float32_t q0; 	//! Quadrature bandpass Numerator Component
	float32_t q1; 	//! Quadrature bandpass Numerator Component
	float32_t q2; 	//! Quadrature bandpass Numerator Component

	float32_t uDash_alpha[3];
	float32_t quDash_alpha[3];
	float32_t uDash_beta[3];
	float32_t quDash_beta[3];
	float32_t u_alpha[3];
	float32_t u_beta[3];
	float32_t uDash_pos_alpha;
	float32_t uDash_pos_beta;
	float32_t u_z;
	float32_t u_d;
	float32_t u_q;

	float32_t sin_theta;
	float32_t cos_theta;

	float32_t LF_B1;	//! Loop Filter Coefficient
	float32_t LF_B0;	//! Loop Filter Coefficient
	float32_t v_q[2];	//! Q-axis value in Rotating Reference
	float32_t y_lf[2];	//! Loop filter output Data Buffer
	float32_t fo[2]; 	//! Output frequency of PLL
	float32_t fn; 		//! Nominal Frequency
	float32_t theta[2];	//! Phase Angle
	float32_t Ts;		//! Sampling time(Inverse of ISR Frequency) or Delta_T
}SA_PLL_3PH_DSOGI;


//! Used to reset the PLL 3PH DSOGI pointer
extern void SA_PLL_3PH_DSOGI_reset(SA_PLL_3PH_DSOGI *pll_obj);

//! Used to configure the PLL 3PH DSOGI pointer
extern void SA_PLL_3PH_DSOGI_config(SA_PLL_3PH_DSOGI *pll_obj, float32_t isrFreq, float32_t nominalFreq,
								float32_t lf_b1, float32_t lf_b0,
								float32_t k, float32_t w1, float32_t b0, float32_t b2,
								float32_t a1, float32_t a2, float32_t q0, float32_t q1, float32_t q2);

//! Used to run the PLL 3PH DSOGI driver
extern void SA_PLL_3PH_DSOGI_run(SA_PLL_3PH_DSOGI *pll_obj, float32_t v_a, float32_t v_b, float32_t v_c);


#ifdef __cplusplus
}
#endif


#endif /* INC_SA_PLL_3PH_DSOGI_H_ */
