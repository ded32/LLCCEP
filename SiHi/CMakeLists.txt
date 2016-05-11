cmake_minimum_required(VERSION 2.6)
project(SiHi_parser_unit_test)

add_custom_target(SiHi_lexer "Generating main lexer module due flex...")
add_custom_target(SiHi_parser "Generating main parser module due yacc...")

add_custom_command(
	SOURCE ./SiHi.l
	COMMAND ${FLEX_EXECUTABLE}
	ARGS -o ./SiHi.lex.c
	TARGET SiHi_lexer
	OUTPUTS ./SiHi.lex.c
)

add_custom_command(
	SOURCE ./SiHi.y
	COMMAND ${BISON_EXECUTABLE}
	ARGS -y ./SiHi.y -o ./SiHi.tab.h
	TARGET SiHi_parser
	OUTPUTS ./SiHi.tab.h
	DEPENDS ./SiHi.lex.c
)


