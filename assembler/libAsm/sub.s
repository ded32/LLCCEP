macro __builtin_operator_sub__, 1
    sub &31, &31, %00
endmacro
 
macro __operator_real_sub__, 2
    mov &31, %00
    __builtin_operator_sub__ %01
endmacro

macro __operator_pointer_sub__, 2
    mov &31, %00
    __builtin_operator_sub__ %01
endmacro
