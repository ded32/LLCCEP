print:
mov &00, "A"
swi 2
ret

_main:
call @al, print
ret