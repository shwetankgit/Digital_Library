/*
 * s_pll_3ph_srf.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Shwetank
 */


#include "sa_pll_3ph_srf.h"

// Detail of the defined functions

//! Used to reset the PLL 3PH SRF pointer
void SA_PLL_3PH_SRF_reset(SA_PLL_3PH_SRF *pll_obj){
	pll_obj->fo[0] = 0.0f;
	pll_obj->fo[1] = 0.0f;

	pll_obj->theta[0] = 0.0f;
	pll_obj->theta[1] = 0.0f;

	pll_obj->v_q[0] = 0.0f;
	pll_obj->v_q[1] = 0.0f;

	pll_obj->y_lf[0] = 0.0f;
	pll_obj->y_lf[1] = 0.0f;
}

//! Used to configure the PLL 3PH SRF pointer
void SA_PLL_3PH_SRF_config(SA_PLL_3PH_SRF *pll_obj, float32_t isrFreq, float32_t nominalFreq,
							float32_t lf_b1, float32_t lf_b0){
	pll_obj->LF_B0 = lf_b0;
	pll_obj->LF_B1 = lf_b1;
	pll_obj->Ts = ((float32_t)1.0)/isrFreq;
	pll_obj->fn = nominalFreq;

	pll_obj->fo[0] = 0.0f;
	pll_obj->fo[1] = 0.0f;

	pll_obj->theta[0] = 0.0f;
	pll_obj->theta[1] = 0.0f;

	pll_obj->v_q[0] = 0.0f;
	pll_obj->v_q[1] = 0.0f;

	pll_obj->y_lf[0] = 0.0f;
	pll_obj->y_lf[1] = 0.0f;
}

//! Used to run the PLL 3PH SRF driver
void SA_PLL_3PH_SRF_run(SA_PLL_3PH_SRF *pll_obj, float32_t v_q){

	//Update new value of v-q
	pll_obj->v_q[0] = v_q;

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
}
