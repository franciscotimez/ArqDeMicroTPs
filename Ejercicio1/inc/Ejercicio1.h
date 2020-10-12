/*
 * Ejercicio.h
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */

#ifndef _EJERCICIO1_H_
#define _EJERCICIO1_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define ARRAY_SIZE 100

/*==================[external functions declaration]=========================*/
void zerosEnC(uint32_t * vector, uint32_t longitud);
void zerosEnAsm(uint32_t * vector, uint32_t longitud);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

#endif /* EJERCICIO1_INC_EJERCICIO1_H_ */
