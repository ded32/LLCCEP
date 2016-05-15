FLAGS:=-g -O0 -std=c++11
OUT:=parser_test.out

all: generate build

generate: SiHi.l SiHi.y
	flex -o SiHi_lexer.cpp SiHi.l
	yacc -o SiHi_parser.hpp SiHi.y

create_ast_static:
	c++ -std=c++11 -I../third-party/ -I../include/ -o ast.o -c ast/ast.cpp
	ar rcs libast.a ast.o
	rm ast.o

build: create_ast_static SiHi_lexer.cpp SiHi_parser.hpp
	c++ -L./ $(FLAGS) -ll -ly -o $(OUT) SiHi_lexer.cpp -last

clean: SiHi_lexer.cpp SiHi_parser.hpp libast.a $(OUT)
	rm -rf $(OUT) SiHi_parser.hpp SiHi_lexer.cpp libast.a $(OUT).dSYM
