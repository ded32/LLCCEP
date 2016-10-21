macro getStdout: 1
mov &00, 0
mov &01, 1
swi 0

mov %00, &02
endmacro

macro prints: 1
getStdout &01
mov &02, "s"
mov &03, %00
swi 0
endmacro

_main:
mov $00, "H"
mov $01, "e"
mov $02, "l"
mov $03, "l"
mov $04, "o"
mov $05, ","
mov $06, " "
mov $07, "w"
mov $08, "o"
mov $09, "r"
mov $10, "l"
mov $11, "d"
mov $12, "!"
mov $13, 10
mov $14, 0

prints 0
