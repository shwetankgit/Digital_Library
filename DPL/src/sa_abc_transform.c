/*
 * sa_abc_transform.c
 *
 *  Created on: Sep 29, 2022
 *      Author: Shwetank
 */


#include "sa_abc_transform.h"

//! Used to reset the ABC Transform pointer
void SA_ABC_TRANSFORM_reset(SA_ABC_TRANSFORM *v){
	v->alpha = 0;
	v->beta = 0;
	v->d_pos = 0;
	v->q_pos = 0;
	v->z = 0;
	v->d_neg = 0;
	v->q_neg = 0;

}

//! Used to run the ABC Transform driver
void SA_ABC_TRANSFORM_run(SA_ABC_TRANSFORM *v,
										float32_t a, float32_t b, float32_t c,
										float32_t sinVal, float32_t cosVal){

	v->alpha = (0.66666666677f) * (a - 0.5f * (b + c));
	v->beta  = (0.57735026913f) * (b - c);
	v->d_pos = v->alpha * cosVal + v->beta * sinVal;
	v->q_pos = -v->alpha * sinVal   + v->beta * cosVal;
	v->z = (0.57735026913f) * (a + b + c);
	v->d_neg = v->alpha * cosVal - v->beta * sinVal;
	v->q_neg = v->alpha * sinVal   + v->beta * cosVal;
}
