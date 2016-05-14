FLAGS:=-g -O0 -std=c99
OUT:=parser_test.out

all: generate build

generate: SiHi.l SiHi.y
	flex -o SiHi_lexer.cpp SiHi.l
	yacc -o SiHi_parser.hpp SiHi.y

build: SiHi_lexer.cpp SiHi_parser.hpp
	c++ $(FLAGS) -ll -ly -o $(OUT) SiHi_lexer.c

clean: SiHi_lexer.cpp SiHi_parser.hpp $(OUT)
	rm -rf $(OUT) SiHi_parser.hpp SiHi_lexer.cpp $(OUT).dSYM
