/*
 * Ejercicio.h
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#ifndef _EJERCICIO4_H_
#define _EJERCICIO4_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define ARRAY_SIZE 100

/*==================[external functions declaration]=========================*/
void productoEscalar12EnC(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);
void productoEscalar12EnASM(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

#endif /* EJERCICIO1_INC_EJERCICIO1_H_ */
