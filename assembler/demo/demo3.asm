macro getStdin: 1
mov $00, &00
mov $01, &01
mov $02, &02

mov &00, 0
mov &01, 0
swi 0
mov %00, &02

mov &00, $00
mov &01, $01
mov &02, $02
endmacro

macro prints: 1
mov $00, &00
mov $01, &01
mov $02, &02
mov $03, &03

getStdin &01
mov &00, 1
mov &02, "s"
mov &03, %00

swi 0

mov &00, $00
mov &01, $01
mov &02, $02
mov &03, $03
endmacro

_main:
mov $32, "H"
mov $33, "e"
mov $34, "l"
mov $35, "l"
mov $36, "l"
mov $37, "o"
mov $38, 10
mov $39, 0

prints 32
