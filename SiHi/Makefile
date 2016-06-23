CUSTOM:=-I./../include/ -I./../../DotViz/ -L./../../DotViz/ -L./
FLAGS:=-g -O0 -std=gnu++11 -Wall $(CUSTOM)

all: synthese_flex_bison build_static_libraries build

synthese_flex_bison: SiHi.l SiHi.y
	flex -o SiHi_lexer.cpp SiHi.l
	yacc -o SiHi_parser.hpp SiHi.y

build_static_libraries: build_ast_static build_dump_static build_stdx_static

build_ast_static: ast/ast.hpp ast/ast.cpp
	g++ $(FLAGS) -c ast/ast.cpp -o ast.o
	libtool -static -o libast.a ast.o

build_dump_static: ast/dump.hpp ast/dump.cpp
	g++ $(FLAGS) -c ast/dump.cpp -o dump.o -lDotViz++
	libtool -static -o libdump.a dump.o

build_stdx_static: ../include/STDExtras.hpp ../lib/STDExtras.cpp
	g++ $(FLAGS) -c ../lib/STDExtras.cpp -o STDExtras.o
	libtool -static -o libSTDExtras.a STDExtras.o

build:
	g++ $(FLAGS) SiHi_lexer.cpp -o SiHi_lexer.out -last -ldump -lDotViz++

clean: 
	rm -rf *.dSYM *.a *.out *.o SiHi_lexer.cpp SiHi_parser.hpp
