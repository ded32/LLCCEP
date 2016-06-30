# Opening file
al mov &01, 0  # ptr 2 mem
al mov $0, "o"
al mov $1, "u"
al mov $2, "t"
al mov $3, 0   # '\0'

al mov &00, 1  # writable
al swi 7       # open

# Writing data
al mov &00, &01 # ptr 2 file
al mov &31, 0

al mov $00, "H"
al mov $01, "e"
al mov $02, "l"
al mov $03, "l"
al mov $04, "o"
al mov $05, ","
al mov $06, " "
al mov $07, "w"
al mov $08, "o"
al mov $09, "r"
al mov $10, "l"
al mov $11, "d"
al mov $12, "!"
al mov $13, 10 # '\n'
al inc &31
al cmp &31, 5
le mov &30, 0
le sub &30, 18
le jmp &30

al mov &02, 00  # ptr 2 mem 
al mov &01, 0   # write mode
al swi 10       # write

#Close file
al swi 8
