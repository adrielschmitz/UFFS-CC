
	.global _start

@ modos de interrupção no registrador de status
	.set IRQ_MODE,0x12
	.set USER_MODE,0x10

@ flag para habilitar interrupções externas no registrador de status
	.set IRQ, 0x80

@enderecos dispositivos
	.set DISPLAY, 0x90000
	.set TIMER,   0x90008
@ constantes
	.set INTERVAL,1000

@ vetor de interrupções
	.org  7*4               @ preenche apenas uma posição do vetor,
	                        @ correspondente ao tipo 6
	b       tratador_timer

	.org 0x1000
_start:
	mov	sp,#0x400	@ seta pilha do modo supervisor
	mov	r0,#IRQ_MODE	@ coloca processador no modo IRQ (interrupção externa)
	msr	cpsr,r0		@ processador agora no modo IRQ
	mov	sp,#0x300	@ seta pilha de interrupção IRQ
	mov	r0,#USER_MODE	@ coloca processador no modo usuário
	bic     r0,r0,#IRQ      @ interrupções IRQ habilitadas
	msr	cpsr,r0		@ processador agora no modo usuário
	mov	sp,#0x40000	@ pilha do usuário no final da memória 

	ldr	r2,=DISPLAY	@ r2 tem porta display
	mov	r3,#0		@ r3 tem contador
	ldr	r4,=digitos
	ldrb	r0,[r4,r3]      @ padrao de bits para valor 0
	strb  	r0,[r2]		@ seta valor inicial display
	ldr	r0,=INTERVAL
	ldr	r6,=TIMER
	str  	r0,[r6]		@ seta timer
loop:
	ldr	r1,=flag
	ldr	r0,[r1]
	cmp	r0,#0
	beq	loop
	mov	r0,#0		@ reseta flag
	str	r0,[r1]
	
	@ aqui conta
	add	r3,r3,#1	@ incrementa contador e
	cmp	r3,#10		@ volta a zero se necessario
	moveq	r3,#0
	ldrb	r0,[r4,r3]      @ padrao de bits para valor
	strb  	r0,[r2]		@ seta display
	b	loop

flag:
     .word 0
digitos:
     .byte 0x7e,0x30,0x6d,0x79,0x33,0x5b,0x5f,0x70,0x7f,0x7b

@ tratador da interrupcao	
@ aqui quando timer expirou
	.align 4
tratador_timer:
	ldr	r7,=flag	@ apenas liga a flag
	mov	r8,#1
	str	r8,[r7]
	movs	pc,lr		@ e retorna
