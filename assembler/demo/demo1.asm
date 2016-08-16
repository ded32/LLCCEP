print:
    mov &00, 0
    mov &01, 1
    swi 0
    mov &01, &02
    top &02
    pop
    top &03
    pop
    mov &00, 1
    swi 0
    ret

_main:
    push -40.54
    push "n"
    call @al, print
    push 10
    push "c"
    call @al, print
    ret