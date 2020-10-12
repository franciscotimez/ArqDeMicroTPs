
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
	.global max_ASM		// Nombre de la funcion!!!!

	/**
	 * Indicamos que la siguiente subrutina debe ser ensamblada en modo thumb,
	 * entonces en las direcciones en el ultimo bit tendran el 1 para que se reconozcan como en modo thumb.
	 * Siempre hay que ponerla antes de la primer instruccion.
	 */
	.thumb_func


/**
 *	prototipo de la funcion en C
 *
 *	int32_t max (int32_t * vectorIn, uint32_t longitud);
 *
 *	En r0 se cargara firstOperand y en r1 se carga secondOperand. Luego el valor devuelto estara en r0 (si son 32 bits).
 *	Si el resultado que retorna es en 64 bits, usa r0 y r1.
*/

#define vectorIn 	r0
#define longitud 	r1
#define indice		r2
#define auxiliar	r3
#define maximo		r4
#define maximoind	r5




max_ASM:		// Nombre de la funcion!!!!!
 	push 	{r4, r5, lr}  /* guardamos la direccion de retorno en la pila */

	mov 	indice, longitud
	subs 	indice,#1
	ldr 	maximo, [vectorIn, indice, LSL 2]
	mov		maximoind, indice
	subs 	indice,#1

loop:

	ldr		auxiliar, [vectorIn, indice, LSL 2]
	cmp 	auxiliar, maximo // vector = *(vector + (incice << 2))
	ble		skip
	//itt		gt
	//ldrgt	maximo,[vectorIn, indice, LSL 2]
	//movgt	maximoind, indice
	ldr 	maximo, [vectorIn, indice, LSL 2]
	mov		maximoind, indice
skip:
	subs 	indice,#1
	bpl 	loop

	mov		r0, maximoind
	pop 	{r4, r5, pc}   /* retorno */

	/* otras alternativas para el retorno */
	/* 1. mov pc,lr
	/  2. bx lr */
	/* pop {pc} */
