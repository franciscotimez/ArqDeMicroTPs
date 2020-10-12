/*
 * Ejercicio.h
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#ifndef _EJERCICIO8_H_
#define _EJERCICIO8_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define ARRAY_SIZE 20

/*==================[external functions declaration]=========================*/
void downsampleM_C(int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N);
void downsampleM_ASM(int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

#endif /* EJERCICIO1_INC_EJERCICIO1_H_ */
