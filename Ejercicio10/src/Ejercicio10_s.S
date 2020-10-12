
	/**
	 * Directiva al ensablador que permite indicar que se encarga de buscar
	 * la instruccion mas apropiada entre thumb y thumb2
	 */
	.syntax unified

	/**
	 * .text permite indicar una seccion de codigo.
	 */
	.text

	/**
	 * .global permite definir un simbolo exportable,
	 * es decir que podemos verlo desde otros modulos (equivalente a extern).
     * Definimos la rutina como global para que sea visible desde otros modulos.
     */
	.global eco_ASM		// Nombre de la funcion!!!!
	.global eco_SIMD

	/**
	 * Indicamos que la siguiente subrutina debe ser ensamblada en modo thumb,
	 * entonces en las direcciones en el ultimo bit tendran el 1 para que se reconozcan como en modo thumb.
	 * Siempre hay que ponerla antes de la primer instruccion.
	 */
	.thumb_func


/**
 *	prototipo de la funcion en C
 *
 *	void eco_ASM(int16_t * vectorIn, int16_t * vectorEco, uint32_t longitud, uint32_t echo);
 *
 *	En r0 se cargara firstOperand y en r1 se carga secondOperand. Luego el valor devuelto estara en r0 (si son 32 bits).
 *	Si el resultado que retorna es en 64 bits, usa r0 y r1.
*/

#define vectorIn 	r0
#define vectorEco 	r1
#define longitud 	r2
#define echo		r3
#define indiceI		r4
#define indiceJ		r5
#define auxiliar1	r6
#define auxiliar2	r7
#define Zero		r8

/*
*	ASM
*/

eco_ASM:		// Nombre de la funcion!!!!!
 	push 	{r4-r7, lr}  /* guardamos la direccion de retorno en la pila */

	mov 	indiceI, echo
	mov		indiceJ, longitud
	sub		indiceJ, echo

loopCopy:
	subs 	indiceI, #1		//Para que arranque en el (echo - 1)
	ldrsh	auxiliar1, [vectorIn, indiceI, LSL 1]
	strh	auxiliar1, [vectorEco, indiceI, LSL 1]
	bne 	loopCopy

	mov		indiceI, longitud
loop:
	sub		indiceI, #1
	subs 	indiceJ, #1
	ldrsh	auxiliar1, [vectorIn, indiceI, LSL 1]	// esta es la senhal original
	ldrsh	auxiliar2, [vectorIn, indiceJ, LSL 1]	// este es el echo
	add		auxiliar2, auxiliar1, auxiliar2, ASR 1
	ssat	auxiliar2, 16, auxiliar2
	strh	auxiliar2, [vectorEco, indiceI, LSL 1]
	bne 	loop

	pop 	{r4-r7, pc}   /* retorno */

	/* otras alternativas para el retorno */
	/* 1. mov pc,lr
	/  2. bx lr */
	/* pop {pc} */

/*
*	Implementacion en SIMD
*/
eco_SIMD:		// Nombre de la funcion!!!!!
 	push 	{r4-r8, lr}  /* guardamos la direccion de retorno en la pila */

	mov		Zero, #0
	mov 	indiceI, echo
	lsr		indiceI, 1		// divido en 2 el echo, porque proceso de a 2 elementos
	mov		indiceJ, longitud	// indiceJ es para recorrer el vector dividido
	lsr		indiceJ, 1
	sub		indiceJ, indiceI


loopCopySIMD:
	subs 	indiceI, #1		//Para que arranque en el (echo - 1)
	ldr		auxiliar1, [vectorIn, indiceI, LSL 2]
	str		auxiliar1, [vectorEco, indiceI, LSL 2]
	bne 	loopCopySIMD

	mov		indiceI, longitud, LSR 1
loopSIMD:
	sub		indiceI, #1
	subs 	indiceJ, #1
	ldr		auxiliar1, [vectorIn, indiceI, LSL 2]	// esta es la senhal original
	ldr		auxiliar2, [vectorIn, indiceJ, LSL 2]	// este es el echo
	shadd16	auxiliar2, auxiliar2, Zero
	qadd16	auxiliar2, auxiliar2, auxiliar1
	str		auxiliar2, [vectorEco, indiceI, LSL 2]
	bne 	loopSIMD

	pop 	{r4-r8, pc}   /* retorno */
