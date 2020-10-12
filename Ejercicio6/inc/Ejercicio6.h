/*
 * Ejercicio.h
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#ifndef _EJERCICIO6_H_
#define _EJERCICIO6_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define ARRAY_SIZE 200

/*==================[external functions declaration]=========================*/
void pack32to16_C (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);
void pack32to16_ASM (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);
void pack32to16_SIMD (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

#endif /* EJERCICIO1_INC_EJERCICIO1_H_ */
