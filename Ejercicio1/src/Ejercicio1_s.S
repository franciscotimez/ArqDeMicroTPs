
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
	.global zerosEnAsm

	/**
	 * Indicamos que la siguiente subrutina debe ser ensamblada en modo thumb,
	 * entonces en las direcciones en el ultimo bit tendran el 1 para que se reconozcan como en modo thumb.
	 * Siempre hay que ponerla antes de la primer instruccion.
	 */
	.thumb_func


/**
 *	prototipo de la funcion en C
 *
 *	void zerosEnAsm(uint32_t * vector, uint32_t longitud);
 *
 *	En r0 se cargara firstOperand y en r1 se carga secondOperand. Luego el valor devuelto estara en r0 (si son 32 bits).
 *	Si el resultado que retorna es en 64 bits, usa r0 y r1.
*/

#define vector 		r0
#define longitud 	r1
#define indice		r2
#define zero		r3



zerosEnAsm:
 	push {lr}  /* guardamos la direccion de retorno en la pila */

	ldr zero, =0
	mov indice, longitud

loop:
	str zero,[vector, indice, LSL 2] // vector = *(vector + (incice << 2))
	subs indice,#1
	bne loop

	pop {pc}   /* retorno */

	/* otras alternativas para el retorno */
	/* 1. mov pc,lr
	/  2. bx lr */
	/* pop {pc} */
