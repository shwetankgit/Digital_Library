/*
 * sa_alphabeta_to_abc.h
 *
 *  Created on: Jan 10, 2023
 *      Author: Shwetank
 */

#ifndef DPL_INC_SA_ALPHABETA_TO_ABC_H_
#define DPL_INC_SA_ALPHABETA_TO_ABC_H_

#ifdef __cplusplus
extern "C" {
#endif

// includes the defines used in Shwetank Agrawal(SA) Library
#include "stm32f4xx.h"
#include "arm_math.h"


//! ABC Inverse Transform (Clarke, Park) from AlphaBeta Structure
typedef struct{
	float32_t a; 		// Output: A phase of 3PH AC Signal
	float32_t b; 		// Output: B phase of 3PH AC Signal
	float32_t c;	 	// Output: C phase of 3PH AC Signal

}SA_ALPHABETA_TO_ABC;


//! Used to reset the alphaBeta pointer reset
extern void SA_ALPHABETA_TO_ABC_reset(SA_ALPHABETA_TO_ABC *v);


//! Used to run the alphaBeta driver
extern void SA_ALPHABETA_TO_ABC_run(SA_ALPHABETA_TO_ABC *v, float32_t alpha, float32_t beta);



#ifdef __cplusplus
}
#endif


#endif /* DPL_INC_SA_ALPHABETA_TO_ABC_H_ */
