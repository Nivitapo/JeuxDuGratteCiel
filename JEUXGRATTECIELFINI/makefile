exe : couleurs_terminal.o saisie_avec_espaces.o partie1.o partie2.o partie3.o principal.o
	gcc -o exe -Wall couleurs_terminal.o saisie_avec_espaces.o partie1.o partie2.o partie3.o principal.o

principal.o : principal.c couleurs_terminal.h saisie_avec_espaces.h partie1.h partie2.h partie3.h 
	gcc -Wall -c principal.c

couleurs_terminal.o : couleurs_terminal.c
	gcc -Wall -c couleurs_terminal.c

saisie_avec_espaces.o : saisie_avec_espaces.c
	gcc -Wall -c saisie_avec_espaces.c

partie1.o : partie1.c
	gcc -Wall -c partie1.c

partie2.o : partie2.c
	gcc -Wall -c partie2.c

partie3.o : partie3.c
	gcc -Wall -c partie3.c






