/*
 * Ejercicio.h
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#ifndef _EJERCICIO2_H_
#define _EJERCICIO2_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define ARRAY_SIZE 100

/*==================[external functions declaration]=========================*/
void productoEscalar32EnC(uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar);
void productoEscalar32EnASM(uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

#endif /* EJERCICIO1_INC_EJERCICIO1_H_ */
