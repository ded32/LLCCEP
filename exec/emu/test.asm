al mov &01, 0 ; Ptr 2 mem
al mov $0, "o" ; 'o'
al mov $1, "u" ; 'u'
al mov $2, "t" ; 't'
al mov $3, 0   ; '\0'

al mov &00, 1 ; write

al swi 7 ; open file

al mov &00, &01
al mov &02, "a" ; 'a'
al mov &01, 0  ; write
al swi 9
al swi 8
