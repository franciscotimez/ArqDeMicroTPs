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

#include "Ejercicio10.h"
#include "board.h"
/*
 * Consigna:
 * 			Realizar una función que recibe un vector de 4096 valores de 16 bits
 * 			(signados), que corresponden a muestras de audio tomadas a una tasa
 * 			de muestreo de 44.100 muestras/s. La función debe introducir un “eco”
 * 			de la mitad de la amplitud de la muestra original a los 20ms de comenzada
 * 			la grabación.
 *
 * 			Nota: El eco consiste en adicionar a la señal original, la propia
 * 			señal original dividida por dos y atrasada en 20ms, como muestra la
 * 			ilustración debajo. Por qué la cantidad de muestras copiadas iguales es de 882?
 *
 * 			Variante: Una vez implementada la función, programar una nueva versión
 * 			que utilice las instrucciones SIMD para optimizar la ejecución del algoritmo.
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

	uint32_t ECO_N = 882;

	int16_t vectorInC[ARRAY_SIZE];
	int16_t vectorEcoC[ARRAY_SIZE];

	initHardware();

	/* Se inicializa el array func con valores de 0 a ARRAY_SIZE */
	for(uint32_t i = 0 ; i < ARRAY_SIZE ; i++){
		vectorInC[i] = 20;
		//vectorInAsm[i] = 10;
	}


	*DWT_CTRL  |= 1; 				// Activa el contador de ciclos

	*DWT_CYCCNT = 0;				//resetea el contador de ciclos
	eco_C(vectorInC, vectorEcoC, ARRAY_SIZE, ECO_N);		// 96856 ciclos
	cyclesC=*DWT_CYCCNT;			//Guarda la cuenta de ciclos

	/* Se inicializa el array func con valores de 0 a ARRAY_SIZE */
	for(uint32_t i = 0 ; i < ARRAY_SIZE ; i++){
		vectorInC[i] = 30;
		//vectorInAsm[i] = 10;
	}

	*DWT_CYCCNT = 0;
	eco_ASM(vectorInC, vectorEcoC, ARRAY_SIZE, ECO_N);		// 44798 ciclos
	cyclesAsm=*DWT_CYCCNT;

	/* Se inicializa el array func con valores de 0 a ARRAY_SIZE */
	for(uint32_t i = 0 ; i < ARRAY_SIZE ; i++){
		vectorInC[i] = 40;
		//vectorInAsm[i] = 10;
	}

	*DWT_CYCCNT = 0;
	eco_SIMD(vectorInC, vectorEcoC, ARRAY_SIZE, ECO_N);		// 20818 ciclos
	cyclesSIMD=*DWT_CYCCNT;

	*DWT_CYCCNT = 0;
	while (1)
	{
		__WFI(); //wfi
	}
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/
