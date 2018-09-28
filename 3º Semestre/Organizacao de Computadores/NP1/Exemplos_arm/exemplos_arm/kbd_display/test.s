@ programa que usa um teclado e um mostrador de sete segmentos

	.global _start          @ ligador necessita deste rótulo

@enderecos de dispositivos
	.set DISPLAY,    0x90000
	.set KBD_DATA,   0x90010
	.set KBD_STATUS, 0x90011
@ constantes
	.set KBD_READY,  0x1
	.set KBD_OVRN,   0x2

_start:
	ldr	r1,=KBD_STATUS
le_tecla1:
	ldr	r2,[r1]
	tst     r2,#KBD_READY
	beq     le_tecla1
	ldr	r1,=KBD_DATA
	ldr	r3,[r1]
	ldr	r2,=DISPLAY	@ r2 tem porta display
	ldr	r4,=digitos
	ldrb	r0,[r4,r3]      @ padrao de bits para valor da tecla
	strb  	r0,[r2]		@ seta valor no display
	b	_start

digitos:
     .byte 0x7e,0x30,0x6d,0x79,0x33,0x5b,0x5f,0x70,0x7f,0x7b,0x4f,0x4f
