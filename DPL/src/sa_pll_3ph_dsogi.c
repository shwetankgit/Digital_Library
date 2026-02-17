/*
 * sa_pll_3ph_dsogi.c
 *
 *  Created on: Oct 30, 2022
 *      Author: Shwetank
 */

#include "sa_pll_3ph_dsogi.h"

// Detail of the defined functions

//! Used to reset the PLL 3PH DSOGI pointer
void SA_PLL_3PH_DSOGI_reset(SA_PLL_3PH_DSOGI *pll_obj){
	pll_obj->uDash_alpha[0] = 0.0f;
	pll_obj->uDash_alpha[1] = 0.0f;
	pll_obj->uDash_alpha[2] = 0.0f;
	pll_obj->uDash_beta[0] = 0.0f;
	pll_obj->uDash_beta[1] = 0.0f;
	pll_obj->uDash_beta[2] = 0.0f;

	pll_obj->quDash_alpha[0] = 0.0f;
	pll_obj->quDash_alpha[1] = 0.0f;
	pll_obj->quDash_alpha[2] = 0.0f;
	pll_obj->quDash_beta[0] = 0.0f;
	pll_obj->quDash_beta[1] = 0.0f;
	pll_obj->quDash_beta[2] = 0.0f;

	pll_obj->u_alpha[0] = 0.0f;
	pll_obj->u_alpha[1] = 0.0f;
	pll_obj->u_alpha[2] = 0.0f;
	pll_obj->u_beta[0] = 0.0f;
	pll_obj->u_beta[1] = 0.0f;
	pll_obj->u_beta[2] = 0.0f;

	pll_obj->uDash_pos_alpha = 0.0f;
	pll_obj->uDash_pos_beta = 0.0f;

	pll_obj->u_z = 0.0f;

	pll_obj->sin_theta = 0.0f;
	pll_obj->cos_theta = 0.0f;

	pll_obj->fo[0] = 0.0f;
	pll_obj->fo[1] = 0.0f;

	pll_obj->theta[0] = 0.0f;
	pll_obj->theta[1] = 0.0f;

	pll_obj->v_q[0] = 0.0f;
	pll_obj->v_q[1] = 0.0f;

	pll_obj->y_lf[0] = 0.0f;
	pll_obj->y_lf[1] = 0.0f;

}

//! Used to configure the PLL 3PH DSOGI pointer
void SA_PLL_3PH_DSOGI_config(SA_PLL_3PH_DSOGI *pll_obj, float32_t isrFreq, float32_t nominalFreq,
								float32_t lf_b1, float32_t lf_b0,
								float32_t k, float32_t w1, float32_t b0, float32_t b2,
								float32_t a1, float32_t a2, float32_t q0, float32_t q1, float32_t q2){

	pll_obj->LF_B0 = lf_b0;
	pll_obj->LF_B1 = lf_b1;
	pll_obj->Ts = ((float32_t)1.0)/isrFreq;
	pll_obj->fn = nominalFreq;
	pll_obj->k = k;
	pll_obj->w1 = w1;
	pll_obj->b0 = b0;
	pll_obj->b2 = b2;
	pll_obj->a1 = a1;
	pll_obj->a2 = a2;
	pll_obj->q0 = q0;
	pll_obj->q1 = q1;
	pll_obj->q2 = q2;

	pll_obj->uDash_alpha[0] = 0.0f;
	pll_obj->uDash_alpha[1] = 0.0f;
	pll_obj->uDash_alpha[2] = 0.0f;
	pll_obj->uDash_beta[0] = 0.0f;
	pll_obj->uDash_beta[1] = 0.0f;
	pll_obj->uDash_beta[2] = 0.0f;

	pll_obj->quDash_alpha[0] = 0.0f;
	pll_obj->quDash_alpha[1] = 0.0f;
	pll_obj->quDash_alpha[2] = 0.0f;
	pll_obj->quDash_beta[0] = 0.0f;
	pll_obj->quDash_beta[1] = 0.0f;
	pll_obj->quDash_beta[2] = 0.0f;

	pll_obj->u_alpha[0] = 0.0f;
	pll_obj->u_alpha[1] = 0.0f;
	pll_obj->u_alpha[2] = 0.0f;
	pll_obj->u_beta[0] = 0.0f;
	pll_obj->u_beta[1] = 0.0f;
	pll_obj->u_beta[2] = 0.0f;

	pll_obj->uDash_pos_alpha = 0.0f;
	pll_obj->uDash_pos_beta = 0.0f;

	pll_obj->u_z = 0.0f;

	pll_obj->sin_theta = 0.0f;
	pll_obj->cos_theta = 0.0f;

	pll_obj->fo[0] = 0.0f;
	pll_obj->fo[1] = 0.0f;

	pll_obj->theta[0] = 0.0f;
	pll_obj->theta[1] = 0.0f;

	pll_obj->v_q[0] = 0.0f;
	pll_obj->v_q[1] = 0.0f;

	pll_obj->y_lf[0] = 0.0f;
	pll_obj->y_lf[1] = 0.0f;


}

//! Used to run the PLL 3PH DSOGI driver
void SA_PLL_3PH_DSOGI_run(SA_PLL_3PH_DSOGI *pll_obj, float32_t v_a, float32_t v_b, float32_t v_c){

	//!- ABC to alpha-beta transform
	pll_obj->u_alpha[0] = (0.66666666677f) * (v_a - 0.5f * (v_b + v_c));
	pll_obj->u_beta[0]  = (0.57735026913f) * (v_b - v_c);
	pll_obj->u_z = (0.57735026913f) * (v_a + v_b + v_c);

	//!- Bandpass output
	pll_obj->uDash_alpha[0] = (pll_obj->b0 * pll_obj->u_alpha[0])
							+ (pll_obj->b2 * pll_obj->u_alpha[2])
							+ (pll_obj->a1 * pll_obj->uDash_alpha[1])
							+ (pll_obj->a2 * pll_obj->uDash_alpha[2]);
	pll_obj->uDash_beta[0] = (pll_obj->b0 * pll_obj->u_beta[0])
							+ (pll_obj->b2 * pll_obj->u_beta[2])
							+ (pll_obj->a1 * pll_obj->uDash_beta[1])
							+ (pll_obj->a2 * pll_obj->uDash_beta[2]);

	//!- Quadrature Bandpass output
	pll_obj->quDash_alpha[0] = (pll_obj->q0 * pll_obj->u_alpha[0])
							+ (pll_obj->q1 * pll_obj->u_alpha[1])
							+ (pll_obj->q2 * pll_obj->u_alpha[2])
							+ (pll_obj->a1 * pll_obj->quDash_alpha[1])
							+ (pll_obj->a2 * pll_obj->quDash_alpha[2]);
	pll_obj->quDash_beta[0] = (pll_obj->q0 * pll_obj->u_beta[0])
							+ (pll_obj->q1 * pll_obj->u_beta[1])
							+ (pll_obj->q2 * pll_obj->u_alpha[2])
							+ (pll_obj->a1 * pll_obj->quDash_beta[1])
							+ (pll_obj->a2 * pll_obj->quDash_beta[2]);

	//!-  Update u, uDash and quDash for new calculation
	pll_obj->uDash_alpha[2] = pll_obj->uDash_alpha[1];
	pll_obj->uDash_alpha[1] = pll_obj->uDash_alpha[0];

	pll_obj->uDash_beta[2] = pll_obj->uDash_beta[1];
	pll_obj->uDash_beta[1] = pll_obj->uDash_beta[0];

	pll_obj->quDash_alpha[2] = pll_obj->quDash_alpha[1];
	pll_obj->quDash_alpha[1] = pll_obj->quDash_alpha[0];

	pll_obj->quDash_beta[2] = pll_obj->quDash_beta[1];
	pll_obj->quDash_beta[1] = pll_obj->quDash_beta[0];

	pll_obj->u_alpha[2] = pll_obj->u_alpha[1];
	pll_obj->u_alpha[1] = pll_obj->u_alpha[0];

	pll_obj->u_beta[2] = pll_obj->u_beta[1];
	pll_obj->u_beta[1] = pll_obj->u_beta[0];

	//!- uDash positive values
	pll_obj->uDash_pos_alpha = (pll_obj->uDash_alpha[0] - pll_obj->quDash_beta[0]) * 0.5f;
	pll_obj->uDash_pos_beta = (pll_obj->uDash_beta[0] + pll_obj->quDash_alpha[0]) * 0.5f;

	//!- Converting from alpha-beta into DQ
	pll_obj->u_d = (pll_obj->uDash_pos_alpha * pll_obj->cos_theta)
				 + (pll_obj->uDash_pos_beta * pll_obj->sin_theta);
	pll_obj->u_q = -(pll_obj->uDash_pos_alpha * pll_obj->sin_theta)
			     +  (pll_obj->uDash_pos_beta * pll_obj->cos_theta);

	//Update new value of v-q
	pll_obj->v_q[0] = pll_obj->u_q;

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

	pll_obj->sin_theta = sinf(pll_obj->theta[1]);
	pll_obj->cos_theta = cosf(pll_obj->theta[1]);


}
