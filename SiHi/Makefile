build_lexer_debug: SiHi.l
	lex -o SiHi_lexer.c SiHi.l
	cc -std=gnu11 -g -O0 -o SiHi_lexer.o SiHi_lexer.c -ll -ly

clean:
	rm -rf SiHi_lexer.c SiHi_lexer.o
