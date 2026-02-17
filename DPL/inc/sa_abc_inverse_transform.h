/*
 * sa_abc_inverse_transform.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Shwetank
 */

#ifndef INC_SA_ABC_INVERSE_TRANSFORM_H_
#define INC_SA_ABC_INVERSE_TRANSFORM_H_

#ifdef __cplusplus
extern "C" {
#endif

// includes the defines used in Shwetank Agrawal(SA) Library
#include "stm32f4xx.h"
#include "arm_math.h"


//! ABC Inverse Transform (Clarke, Park) from DQ0 Structure
typedef struct{
	float32_t a; 		// Output: A phase of 3PH AC Signal
	float32_t b; 		// Output: B phase of 3PH AC Signal
	float32_t c;	 	// Output: C phase of 3PH AC Signal
	float32_t alpha;	// Output: Alpha Component of abc
	float32_t beta;		// Output: Beta Component of abc

}SA_ABC_INVERSE_TRANSFORM;


//! Used to reset the ABC Inverse transform pointer reset
extern void SA_ABC_INVERSE_TRANSFORM_reset(SA_ABC_INVERSE_TRANSFORM *v);


//! Used to run the ABC Inverse transform driver
extern void SA_ABC_INVERSE_TRANSFORM_run(SA_ABC_INVERSE_TRANSFORM *v, float32_t d, float32_t q, float32_t z, float32_t sinVal, float32_t cosVal);



#ifdef __cplusplus
}
#endif


#endif /* INC_SA_ABC_INVERSE_TRANSFORM_H_ */
