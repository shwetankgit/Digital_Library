/*
 * sa_abc_transform.h
 *
 *  Created on: Sep 29, 2022
 *      Author: Shwetank
 */

#ifndef INC_SA_ABC_TRANSFORM_H_
#define INC_SA_ABC_TRANSFORM_H_

#ifdef __cplusplus
extern "C" {
#endif

// includes the defines used in Shwetank Agrawal(SA) Library
#include "stm32f4xx.h"
#include "arm_math.h"


//! ABC Transform (Clarke, Park) and Positive and negative sequence Structure
typedef struct{
	float32_t alpha;	// Output: Alpha Component of abc (from Clarke Transform)
	float32_t beta;		// Output: Beta Component of abc (from Clarke Transform)
	float32_t d_pos;	// Output: D axis Positive Sequence Component of alpha-beta (from park Transform)
	float32_t q_pos; 	// Output: Q axis Positive Sequence Component of alpha-beta (from park Transform)
	float32_t z;		// Output: Z axis component of alpha-beta
	float32_t d_neg; 	// Output: D axis Negative Sequence Component of alpha-beta (from park Transform)
	float32_t q_neg; 	// Output: Q axis Negative Sequence Component of alpha-beta (from park Transform)

}SA_ABC_TRANSFORM;


//! Used to reset the ABC transform pointer reset
extern void SA_ABC_TRANSFORM_reset(SA_ABC_TRANSFORM *v);


//! Used to run the ABC transform driver
extern void SA_ABC_TRANSFORM_run(SA_ABC_TRANSFORM *v, float32_t a, float32_t b, float32_t c, float32_t sinVal, float32_t cosVal);


#ifdef __cplusplus
}
#endif

#endif /* INC_SA_ABC_TRANSFORM_H_ */
