@ pisca um led, sem uso do timer

	.global  _start         @ ligador precisa deste rótulo
	
@ endereço painel de leds
	.set LEDSADDR,0x90000
@ intervalo (tempo) para ligar/desligar o led
	.set INTERVAL,0x7fffff
	
_start:
	mov	r0,#1           @ inicializa contador para leds
	ldr	r2,=LEDSADDR	@ escreve valor corrente do contador no
	str	r0,[r2]		@ painel de leds
	ldr	r1,=INTERVAL    @ inicializa contador de tempo
loop:
	subs	r1,#1		@ espera contador de tempo zerar
	bne	loop
				@ aqui quando tempo expirou
	ldr	r1,=INTERVAL    @ reinicializa contador de tempo
	add	r0,#1		@ conta
	str	r0,[r2]		@ painel de leds
	b 	loop


