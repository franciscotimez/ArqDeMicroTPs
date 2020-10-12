/*
 * Ejercicio1.c
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#include "Ejercicio2.h"

void productoEscalar32EnC(uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar)
{
	uint32_t i;
	//for( i = longitud ; i > 0 ; --i){
	//		vectorOut[i] = vectorIn[i] * escalar;
	//	}
	for( i = 0 ; i < longitud ; i++){
		vectorOut[i] = vectorIn[i] * escalar;
	}
	return;
}
