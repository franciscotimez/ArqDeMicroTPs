
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
	.global downsampleM_ASM		// Nombre de la funcion!!!!

	/**
	 * Indicamos que la siguiente subrutina debe ser ensamblada en modo thumb,
	 * entonces en las direcciones en el ultimo bit tendran el 1 para que se reconozcan como en modo thumb.
	 * Siempre hay que ponerla antes de la primer instruccion.
	 */
	.thumb_func


/**
 *	prototipo de la funcion en C
 *
 *	void downsampleM (int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N);
 *
 *	En r0 se cargara firstOperand y en r1 se carga secondOperand. Luego el valor devuelto estara en r0 (si son 32 bits).
 *	Si el resultado que retorna es en 64 bits, usa r0 y r1.
*/

#define vectorIn 	r0
#define vectorOut 	r1
#define longitud 	r2
#define N		 	r3
#define indiceI		r4
#define indiceJ		r5
#define indiceK		r6
#define indiceFan	r7
#define auxiliar	r8




downsampleM_ASM:		// Nombre de la funcion!!!!!
 	push 	{r4-r8, lr}  /* guardamos la direccion de retorno en la pila */

	subs 	longitud, #1
	mov 	indiceFan, longitud
	mov 	indiceI, #0
	mov 	indiceJ, N
	mov 	indiceK, #0


loop:
	subs 	indiceJ, #1 // vector = *(vector + (incice << 2))
	beq		else
	ldr		auxiliar, [vectorIn, indiceI, LSL 2]
	str		auxiliar, [vectorOut, indiceK, LSL 2]
	add		indiceK, #1
else:
	bne		skip
	mov 	indiceJ, N
skip:
	add		indiceI, #1
	subs 	indiceFan, #1
	bne 	loop
	mov 	auxiliar, #0
zeros:
	cmp 	indiceK, longitud
	str		auxiliar, [vectorOut, indiceK, LSL 2]
	add		indiceK, #1
	bne 	zeros

	pop 	{r4-r8, pc}   /* retorno */

	/* otras alternativas para el retorno */
	/* 1. mov pc,lr
	/  2. bx lr */
	/* pop {pc} */
