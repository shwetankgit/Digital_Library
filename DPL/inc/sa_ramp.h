/*
 * sa_ramp.h
 *
 *  Created on: Sep 29, 2022
 *      Author: Shwetank
 */

#ifndef INC_SA_RAMP_H_
#define INC_SA_RAMP_H_

#ifdef __cplusplus
extern "C" {
#endif


// includes the defines used in Shwetank Agrawal(SA) Library
#include "stm32f4xx.h"
#include "arm_math.h"




//! Ramp Signal Generator Structure
typedef volatile struct{
	float32_t freq;			// Input: Ramp Frequency(pu)
	float32_t stepTimeMax;	// Parameter: Maximum step Time
	float32_t out;			// Output: Ramp Signal(pu)
	float32_t outAngle;	// Output: Updated New angle in Radian
} SA_RAMPGEN;


//! Used to reset the RAMPGEN pointer
extern void SA_RAMPGEN_reset(SA_RAMPGEN *v);

//! Used to configure the RAMPGEN pointer
extern void SA_RAMPGEN_config(SA_RAMPGEN *v, float32_t isrFreq, float32_t rampFreq);

//! Used to run the RAMPGEN driver
extern void SA_RAMGEN_run(SA_RAMPGEN *v);





#ifdef __cplusplus
}
#endif

#endif /* INC_SA_RAMP_H_ */
