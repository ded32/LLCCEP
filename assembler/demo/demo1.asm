call @al, print
mov &00, 0
swi 2
swi 0

print:
mov $00, "H" ; H
mov $01, "e" ; e
mov $02, "l" ; l
mov $03, "l" ; l
mov $04, "o" ; o
mov $05, "," ; ,
mov $06, " " ; SP
mov $07, "w" ; w
mov $08, "o" ; o
mov $09, "r" ; r
mov $10, "l" ; l
mov $11, "d" ; d
mov $12, "!" ; !
mov $13, 10  ; \n
mov $14, 0   ; \0
ret
