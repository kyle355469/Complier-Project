##################################################################
#
# Makefile -- P Parser
#
##################################################################
p: lex.yy.o y.tab.o table.o
	gcc -o p lex.yy.o y.tab.o table.o -ll

lex.yy.o: lex.yy.c y.tab.h 
	gcc -c -g lex.yy.c

y.tab.o: y.tab.c y.tab.h table.h
	gcc -c -g y.tab.c

lex.yy.c: test.l y.tab.h table.h
	lex test.l

y.tab.c: p.y table.h
	yacc -t -v -d p.y

y.tab.h: p.y table.h
	yacc -t -v -d p.y


table.o: table.c table.h
	gcc -c -g table.c

clean:
	rm -f p *.o lex.yy.c y.tab.c