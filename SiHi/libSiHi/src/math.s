macro __builtInOperator_inc__, 0
    stregs
   
    top &00
    pop

    inc &00
    push &00

    ldregs
endmacro

macro __builtInOperator_dec__, 0
    stregs

    top &00
    pop

    dec &00
    push &00

    ldregs
endmacro

macro __builtInOperator_add__, 0
   stregs

   top &00
   pop
   top &01
   pop

   add &01, &01, &00
   push &01

   ldregs
endmacro

macro __builtInOperator_sub__, 0
   stregs

   top &00
   pop
   top &01
   pop

   sub &01, &01, &00
   push &01

   ldregs
endmacro

macro __builtInOperator_mul__, 0
   stregs

   top &00
   pop
   top &01
   pop

   mul &01, &01, &00
   push &01

   ldregs
endmacro

macro __builtInOperator_div__, 0
   stregs

   top &00
   pop
   top &01
   pop

   div &01, &01, &00
   push &01

   ldregs
endmacro

