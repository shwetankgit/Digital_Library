/*
 * sa_pll_3ph_ddsrf.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Shwetank
 */

#include "sa_pll_3ph_ddsrf.h"

// Detail of the defined functions

//! Used to reset the PLL 3PH DDSRF pointer
void SA_PLL_3PH_DDSRF_reset(SA_PLL_3PH_DDSRF *pll_obj){
	pll_obj->d_p_decouple = 0.0f;
	pll_obj->d_n_decouple = 0.0f;
	pll_obj->q_p_decouple = 0.0f;
	pll_obj->q_n_decouple = 0.0f;

	pll_obj->y_d_p_lpf[0] = 0.0f;
	pll_obj->y_d_p_lpf[1] = 0.0f;
	pll_obj->y_q_p_lpf[0] = 0.0f;
	pll_obj->y_q_p_lpf[1] = 0.0f;
	pll_obj->y_d_n_lpf[0] = 0.0f;
	pll_obj->y_d_n_lpf[1] = 0.0f;
	pll_obj->y_q_n_lpf[0] = 0.0f;
	pll_obj->y_q_n_lpf[1] = 0.0f;

	pll_obj->x_d_p_lpf[0] = 0.0f;
	pll_obj->x_d_p_lpf[1] = 0.0f;
	pll_obj->x_q_p_lpf[0] = 0.0f;
	pll_obj->y_q_p_lpf[1] = 0.0f;
	pll_obj->x_d_n_lpf[0] = 0.0f;
	pll_obj->x_d_n_lpf[1] = 0.0f;
	pll_obj->x_q_n_lpf[0] = 0.0f;
	pll_obj->x_q_n_lpf[1] = 0.0f;

	pll_obj->fo[0] = 0.0f;
	pll_obj->fo[1] = 0.0f;

	pll_obj->theta[0] = 0.0f;
	pll_obj->theta[1] = 0.0f;

	pll_obj->v_q[0] = 0.0f;
	pll_obj->v_q[1] = 0.0f;

	pll_obj->y_lf[0] = 0.0f;
	pll_obj->y_lf[1] = 0.0f;

}

//! Used to configure the PLL 3PH DDSRF pointer
void SA_PLL_3PH_DDSRF_config(SA_PLL_3PH_DDSRF *pll_obj, float32_t isrFreq, float32_t nominalFreq,
								float32_t lf_b1, float32_t lf_b0, float32_t lpf_k1, float32_t lpf_k2 ){

	pll_obj->LF_B0 = lf_b0;
	pll_obj->LF_B1 = lf_b1;
	pll_obj->LPF_K1 = lpf_k1;
	pll_obj->LPF_K2 = lpf_k2;
	pll_obj->Ts = ((float32_t)1.0)/isrFreq;
	pll_obj->fn = nominalFreq;

	pll_obj->d_p_decouple = 0.0f;
	pll_obj->d_n_decouple = 0.0f;
	pll_obj->q_p_decouple = 0.0f;
	pll_obj->q_n_decouple = 0.0f;

	pll_obj->y_d_p_lpf[0] = 0.0f;
	pll_obj->y_d_p_lpf[1] = 0.0f;
	pll_obj->y_q_p_lpf[0] = 0.0f;
	pll_obj->y_q_p_lpf[1] = 0.0f;
	pll_obj->y_d_n_lpf[0] = 0.0f;
	pll_obj->y_d_n_lpf[1] = 0.0f;
	pll_obj->y_q_n_lpf[0] = 0.0f;
	pll_obj->y_q_n_lpf[1] = 0.0f;

	pll_obj->x_d_p_lpf[0] = 0.0f;
	pll_obj->x_d_p_lpf[1] = 0.0f;
	pll_obj->x_q_p_lpf[0] = 0.0f;
	pll_obj->y_q_p_lpf[1] = 0.0f;
	pll_obj->x_d_n_lpf[0] = 0.0f;
	pll_obj->x_d_n_lpf[1] = 0.0f;
	pll_obj->x_q_n_lpf[0] = 0.0f;
	pll_obj->x_q_n_lpf[1] = 0.0f;

	pll_obj->fo[0] = 0.0f;
	pll_obj->fo[1] = 0.0f;

	pll_obj->theta[0] = 0.0f;
	pll_obj->theta[1] = 0.0f;

	pll_obj->v_q[0] = 0.0f;
	pll_obj->v_q[1] = 0.0f;

	pll_obj->y_lf[0] = 0.0f;
	pll_obj->y_lf[1] = 0.0f;
}

//! Used to run the PLL 3PH DDSRF driver
void SA_PLL_3PH_DDSRF_run(SA_PLL_3PH_DDSRF *pll_obj, float32_t d_p, float32_t d_n,
										float32_t q_p, float32_t q_n){

	// Decoupling Network
	pll_obj->d_p_decouple = d_p
							- (pll_obj->y_d_n_lpf[0] * pll_obj->cos_2theta)
							- (pll_obj->y_q_n_lpf[0] * pll_obj->sin_2theta);
	pll_obj->q_p_decouple = q_p
							+ (pll_obj->y_d_n_lpf[0] * pll_obj->sin_2theta)
							- (pll_obj->y_q_n_lpf[0] * pll_obj->cos_2theta);
	pll_obj->d_n_decouple = d_n
							- (pll_obj->y_d_p_lpf[0] * pll_obj->cos_2theta)
							+ (pll_obj->y_q_p_lpf[0] * pll_obj->sin_2theta);
	pll_obj->q_n_decouple = q_n
							- (pll_obj->y_d_p_lpf[0] * pll_obj->sin_2theta)
							- (pll_obj->y_q_p_lpf[0] * pll_obj->cos_2theta);

	// Low Pass Filter
	pll_obj->x_d_p_lpf[0] = pll_obj->d_p_decouple;
	pll_obj->x_q_p_lpf[0] = pll_obj->q_p_decouple;
	pll_obj->x_d_n_lpf[0] = pll_obj->d_n_decouple;
	pll_obj->x_q_n_lpf[0] = pll_obj->q_n_decouple;

	pll_obj->y_d_p_lpf[0] = (pll_obj->x_d_p_lpf[0] * pll_obj->LPF_K1)
						  + (pll_obj->x_d_p_lpf[1] * pll_obj->LPF_K1)
						  - (pll_obj->y_d_p_lpf[1] * pll_obj->LPF_K2);
	pll_obj->y_q_p_lpf[0] = (pll_obj->x_q_p_lpf[0] * pll_obj->LPF_K1)
						  + (pll_obj->x_q_p_lpf[1] * pll_obj->LPF_K1)
						  - (pll_obj->y_q_p_lpf[1] * pll_obj->LPF_K2);
	pll_obj->y_d_n_lpf[0] = (pll_obj->x_d_n_lpf[0] * pll_obj->LPF_K1)
						  + (pll_obj->x_d_n_lpf[1] * pll_obj->LPF_K1)
						  - (pll_obj->y_d_n_lpf[1] * pll_obj->LPF_K2);
	pll_obj->y_q_n_lpf[0] = (pll_obj->x_q_n_lpf[0] * pll_obj->LPF_K1)
						  + (pll_obj->x_q_n_lpf[1] * pll_obj->LPF_K1)
						  - (pll_obj->y_q_n_lpf[1] * pll_obj->LPF_K2);

	pll_obj->x_d_p_lpf[1] = pll_obj->x_d_p_lpf[0];
	pll_obj->x_q_p_lpf[1] = pll_obj->x_q_p_lpf[0];
	pll_obj->x_d_n_lpf[1] = pll_obj->x_d_n_lpf[0];
	pll_obj->x_q_n_lpf[1] = pll_obj->x_q_n_lpf[0];

	pll_obj->y_d_p_lpf[1] = pll_obj->y_d_p_lpf[0];
	pll_obj->y_q_p_lpf[1] = pll_obj->y_q_p_lpf[0];
	pll_obj->y_d_n_lpf[1] = pll_obj->y_d_n_lpf[0];
	pll_obj->y_q_n_lpf[1] = pll_obj->y_q_n_lpf[0];

	//Update new value of v-q
	pll_obj->v_q[0] = pll_obj->q_p_decouple;

	// Loop Filter
	pll_obj->y_lf[0] = pll_obj->y_lf[1]
					 + (pll_obj->LF_B0 * pll_obj->v_q[0])
					 + (pll_obj->LF_B1 * pll_obj->v_q[1]);
	pll_obj->y_lf[1] = pll_obj->y_lf[0];
	pll_obj->v_q[1] = pll_obj->v_q[0];

	// Saturation of Loop Filter output
	pll_obj->y_lf[0] = (pll_obj->y_lf[0] > (float32_t)(200.0))?
						(float32_t)(200.0): pll_obj->y_lf[0];

	// VCO
	pll_obj->fo[0] = pll_obj->fn + pll_obj->y_lf[0];

	pll_obj->theta[0] = pll_obj->theta[1] +
						(pll_obj->Ts * PI)*(pll_obj->fo[0] + pll_obj->fo[1]);

	// Saturation of theta
	if(pll_obj->theta[0] > (float32_t)(2.0 * PI)){
		pll_obj->theta[0] = pll_obj->theta[0] - (float32_t)(2.0 * PI);
	}

	pll_obj->theta[1] = pll_obj->theta[0];
	pll_obj->fo[1] = pll_obj->fo[0];

	pll_obj->sin_2theta = sinf(pll_obj->theta[1] * 2.0f);
	pll_obj->cos_2theta = cosf(pll_obj->theta[1] * 2.0f);


}
