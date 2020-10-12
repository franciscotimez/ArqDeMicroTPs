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

#include "Ejercicio1.h"
#include "board.h"

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

	uint32_t vectorC[ARRAY_SIZE];
	uint32_t vectorAsm[ARRAY_SIZE];


	initHardware();

	/* Se inicializa el array func con valores de 0 a ARRAY_SIZE */
	for(uint32_t i = 0 ; i < ARRAY_SIZE ; i++){
		vectorC[i] = i;
		vectorAsm[i] = i;
	}


	*DWT_CTRL  |= 1; 				// Activa el contador de ciclos

	*DWT_CYCCNT = 0;				//resetea el contador de ciclos
	zerosEnC(vectorC, ARRAY_SIZE);	//822 ciclos
	cyclesC=*DWT_CYCCNT;			//Guarda la cuenta de ciclos

	*DWT_CYCCNT = 0;
	zerosEnAsm(vectorAsm, ARRAY_SIZE);	//534 ciclos
	cyclesAsm=*DWT_CYCCNT;

	//	*DWT_CYCCNT = 0;
	//	resultSIMD=avgWindowSIMD (func, ARRAY_SIZE, n_samples, delta_samples);
	//	cyclesSIMD=*DWT_CYCCNT;
	while (1)
	{
		__WFI(); //wfi
	}
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/
