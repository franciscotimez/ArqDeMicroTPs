/*
 * Ejercicio.h
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#ifndef _EJERCICIO10_H_
#define _EJERCICIO10_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define ARRAY_SIZE 4096

/*==================[external functions declaration]=========================*/
void eco_C(int16_t * vectorIn, int16_t * vectorEco, uint32_t longitud, uint32_t echo);
void eco_ASM(int16_t * vectorIn, int16_t * vectorEco, uint32_t longitud, uint32_t echo);
void eco_SIMD(int16_t * vectorIn, int16_t * vectorEco, uint32_t longitud, uint32_t echo);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

#endif /* EJERCICIO1_INC_EJERCICIO1_H_ */
