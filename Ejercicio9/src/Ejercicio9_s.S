
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
	.global invertir_ASM		// Nombre de la funcion!!!!

	/**
	 * Indicamos que la siguiente subrutina debe ser ensamblada en modo thumb,
	 * entonces en las direcciones en el ultimo bit tendran el 1 para que se reconozcan como en modo thumb.
	 * Siempre hay que ponerla antes de la primer instruccion.
	 */
	.thumb_func


/**
 *	prototipo de la funcion en C
 *
 *	void invertir_ASM(uint16_t * vectorIn, uint32_t longitud);
 *
 *	En r0 se cargara firstOperand y en r1 se carga secondOperand. Luego el valor devuelto estara en r0 (si son 32 bits).
 *	Si el resultado que retorna es en 64 bits, usa r0 y r1.
*/

#define vectorIn 	r0
#define longitud 	r1
#define indiceI		r2
#define indiceJ		r3
#define auxiliar1	r4
#define auxiliar2	r5





invertir_ASM:		// Nombre de la funcion!!!!!
 	push 	{r4-r5, lr}  /* guardamos la direccion de retorno en la pila */

	mov 	indiceI, longitud, LSR 1
	sub 	indiceI, #1
	mov 	indiceJ, longitud
	sub 	indiceJ, #1
	sub		indiceJ, indiceI

loop:
	ldrh	auxiliar1, [vectorIn, indiceI, LSL 1]
	ldrh	auxiliar2, [vectorIn, indiceJ, LSL 1]
	strh	auxiliar1, [vectorIn, indiceJ, LSL 1]
	strh	auxiliar2, [vectorIn, indiceI, LSL 1]
	add		indiceJ, #1
	subs 	indiceI, #1
	bpl 	loop

	pop 	{r4-r5, pc}   /* retorno */

	/* otras alternativas para el retorno */
	/* 1. mov pc,lr
	/  2. bx lr */
	/* pop {pc} */
