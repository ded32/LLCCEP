_main:
mov &0, 0
mov &1, 1
swi 0

mov &0, 1
mov &1, &2
mov &2, "c"
mov &3, "H"
swi 0
ret
