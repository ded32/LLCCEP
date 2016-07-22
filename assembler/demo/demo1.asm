call @al, print
swi 5

print:
mov &00, "A"
swi 2
ret
