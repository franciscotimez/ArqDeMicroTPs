
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
	.global filtroVentana10_ASM		// Nombre de la funcion!!!!
	.global filtroVentana10_SIMD
	/**
	 * Indicamos que la siguiente subrutina debe ser ensamblada en modo thumb,
	 * entonces en las direcciones en el ultimo bit tendran el 1 para que se reconozcan como en modo thumb.
	 * Siempre hay que ponerla antes de la primer instruccion.
	 */
	.thumb_func


/**
 *	prototipo de la funcion en C
 *
 *	void filtroVentana10_ASM(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);
 *
 *	En r0 se cargara firstOperand y en r1 se carga secondOperand. Luego el valor devuelto estara en r0 (si son 32 bits).
 *	Si el resultado que retorna es en 64 bits, usa r0 y r1.
*/

#define vectorIn 	r0
#define vectorOut 	r1
#define longitudIn	r2
#define baseVent	r3
#define indiceV		r4
#define indiceI		r5
#define auxiliar	r6
#define acumulador	r7
#define	Ventana		r8


filtroVentana10_ASM:		// Nombre de la funcion!!!!!
 	push 	{r4-r8, lr}  /* guardamos la direccion de retorno en la pila */

	mov		Ventana, #10
	add 	indiceV, longitudIn, Ventana
	add		baseVent, vectorIn, longitudIn, LSL 1
	sub		baseVent, #20

	mov		indiceI, longitudIn
	sub		indiceI, Ventana

loop:
	mov 	indiceV, Ventana
	mov		acumulador, #0

loopVentana:
	subs 	indiceV, #1
	ldrh 	auxiliar,[baseVent, indiceV, LSL 1] // vector = *(vector + (incice << 2))
	add		acumulador, acumulador, auxiliar
	usat 	auxiliar,16,auxiliar
	bne 	loopVentana
	udiv	acumulador, acumulador, Ventana
	strh	acumulador, [vectorOut, indiceI, LSL 1]
	sub		baseVent, #2
	subs	indiceI, #1
	bpl		loop

	pop 	{r4-r8, pc}   /* retorno */

	/* otras alternativas para el retorno */
	/* 1. mov pc,lr
	/  2. bx lr */
	/* pop {pc} */

/*
*	Implementacion SIMD
*/
filtroVentana10_SIMD:		// Nombre de la funcion!!!!!
 	push 	{r4-r8, lr}  /* guardamos la direccion de retorno en la pila */

	mov		Ventana, #10
	add 	indiceV, longitudIn, Ventana
	add		baseVent, vectorIn, longitudIn, LSL 1
	sub		baseVent, #20

	mov		indiceI, longitudIn
	sub		indiceI, Ventana

loopSIMD:
	mov 	indiceV, Ventana, LSR 1
	mov		acumulador, #0

loopVentanaSIMD:
	subs 	indiceV, #1
	ldr 	auxiliar,[baseVent, indiceV, LSL 2] // vector = *(vector + (incice << 2))
	uqadd16	acumulador, acumulador, auxiliar
	bne 	loopVentanaSIMD

	uqasx	acumulador, acumulador, acumulador
	lsr		acumulador, 16
	udiv	acumulador, acumulador, Ventana
	strh	acumulador, [vectorOut, indiceI, LSL 1]
	sub		baseVent, #2
	subs	indiceI, #1
	bpl		loopSIMD

	pop 	{r4-r8, pc}   /* retorno */
