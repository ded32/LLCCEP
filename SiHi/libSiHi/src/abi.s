macro __operator_index_array__, 0
    stregs

    top &00
    pop
    top &01
    pop
    top &02
    pop

    mul &01, &01, &02
    add &00, &00, &01

    push &00

    ldregs
endmacro

macro __operator_call_function_pointer__, 0
    stregs

    top &00
    pop

    call &00

    ldregs
endmacro

macro __operator_dot_class__, 0
    stregs

    top &00
    pop

    top &01
    pop

    add &00, &00, &01
    push &00

    ldregs
endmacro

macro __operator_arrow_class_ptr__, 0
    stregs

    top &00
    pop

    mav &00, &00

    top &01
    pop

    add &00, &00, &01
    push &00

    ldregs
endmacro


