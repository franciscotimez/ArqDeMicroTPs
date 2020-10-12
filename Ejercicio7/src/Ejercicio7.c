/*
 * Ejercicio1.c
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#include "Ejercicio7.h"

int32_t max_C(int32_t * vectorIn, uint32_t longitud)
{
	uint32_t i;
	int32_t maximo = vectorIn[0];

	for( i = 1 ; i < longitud ; i++){
		if(vectorIn[i] > maximo) maximo = i;
	}
	return maximo;
}
