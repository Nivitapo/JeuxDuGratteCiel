#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <time.h>
#include "couleurs_terminal.h"
#include "saisie_avec_espaces.h"
#include "partie1.h"
#include "partie2.h"
#include "partie3.h"

int main()
{
	srand(time(NULL));
	int n;
	
			
	printf("Veuillez saisir la taille de votre quartier :  \n");
	scanf("%d",&n);
	while(n<2 || n>8)
	{
		printf("Veuillez saisir a nouveau taille de votre quartier :  \n");
		scanf("%d",&n);
	}
	Gratte_ciel * p=creer_gratte_ciel_aleatoire(n);
	affichage_gratte_ciel(p);
	jouer(p,n);
	detruire_gratte_ciel(p);

	return 0;
}
