
.globl _start
_start:
    mov sp, #0x8000
    bl bootmain
hang: b hang




.globl _putw
_putw:
    str r1,[r0]
    bx lr

.globl _getw
_getw:
    ldr r0,[r0]
    bx lr
