@ Exemplo de uso do dispositivo LCD
@ compatível com controlador HITACHI HD44780

	.global _start  @ ligador necessita deste rótulo
	
@ constantes para "commands"
        .set LCD_CLEARDISPLAY,0x01
        .set LCD_RETURNHOME,0x02
        .set LCD_ENTRYMODESET,0x04
        .set LCD_DISPLAYCONTROL,0x08
        .set LCD_CURSORSHIFT,0x10
        .set LCD_FUNCTIONSET,0x20
        .set LCD_SETCGRAMADDR,0x40
        .set LCD_SETDDRAMADDR,0x80
        .set LCD_BUSYFLAG,0x80
	
@ constantes para "display entry mode"
        .set LCD_ENTRYRIGHT,0x00
        .set LCD_ENTRYLEFT,0x02
        .set LCD_ENTRYSHIFTINCREMENT,0x01
        .set LCD_ENTRYSHIFTDECREMENT,0x00

@ constantes para "display on/off control"
        .set LCD_DISPLAYON,0x04
        .set LCD_DISPLAYOFF,0x00
        .set LCD_CURSORON,0x02
        .set LCD_CURSOROFF,0x00
        .set LCD_BLINKON,0x01
        .set LCD_BLINKOFF,0x00

@ constantes para "display/cursor shift"
        .set LCD_DISPLAYMOVE,0x08
        .set LCD_CURSORMOVE,0x00
        .set LCD_MOVERIGHT,0x04
        .set LCD_MOVELEFT,0x00
	
@ constantes para "function set"
        .set LCD_8BITMODE,0x10
        .set LCD_4BITMODE,0x00
        .set LCD_2LINE,0x08
        .set LCD_1LINE,0x00
        .set LCD_5x10DOTS,0x04
        .set LCD_5x8DOTS,0x00

@ modos de interrupção no registrador de status
	.set IRQ_MODE,0x12
	.set USER_MODE,0x10

@ flag para habilitar interrupções externas no registrador de status
	.set IRQ,0x80

@ enderecos dispositivos
	.set ADISPLAY_DAT,0x90001
	.set ADISPLAY_CMD,0x90000
	.set TIMER,       0x90008
@ constantes
	.set INTERVAL,100

@ vetor de interrupções
	.org  7*4               @ preenche apenas uma posição do vetor,
	                        @ correspondente ao tipo 7
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
	mov	sp,#0x10000	@ pilha do usuário no final da memória 

	mov	r0,#LCD_FUNCTIONSET+LCD_8BITMODE+LCD_2LINE+LCD_5x8DOTS
	                        @ r0 tem comando
	bl      wr_cmd		@ escreve comando no display

	mov	r0,#LCD_CLEARDISPLAY
	                        @ r0 tem comando: clear display
	bl      wr_cmd		@ escreve comando no display

	mov	r0,#LCD_RETURNHOME
	                        @ r0 tem comando: cursor home
	bl      wr_cmd		@ escreve comando no display

	mov	r0,#LCD_DISPLAYCONTROL+LCD_DISPLAYON+LCD_BLINKOFF
	                        @ r0 tem comando
	bl      wr_cmd		@ escreve comando no display
	
        ldr     r1, =msg        @ escreve mensagem no display, primeira linha 
	bl      write_msg

	mov	r0,#(LCD_SETDDRAMADDR+64)
	                        @ r0 tem comando: endereço inicio da segunda linha
	                        @ para 16x2 e 20x2:
	                        @   primeira linha: 0..39 (0x00..0x27)
	                        @   segunda linha: 64..103 (0x40..0x67)
	                        @ para 20x4:
	                        @   primeira linha: 0..19 (0x00..0x13)
	                        @   segunda linha:64..83 (0x40..0x53)
	                        @   terceira linha: 20..39 (0x14..0x27)
	                        @   quarta linha:  84..103 (0x54..0x67)

	bl      wr_cmd		@ escreve comando no display
        ldr     r1, =msg2       @ escreve mensagem no display, segunda linha
	bl      write_msg

	ldr	r0,=INTERVAL
	ldr	r6,=TIMER
	str  	r0,[r6]		@ seta timer

	
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ loop principal
@ faz shift a cada tick to timer
loop:
	ldr	r1,=flag        @ timer escreve 1 em flag quando tick
	ldr	r0,[r1]         @ lê flag
	cmp	r0,#0
	beq	loop
	mov	r0,#0		@ reseta flag
	str	r0,[r1]

	mov	r0,#0x1c
	mov	r0,#LCD_CURSORSHIFT+LCD_DISPLAYMOVE+LCD_MOVERIGHT
	                        @ r0 tem comando
	bl      wr_cmd		@ escreve comando no display
	b       loop

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ wr_cmd
@ escreve comando em r0 no display
wr_cmd:
	ldr	r6,=ADISPLAY_CMD @ r6 tem porta display
	ldrb	r5,[r6]
	tst     r5,#LCD_BUSYFLAG
	beq	wr_cmd           @ espera BF ser 1
	strb	r0,[r6]
	mov	pc,lr

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ wr_dat
@ escreve dado em r0 no display
wr_dat:
	ldr	r6,=ADISPLAY_CMD @ r6 tem porta display
	ldrb	r5,[r6]          @ lê flag BF
	tst     r5,#LCD_BUSYFLAG
	beq	wr_dat           @ espera BF ser 1
	ldr	r6,=ADISPLAY_DAT @ r6 tem porta display
	strb	r0,[r6]
	mov	pc,lr

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ write_msg
@ escreve cadeia de caracteres apontada por r1, terminada com caractere nulo
write_msg:
	push    {lr}	
	mov	r4, #0     @ endereço inicial
write_msg1:
	ldrb    r0,[r1,r4] @ caractere a ser escrito
	teq	r0,#0
	popeq   {pc}       @ final da cadeia
	bl      wr_dat     @ escreve caractere
	add     r1,#1      @ avança contador
	b       write_msg1

flag:
     .word 0
msg:
@    .asciz      "Hello, ARM!"
    .asciz      "Bom dia, ARM!"
msg2:
@    .asciz      "I am alive!"
    .asciz      "Eu sou azul."

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ tratador da interrupcao	
@ aqui quando timer expirou
	.align 4
tratador_timer:
	ldr	r7,=flag	@ apenas liga a flag
	mov	r8,#1
	str	r8,[r7]
	movs	pc,lr		@ e retorna
