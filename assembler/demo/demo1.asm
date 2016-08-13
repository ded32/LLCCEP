print:
mov &00, "a"    ; &00 := 'a'
swi 5           ; print &00
ret             ; exit subroutine

_main:          ; entry point
call @al, print ; call to function, prints 'a'
ret             ; exit program