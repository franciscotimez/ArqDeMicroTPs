/*
 * Ejercicio1.c
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#include "Ejercicio9.h"

void invertir_C (uint16_t * vectorIn, uint32_t longitud)
{
	volatile uint32_t i = 0, j = longitud - 1;
	uint16_t auxiliar;

	while(i < j){
		auxiliar = vectorIn[i];
		vectorIn[i] = vectorIn[j];
		vectorIn[j] = auxiliar;
		i++;
		j--;
	}
	return;
}
