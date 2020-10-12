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

#include "Ejercicio5.h"
#include "board.h"
/*
 * Consigna:
 * 			Realice una función que implemente un filtro de ventana móvil de
 * 			10 valores sobre un vector de muestras.
 *
 * 			void filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);
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

	uint16_t vectorInC[ARRAY_SIZE];
	uint16_t vectorInAsm[ARRAY_SIZE];
	uint16_t vectorInSIMD[ARRAY_SIZE];

	uint16_t vectorOutC[ARRAY_SIZE];
	uint16_t vectorOutAsm[ARRAY_SIZE];
	uint16_t vectorOutSIMD[ARRAY_SIZE];


	initHardware();

	/* Se inicializa el array func con valores de 0 a ARRAY_SIZE */
	for(uint32_t i = 0 ; i < ARRAY_SIZE ; i++){
		vectorInC[i] = i;
		vectorInAsm[i] = i;
		vectorInSIMD[i] = i;
	}


	*DWT_CTRL  |= 1; 				// Activa el contador de ciclos

	*DWT_CYCCNT = 0;				//resetea el contador de ciclos
	filtroVentana10_C(vectorInC, vectorOutC, ARRAY_SIZE);		// 14047 ciclos
	cyclesC=*DWT_CYCCNT;			//Guarda la cuenta de ciclos

	*DWT_CYCCNT = 0;
	filtroVentana10_ASM(vectorInAsm, vectorOutAsm, ARRAY_SIZE);	// 8520 ciclos
	cyclesAsm=*DWT_CYCCNT;

	*DWT_CYCCNT = 0;
	filtroVentana10_SIMD(vectorInSIMD, vectorOutSIMD, ARRAY_SIZE);	// 4875 ciclos
	cyclesSIMD=*DWT_CYCCNT;

	*DWT_CYCCNT = 0;
	while (1)
	{
		__WFI(); //wfi
	}
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/
