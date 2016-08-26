macro getStdout: 1
stregs

mov &00, 0
mov &01, 1
swi 0

mov %00, &02

ldregs
endmacro

macro prints: 1
stregs

mov &00, 1
getStdout $03
mov &01, $03
mov &02, "s"
mov &03, %00
swi 0

ldregs
endmacro

_main:
mov $00, "a"
mov $01, 0

prints 0
