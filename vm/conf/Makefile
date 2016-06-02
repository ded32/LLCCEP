FLAGS:=-c -std=c11 -I../../include/
all: build

build_static:
	cc $(FLAGS) -o section.o section.c
	ar rcs libsection.a section.o
	rm section.o
	cc $(FLAGS) -o list.o ../../lib/list.c
	ar rcs liblist.a list.o
	rm list.o

build: build_static
	lex -o lexer.c vm_conf.l
	yacc -o parser.h vm_conf.y
	cc -std=c11 -I../../include -L./ -o test.out lexer.c -ly -lsection -llist

clean:
	rm  *.a lexer.c parser.h test.out
