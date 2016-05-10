all: generate_lexer build clean

generate_lexer:
	lex *.l
	yacc *.y

build:
	clang lex.yy.c -g -O0 -std=c99 -ll -ly -o parser.out

clean:
	rm -rf *.dSYM
	rm -rf *.c 
