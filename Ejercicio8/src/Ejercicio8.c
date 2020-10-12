/*
 * Ejercicio1.c
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#include "Ejercicio8.h"

void downsampleM_C(int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N)
{
	volatile uint32_t i, j = 0, k = 0;

	for( i = 0 ; i < longitud ; i++){
		if(j < N - 1){
			vectorOut[k] = vectorIn[i];
			k++;
			j++;
		}
		else {
			j = 0;
		}
	}
	for(  ; k < longitud ; k++) vectorOut[k] = 0;
	return;
}
