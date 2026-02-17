/*
 * sa_ramp.c
 *
 *  Created on: Sep 29, 2022
 *      Author: Shwetank
 */


#include "sa_ramp.h"

// Detail of the defined functions

//! Used to reset the RAMPGEN pointer
void SA_RAMPGEN_reset(SA_RAMPGEN *v){
	v->out = 0;
	v->outAngle = 0;
}

//! Used to configure the RAMPGEN pointer
void SA_RAMPGEN_config(SA_RAMPGEN *v, float32_t isrFreq, float32_t rampFreq){
	v->freq = rampFreq;
	v->stepTimeMax = ((float32_t)1.0)/isrFreq;
}


//! Used to run the RAMPGEN driver
void SA_RAMGEN_run(SA_RAMPGEN *v){

	//Angle update rate or (theta = theta + delta_theta) calculation
	// but limited between (0,1)
	v->out += (v->stepTimeMax*v->freq);

	// Saturate within (0,1)
	v->out = (v->out > 1.0f)? (v->out-1.0f):v->out;
	v->outAngle = v->out * PI * 2.0f;

}
