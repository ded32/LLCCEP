al mov &00, 0
al cmp &01, 800 
le mul &01, &00, &00
le swi 8
le inc &01
le mov &14, 1
