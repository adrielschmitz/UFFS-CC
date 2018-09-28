@ programa para incrementar contador em leds, cada vez
@ que um botão é pressionado

	
        .global _start         @ ligador precisa do símbolo _start
	
@ endereços dos dispositivos
	.set COUNT,0x90010
	.set LED,0x90110
@ constantes
	.set BIT_READY,1
	.set MAX_COUNT,16
	
_start:
	ldr	r1,=COUNT       @ r2 tem botao conta
	ldr r2,=LED         @ r2 tem led
	mov	r3,#0		    @ r3 tem contador led
loop:
	ldr	r0,[r1]         @ verifica botao conta
	cmp	r0,#BIT_READY   @ foi pressionado?
	bne	loop            @ se nao foi, continua
@ aqui conta
	add	r3,#1		    @ incrementa contador e
	strb r3,[r2]		@ seta led 
	cmp	r3,#MAX_COUNT   @ volta a zero se necessario
	moveq r3,#0
	b	loop
