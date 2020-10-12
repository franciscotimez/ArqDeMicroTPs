/*
 * Ejercicio1.c
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#include "Ejercicio5.h"
#define VENTANA		10
void filtroVentana10_C(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudIn)
{
	uint32_t offsetVentana = 0;

	for(uint32_t i = 0 ; i < longitudIn ; i++) vectorOut[i] = 0;

	for( offsetVentana = 0 ; offsetVentana < (longitudIn - VENTANA + 1) ; offsetVentana++)	// Muevo la ventana
	{
		for( uint32_t j = 0; j < VENTANA ; j++ ) //acumulo la ventana
		{
			vectorOut[offsetVentana] += vectorIn[offsetVentana + j];
		}
		vectorOut[offsetVentana] /= VENTANA;
	}
	return;
}
