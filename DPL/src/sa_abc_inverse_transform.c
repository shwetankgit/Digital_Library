/*
 * sa_abc_inverse_transform.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Shwetank
 */



#include "sa_abc_inverse_transform.h"

// Detail of the defined functions


//! Used to reset the ABC Inverse transform pointer reset
void SA_ABC_INVERSE_TRANSFORM_reset(SA_ABC_INVERSE_TRANSFORM *v){
	v->a = 0;
	v->b = 0;
	v->c = 0;
	v->alpha = 0;
	v->beta = 0;
}



//! Used to run the ABC Inverse transform driver
void SA_ABC_INVERSE_TRANSFORM_run(SA_ABC_INVERSE_TRANSFORM *v, float32_t d, float32_t q, float32_t z, float32_t sinVal, float32_t cosVal){
	v->alpha = d * cosVal  - q * sinVal;
	v->beta  = d * sinVal  + q * cosVal;
	v->a 	= v->alpha  + 0.5f * z;
	v->b 	= -0.5f * v->alpha + 0.8660254f * v->beta + 0.5f * z;
	v->c 	= -0.5f * v->alpha - 0.8660254f * v->beta + 0.5f * z;

}
