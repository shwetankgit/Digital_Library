/*
 * sa_alphabeta_to_abc.c
 *
 *  Created on: Jan 10, 2023
 *      Author: Shwetank
 */

#include "sa_alphabeta_to_abc.h"

// Detail of the defined functions


//! Used to reset the alphaBeta pointer reset
void SA_ALPHABETA_TO_ABC_reset(SA_ALPHABETA_TO_ABC *v){
	v->a = 0;
	v->b = 0;
	v->c = 0;
}



//! Used to run the alphaBeta driver
void SA_ALPHABETA_TO_ABC_run(SA_ALPHABETA_TO_ABC *v, float32_t alpha, float32_t beta){
	v->a 	= alpha;
	v->b 	= -0.5f * alpha + 0.8660254f * beta;
	v->c 	= -0.5f * alpha - 0.8660254f * beta;

}
