/*
 * Ejercicio.h
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#ifndef _EJERCICIO9_H_
#define _EJERCICIO9_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define ARRAY_SIZE 20

/*==================[external functions declaration]=========================*/
void invertir_C (uint16_t * vector, uint32_t longitud);
void invertir_ASM(uint16_t * vector, uint32_t longitud);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

#endif /* EJERCICIO1_INC_EJERCICIO1_H_ */
