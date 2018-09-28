@ incrementa contador binário com leds, usando um botão

	.global _start     @ ligador necessita deste rótulo
	
@ modos de interrupção no registrador de status
	.equ IRQ_MODE,0x12
	.equ USER_MODE,0x10

@ flag para habilitar interrupções externas no registrador de status
	.equ IRQ, 0x80
        
@ endereços dos dispositivos
	.equ BOTAO,0x90030
	.equ LEDS, 0x90050
@ constantes
	.equ BIT_READY,1
	.equ MAX_COUNT,16
        
@ vetor de interrupções
	.org  0               @ em caso de reset,
	b     _start          @ vai para inicio
	.org  6*4             @ interrupção de tipo 6 (IRQ)
	b     trata_botao     @ rotina de interrupção

	.org 0x400
_start:
	mov   sp,#0x400       @ seta pilha do modo supervisor
	mov   r0,#IRQ_MODE    @ coloca processador no modo IRQ   
	msr   cpsr,r0         @ processador agora no modo IRQ
	mov   sp,#0x300       @ seta pilha de interrupção IRQ
	mov   r0,#USER_MODE   @ coloca processador no modo usuário
	bic   r0,r0,#IRQ      @ habilita interrupções IRQ 
	msr   cpsr,r0         @ processador agora no modo usuário
	mov   sp,#0x40000     @ pilha do usuário no final da memória 

	ldr   r1,=click       @ r1 tem endereço da variável click 
	ldr   r2,=LEDS        @ r2 tem porta painel leds
	mov   r3,#0           @ r3 tem contador, no inicio é 0
atualiza:     
	str   r3,[r2]         @ escreve valor de contador nos leds
	mov   r0,#0   
	str   r0,[r1]         @ zera indicador de click
loop:
	ldr   r0,[r1]         @ verifica variável click
	cmp   r0,#1           @ botão foi pressionado?
	bne   loop            @ se não foi, continua
                              @ aqui trata botão pressionado
	add   r3,#1           @ incrementa contador
	cmp   r3,#MAX_COUNT   @ se excedeu valor máximo
	moveq r3,#0           @ volta contador a zero 
	b     atualiza        @ e atualiza leds

click:
	.word 0

@ tratador da interrupção
trata_botao:
	push  {r0,r1}         @ salva registradores usados
	ldr   r1,=click       @ apenas liga a variável click
	mov   r0,#1           @ indicando que botão foi 
	str   r0,[r1]         @ pressionado
	pop   {r0,r1}         @ restaura registradores
	movs  pc,lr           @ e retorna
