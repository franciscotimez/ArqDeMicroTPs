/*
 * Ejercicio.h
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#ifndef _EJERCICIO5_H_
#define _EJERCICIO5_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define ARRAY_SIZE 100

/*==================[external functions declaration]=========================*/
void filtroVentana10_C(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);
void filtroVentana10_ASM(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

#endif /* EJERCICIO1_INC_EJERCICIO1_H_ */
