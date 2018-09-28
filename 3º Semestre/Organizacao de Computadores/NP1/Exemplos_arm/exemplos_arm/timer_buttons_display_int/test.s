@ Programa para incrementar contador, mostrado em um mostrador de sete segmentos.
@ O botão Start inicia o timer, o botão Stop cancela o timer.
	
        .global _start         @ ligador precisa do símbolo _start

@ flag para habilitar interrupções externas no registrador de status
	.set IRQ, 0x80
	.set FIQ, 0x40

@ endereços das pilhar
	.set STACK,     0x80000
	.set STACK_FIQ, 0x72000
	.set STACK_IRQ, 0x70000
	
@ modos de interrupção no registrador de status
	.set IRQ_MODE,0x12
	.set FIQ_MODE,0x11
	.set USER_MODE,0x10
	
@ endereços dos dispositivos
	.set START,0x90000
	.set STOP,0x90001
	.set TIMER,   0x90008
	.set DISPLAY, 0xa0000
@ constantes
	.set BIT_READY,1
	.set INTERVAL,1000

@ vetor de interrupções
	.org  6*4               @ preenche apenas duas posição do vetor, 6 e 7
	b      tratador_timer
	b      tratador_botao
	
	.org 0x200
_start:
	mov	sp,#0x500	@ seta pilha do modo supervisor
	mov	r0,#IRQ_MODE	@ coloca processador no modo IRQ (interrupção externa)
	msr	cpsr,r0		@ processador agora no modo IRQ
	mov	sp,#STACK_IRQ	@ seta pilha de interrupção IRQ
	mov	r0,#FIQ_MODE	@ coloca processador no modo IRQ (interrupção externa)
	msr	cpsr,r0		@ processador agora no modo FIQ
	mov	sp,#STACK_FIQ	@ seta pilha de interrupção FIQ
	mov	r0,#USER_MODE	@ coloca processador no modo usuário
	bic     r0,r0,#(IRQ+FIQ)@ interrupções FIQ e IRQ habilitadas
	msr	cpsr,r0		@ processador agora no modo usuário
	mov	sp,#STACK	@ pilha do usuário no final da memória 

	mov	r3,#0           @ zera mostrador no início
	ldr     r4,=digitos
	ldrb	r0,[r4,r3]      @ padrao de bits para valor
	ldr     r5,=DISPLAY
	strb  	r0,[r5]		@ seta display com zero	
loop:
	ldr     r1,=flag_timer  @ verifica se ocorreu interrupção do timer
	ldr     r0,[r1]
	cmp     r0,#1           @ flag ligada?
	bne     loop0           @ se não, continua
                                @ aqui incrementa e atualiza contador 
	mov     r0,#0
	str     r0,[r1]         @ reseta flag_timer
	ldr     r2,=contador
	ldr     r3,[r2]         @ valor corrente
	add	r3,r3,#1	@ incrementa contador e
	cmp	r3,#10		@ volta a zero se necessario
	moveq	r3,#0
	ldr     r4,=digitos
	ldrb	r0,[r4,r3]      @ padrao de bits para valor
	ldr     r5,=DISPLAY
	strb  	r0,[r5]		@ seta display
	strb    r3,[r2]         @ armazena contador
loop0:	
	ldr     r1,=flag_button @ verifica se ocorreu interrupção do botão
	ldr     r0,[r1]
	cmp     r0,#1           @ flag ligada?
 	bne     loop            @ se não, continua no loop principal
 	mov     r0,#0
 	str     r0,[r1]         @ reseta flag_button
				@ verifica qual botão
	ldr	r1,=START       @ r1 tem endereço botao start
	ldr	r0,[r1]         @ verifica botao start
	cmp	r0,#BIT_READY   @ foi pressionado?
	bne	loop1           @ se nao foi, continua
@ aqui botão start pressionado
	ldr     r3,=TIMER       @ r3 tem endereço timer
	ldr	r4,=INTERVAL
	str  	r4,[r3]		@ seta timer
	b       loop     
loop1:
	ldr	r2,=STOP        @ r2 tem endereço botao stop
	ldr	r0,[r2]         @ verifica botao stop
	cmp	r0,#BIT_READY   @ foi pressionado?
	bne	loop            @ se nao foi, continua
@ aqui botão start pressionado
	ldr     r3,=TIMER       @ r3 tem endereço timer
	mov     r5,#0
	str  	r5,[r3]		@ reseta timer
	b       loop     
	
@ tratadores de interrupcao	
@ aqui quando timer expirou
@ note que o programa prepara a pilha do modo IRQ, mas o
@ tratador não a utiliza (por utilizar apenas registradores
@ não utilizados no corpo do programa).
	.align 4
tratador_timer:
	ldr	r7,=flag_timer	@ apenas liga a flag
	mov	r8,#1
	str	r8,[r7]
	movs	pc,lr		@ e retorna

@ aqui quando um dos botões foi pressionado
@ note que o programa nãrepara a pilha do modo FIQ
@ mas o tratador não a utiliza, no caso, por usar apenas
@ registradores do banco de registradores do modo FIQ. Se o tratador
@ precisasse salvar registradores, por exemplo, seria necessário
@ usar a pilha.
tratador_botao:
	ldr	r7,=flag_button	@ apenas liga a flag
	mov	r8,#1
	str	r8,[r7]
	movs	pc,lr		@ e retorna
	
flag_timer:
     .word 0
flag_button:
     .word 0
contador:
     .word 0
digitos:
     .byte 0x7e,0x30,0x6d,0x79,0x33,0x5b,0x5f,0x70,0x7f,0x7b
