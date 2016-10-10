_main:
mov &00, 0
mov &01, 1
swi 0
mov &00, 1
push &02
top &01
pop
mov &02, "c"
mov &03, "H"
swi 0
