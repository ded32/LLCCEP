; Get output surface size
al swi 7              ; Get screen size to 00 and 01 registers
al mov &02, &00       ; Move screen width to 02 register 
al mov &03, &01       ; Move screen heiht to 03 register
al mov &00, 0         ; Set 00 register to 0
al mov &01, 0         ; Set 01 register to 0
; Drawing loop
al cmp &01, &03       ; Compare 01 register to screen height
le mul &01, &00, &00  ; set register 01 to the square of 00 register
le swi 6              ; set {register 00, register 01} pixel to white
le add &00, &00, 0.01 ; make register 00 += 0.01
le mov &14, 5         ; goto compare.
