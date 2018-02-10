/*******************************************************
Nom           : couleurs_terminal.h
Auteur        : Mathieu Lacroix
Version       : V1
Date          : 16/11/16
Informations  : Contient la définition de la fonction
                - saisie_avec_espaces
********************************************************/
#include "saisie_avec_espaces.h"


void purger()
{
  int c;
  while ((c = getc(stdin)) != '\n' && c != EOF)
    	;
}


void clean (char *chaine)
{
   char *p = strchr(chaine, '\n');
   if (p)
    *p = 0;
   else
    purger();
}

void saisie_avec_espaces(char * chaine, int n)
{
    fgets(chaine, n, stdin);
    clean(chaine);
}



/****************************
// Exemple d'utilisation de la fonction saisie_avec_espaces.
int main()
{
	char ch1[5];
	printf("Tapez une phrase : \n");
	saisie_avec_espaces(ch1,5);
	printf("Vous avez tape : '%s'\n", ch1);

	printf("Tapez une phrase : \n");
	saisie_avec_espaces(ch1,5);
	printf("Vous avez tape : '%s'\n", ch1);

	printf("Tapez une phrase : \n");
	saisie_avec_espaces(ch1,5);
	printf("Vous avez tape : '%s'\n", ch1);

    return 0;
}

****************************/
