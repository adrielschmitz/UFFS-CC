@ programa que lê e escreve na console 
 
	.global _start      @ ligador necessita deste rótulo

_start:
	/* int write(int fd, const void *buf, size_t count) */
	mov     r0, #1      @ fd -> stdout
	ldr     r1, =msg    @ buf -> msg
	ldr     r2, =len    @ count -> len(msg)
	mov     r7, #4      @ write é syscall #4
	svc     0x055       @ executa syscall 

	/* int read(int fd, const void *buf, size_t count) */

	mov     r0, #0      @ fd -> stdin
	ldr     r1, =buffer @ buf -> buffer
	ldr     r2, =len    @ count -> len(msg)
	mov     r7, #3      @ write é syscall #3
	svc     #0x55       @ executa syscall 
	mov	r2, r0      @ número de bytes a serem lidos
	
	/* int write(int fd, const void *buf, size_t count) */
	mov     r0, #1      @ fd -> stdout
	ldr     r1, =buffer @ buf -> msg
	mov     r7, #4      @ write é syscall #4
	svc     0x55        @ executa syscall 
    
	/* exit(int status) */
	mov     r0, #0      @ status -> 0
	mov     r7, #1      @ exit é syscall #1
	svc     #0x55       @ executa syscall 

msg:
	.ascii   "Hello, ARM!\n"
len = . - msg

@buffer onde serao armazenados os caracteres lidos
buffer:
	.skip	256
 
