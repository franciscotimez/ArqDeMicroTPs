/*
 * Ejercicio1.c
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#include "Ejercicio10.h"

void eco_C(int16_t * vectorIn, int16_t * vectorEco, uint32_t longitud, uint32_t echo)
{
	volatile uint32_t i = 0, j = 0;

	for(i = 0 ; i < echo ; i++){
		vectorEco[i] = vectorIn[i];
	}
	for( ; i < longitud ; i++){
		vectorEco[i] = vectorIn[i] + (vectorIn[j] >> 1);
		j++;
	}
	return;
}
