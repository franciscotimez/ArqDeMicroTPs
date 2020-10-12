/*
 * main.c
 *
 *  Created on: 6 oct. 2020
 *      Author: francisco
 */



/** @brief This is a simple blink example.
 */

/** \addtogroup blink Bare-metal blink example
 ** @{ */

/*==================[inclusions]=============================================*/

#include "main.h"

#include "Ejercicio8.h"
#include "board.h"
/*
 * Consigna:
 * 			Realizar una función que realice el producto de un vector y
 * 			un escalar (por ejemplo, podría servir para cambiar el nivel
 * 			de amplitud de una señal).
 * 			void productoEscalar32 (uint32_t * vectorIn, uint32_t * vectorOut uint32_t longitud, uint32_t escalar);
 */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/
volatile uint32_t * DWT_CTRL   = (uint32_t *)0xE0001000;
volatile uint32_t * DWT_CYCCNT = (uint32_t *)0xE0001004;

/*==================[internal functions declaration]=========================*/

/** @brief hardware initialization function
 *	@return none
 */
static void initHardware(void);

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

static void initHardware(void)
{
	Board_Init();
	SystemCoreClockUpdate();
	//SysTick_Config(SystemCoreClock / 1000);
}

/*==================[external functions definition]==========================*/

int main(void)
{
	// Variables para guardar los ciclos de ejecucion
	volatile uint32_t cyclesC = 0, cyclesAsm = 0, cyclesSIMD = 0;

	uint32_t N = 4;

	int32_t vectorInC[ARRAY_SIZE];
	int32_t vectorOutC[ARRAY_SIZE];

	int32_t vectorInAsm[ARRAY_SIZE];
	int32_t vectorOutAsm[ARRAY_SIZE];

	initHardware();

	/* Se inicializa el array func con valores de 0 a ARRAY_SIZE */
	for(uint32_t i = 0 ; i < ARRAY_SIZE ; i++){
		vectorInC[i] = i;
		vectorInAsm[i] = i;
	}


	*DWT_CTRL  |= 1; 				// Activa el contador de ciclos

	*DWT_CYCCNT = 0;				//resetea el contador de ciclos
	downsampleM_C(vectorInC, vectorOutC, ARRAY_SIZE, N); 	// 685 ciclos
	cyclesC=*DWT_CYCCNT;			//Guarda la cuenta de ciclos

	*DWT_CYCCNT = 0;
	downsampleM_ASM(vectorInAsm, vectorOutAsm, ARRAY_SIZE, N);	// 294 ciclos
	cyclesAsm=*DWT_CYCCNT;

	*DWT_CYCCNT = 0;
	//	resultSIMD=avgWindowSIMD (func, ARRAY_SIZE, n_samples, delta_samples);
	//	cyclesSIMD=*DWT_CYCCNT;
	while (1)
	{
		__WFI(); //wfi
	}
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/
