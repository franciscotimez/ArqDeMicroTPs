/*
 * Ejercicio1.c
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#include "Ejercicio6.h"

void pack32to16_C (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud)
{
	uint32_t i;

	for( i = 0 ; i < longitud ; i++){
		vectorOut[i] = vectorIn[i] >> 16;
	}
	return;
}
