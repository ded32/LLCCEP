macro __builtin_operator_add__, 1
    add &31, &31, %00
endmacro

macro __operator_real_add__, 2
    mov &31, %00
    __builtin_operator_add__ %01
endmacro

macro __operator_pointer_add__, 2
    mov &31, %00
    __builtin_operator_add__ %01
endmacro
