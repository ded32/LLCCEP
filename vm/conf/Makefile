FLAGS:=-std=gnu99 -I../../include/ -g -O0
all: build

build_static:
	cc -c $(FLAGS) -o section.o section.c
	ar rcs libsection.a section.o
	rm section.o
	cc -c $(FLAGS) -o list.o ../../lib/list.c
	ar rcs liblist.a list.o
	rm list.o

build: build_static
	lex -o lexer.h vm_conf.l
	yacc -o parser.h vm_conf.y
	cc $(FLAGS) -L./ -o test.out test.c -ly -ll -lsection -llist

clean:
	rm test.out *.a lexer.h parser.h
