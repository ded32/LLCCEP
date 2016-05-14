FLAGS:=-g -O0 -std=c99
OUT:=parser_test.out

all: generate build

generate: SiHi.l SiHi.y
	flex -o SiHi_lexer.c SiHi.l
	yacc -o SiHi_parser.h SiHi.y

build: SiHi_lexer.c SiHi_parser.h
	cc $(FLAGS) -ll -ly -o $(OUT) SiHi_lexer.c

clean: SiHi_lexer.c SiHi_parser.h $(OUT)
	rm -rf $(OUT) SiHi_parser.h SiHi_lexer.c rm $(OUT).dSYM
