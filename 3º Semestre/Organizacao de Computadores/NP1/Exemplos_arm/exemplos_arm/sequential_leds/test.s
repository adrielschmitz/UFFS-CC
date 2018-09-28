@ luzes sequenciais, sem uso do timer

	.global _start          @ ligador precisa deste rótulo
	
@ endereço painel de leds
        .set LEDSADDR,0x90000
        .set INTERVAL,0x7ffff
        
_start:
        mov     r0,#1           @ inicializa contador para leds
        ldr     r2,=LEDSADDR    @ escreve valor corrente do contador no
        str     r0,[r2]         @ painel de leds
        mov     r3,#1           @ r3 tem padrão de bits, inicia com 1
        mov     r4,#1           @ r4 tem direção (direita=0 ou esquerda=1)
        ldr     r1,=INTERVAL    @ inicializa contador de tempo
loop:
        subs    r1,#1           @ espera contador de tempo zerar
        bne     loop
                                @ aqui quando contador expirou
        ldr     r1,=INTERVAL    @ reinicializa contador de tempo
        strb    r3,[r2]         @ escreve o padrão de bits em r3 nos leds
        cmp     r4,#0           @ verifica direção do deslocamento
        movne   r3,r3,lsl#1     @ desloca para esquerda se r4=1
        moveq   r3,r3,lsr#1     @ desloca para a direita se r4=0
        tst     r3,#0x100       @ valor corrente muito à esquerda?
        movne   r4,#0           @ começa a deslocar para a direita
        movne   r3,#0x40        @ próximo valor para leds
        cmp     r3,#0           @ deslocou bit 1 para fora?
        moveq   r4,#1           @ começa a deslocar para a esquerda
        moveq   r3,#2           @ próximo valor para leds
        b       loop            @ e volta no loop
