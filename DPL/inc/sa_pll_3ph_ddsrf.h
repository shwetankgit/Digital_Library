/*
 * sa_pll_3ph_ddsrf.h
 *
 *  Created on: Oct 1, 2022
 *      Author: Shwetank
 */

#ifndef INC_SA_PLL_3PH_DDSRF_H_
#define INC_SA_PLL_3PH_DDSRF_H_

#ifdef __cplusplus
extern "C" {
#endif


// includes the defines used in Shwetank Agrawal(SA) Library
#include "stm32f4xx.h"
#include "arm_math.h"

//!--- The Bilinear(Tustin) Discretization Method used  ---------------
//!    to convert from continuous to discrete domain

//! PLL 3PH DDSRF Structure
typedef struct{
	float32_t LF_B1;		//! Loop Filter Coefficient
	float32_t LF_B0;		//! Loop Filter Coefficient
	float32_t LPF_K1;		//! LPF filter Coefficient
	float32_t LPF_K2;		//! LPF filter Coefficient

	float32_t d_p_decouple;	//! Positive D-axis decouple value
	float32_t d_n_decouple;	//! Negative D-axis decouple value
	float32_t q_p_decouple;	//! Positive Q-axis decouple value
	float32_t q_n_decouple;	//! Negative Q-axis decouple value

	float32_t cos_2theta;	//! Cos of twice grid freq. angle
	float32_t sin_2theta;	//! Sin of twice grid freq. angle

	float32_t y_d_p_lpf[2];		//! Stores LPF output Positive Decoupled D axis components
	float32_t y_q_p_lpf[2];		//! Stores LPF output Positive Decoupled Q axis components
	float32_t y_d_n_lpf[2];		//! Stores LPF output Negative Decoupled D axis components
	float32_t y_q_n_lpf[2];		//! Stores LPF output Negative Decoupled Q axis components
	float32_t x_d_p_lpf[2];		//! Stores LPF input Positive Decoupled D axis components
	float32_t x_q_p_lpf[2];		//! Stores LPF input Positive Decoupled Q axis components
	float32_t x_d_n_lpf[2];		//! Stores LPF input Negative Decoupled D axis components
	float32_t x_q_n_lpf[2];		//! Stores LPF input Negative Decoupled Q axis components

	float32_t v_q[2]; 		//! Q-axis value in Rotating Reference
	float32_t y_lf[2];		//! Loop filter output Data Buffer
	float32_t fo[2]; 		//! Output frequency of PLL
	float32_t fn; 		//! Nominal Frequency
	float32_t theta[2];	//! Phase Angle
	float32_t Ts;		//! Sampling time(Inverse of ISR Frequency) or Delta_T
}SA_PLL_3PH_DDSRF;


//! Used to reset the PLL 3PH DDSRF pointer
extern void SA_PLL_3PH_DDSRF_reset(SA_PLL_3PH_DDSRF *pll_obj);

//! Used to configure the PLL 3PH DDSRF pointer
extern void SA_PLL_3PH_DDSRF_config(SA_PLL_3PH_DDSRF *pll_obj, float32_t isrFreq, float32_t nominalFreq,
								float32_t lf_b1, float32_t lf_b0, float32_t lpf_k1, float32_t lpf_k2);

//! Used to run the PLL 3PH DDSRF driver
extern void SA_PLL_3PH_DDSRF_run(SA_PLL_3PH_DDSRF *pll_obj, float32_t d_p, float32_t d_n,
								float32_t q_p, float32_t q_n);


#endif /* INC_SA_PLL_3PH_DDSRF_H_ */
