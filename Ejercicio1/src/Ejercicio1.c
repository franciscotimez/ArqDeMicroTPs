/*
 * Ejercicio1.c
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#include "Ejercicio1.h"

void zerosEnC(uint32_t * vector, uint32_t longitud)
{
	uint32_t i;
	for( i = 0 ; i < longitud ; i++){
		vector[i] = 0;
	}

	return;
}
