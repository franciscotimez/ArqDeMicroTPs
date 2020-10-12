/*
 * Ejercicio1.c
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#include "Ejercicio4.h"

void productoEscalar12EnC(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar)
{
	uint32_t i;
	//for( i = longitud ; i > 0 ; --i){
	//		vectorOut[i] = vectorIn[i] * escalar;
	//	}
	for( i = 0 ; i < longitud ; i++){
		vectorOut[i] = vectorIn[i] * escalar;
		if(vectorOut[i] > 0x0FFF) vectorOut[i] = 0x0FFF;
	}
	return;
}
