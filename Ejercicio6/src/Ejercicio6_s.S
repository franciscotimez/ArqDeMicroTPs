
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
	.global pack32to16_ASM		// Nombre de la funcion!!!!

	/**
	 * Indicamos que la siguiente subrutina debe ser ensamblada en modo thumb,
	 * entonces en las direcciones en el ultimo bit tendran el 1 para que se reconozcan como en modo thumb.
	 * Siempre hay que ponerla antes de la primer instruccion.
	 */
	.thumb_func


/**
 *	prototipo de la funcion en C
 *
 *	void pack32to16 (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);
 *
 *	En r0 se cargara firstOperand y en r1 se carga secondOperand. Luego el valor devuelto estara en r0 (si son 32 bits).
 *	Si el resultado que retorna es en 64 bits, usa r0 y r1.
*/

#define vectorIn 	r0
#define vectorOut 	r1
#define longitud	r2
#define indice		r3
#define auxiliar	r4




pack32to16_ASM:		// Nombre de la funcion!!!!!
 	push {r4, lr}  /* guardamos la direccion de retorno en la pila */

	mov indice, longitud

loop:
	subs indice,#1
	ldr auxiliar,[vectorIn, indice, LSL 2] // vector = *(vector + (incice << 2))
	asr	auxiliar, 16
	strh auxiliar,[vectorOut, indice, LSL 1]
	bne loop

	pop {r4, pc}   /* retorno */

	/* otras alternativas para el retorno */
	/* 1. mov pc,lr
	/  2. bx lr */
	/* pop {pc} */
