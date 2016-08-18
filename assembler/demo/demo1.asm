_createWindow:
    mov $00, &00
    mov $01, &01
    mov $02, &02
    mov $03, &03
    mov $04, &04
    mov $05, &05

    top &04
    pop
    top &03
    pop
    top &02
    pop
    top &01
    pop
    mov &00, 0
    swi 1

    push &05

    mov &00, $00
    mov &01, $01
    mov &02, $02
    mov &03, $03
    mov &04, $04
    mov &05, $05
    ret

_drawPoint:
    mov $00, &00
    mov $01, &01
    mov $02, &02

    top &02
    pop
    top &01
    pop

    mov &00, 1
    swi 1

    mov &00, $00
    mov &01, $01
    mov &02, $02
    ret
   
_main:
    mov $32, "T"
    mov $33, "e"
    mov $34, "s"
    mov $35, "t"
    mov $36, " "
    mov $37, "w"
    mov $38, "i"
    mov $39, "n"
    mov $40, "d"
    mov $41, "o"
    mov $42, "w"
    mov $43, 0

    push 800
    push 640
    push 32
    push 0

    call @al, _createWindow
    top &01
    pop

_drawingLoop:
    mul &08, &07, &07
    cmp &08, 640
    jmp @ae, _drawingLoopLeave
    push &07
    push &08
    call @al, _drawPoint
    inc &07
    jmp @al, _drawingLoop

_drawingLoopLeave:
