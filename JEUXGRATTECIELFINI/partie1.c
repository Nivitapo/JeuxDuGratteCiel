#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h> 
#include "couleurs_terminal.h"
#include "partie1.h"

										///////////////////////////////
										///////////Exercie 2///////////
										///////////////////////////////

/*! 
* Fonction allouant dynamiquement un Gratte_ciel dnt l'adresse est retourner
* param n : nombre d'immeuble par ligne et par colonne dans le quartier
*/


Gratte_ciel *creer_gratte_ciel(int nb)
{

    Gratte_ciel *x;

    if (nb < 2 || nb > 8) {
	return x = NULL;	//on prend la valeur null si le chiffre passé  en                                                                                                                      param != entre 2 et 8 inclus
	exit(0);		//arrêt du processus si l'allocation échoue
    }

    else {
	x = malloc(sizeof(int) * 3);	//on alloue une place pour la structure de 3int
	x->grille = malloc(sizeof(int) * ((nb + 2) * (nb + 2)));	//x pointant sur l'allocation de la grille
    }

    int i = 0;			//Initialisation de i

    while (i < (nb + 2) * (nb + 2)) {
	x->grille[i] = 0;	//on initialise la valeur de toutes les cases à 0
	i++;
    }

    x->n = nb;			//x pointant sur l'entier n qui prend la valeur                                                                                                                 entrée en paramètre nb
    x->nb_cases_libres = (nb * nb);	//x pointant sur l'entier nb_cases_libres qui                                                                                                                   prend la valeur de la grille (sans les bordures)
    return x;			//on retourne l'adresse du gratte-ciel
}

										///////////////////////////////
										///////////Exercie 3///////////
										///////////////////////////////
/*!
* Fonction désallouant dynamiquement la mémoire utilisée par le gratte-ciel passé en paramètre
* \param p : pointeur sur le gratte-ciel à désallouer
*/

void detruire_gratte_ciel(Gratte_ciel * p)
{
    if (p != NULL)		//Si l'adresse est différent de "Null"
    {
	free(p->grille);	//libération de l'espace de la grille (désallouer)
	free(p);		//libération de l'esapace du pointeur sur le gratte-ciel (désallouer)
    }
}


										///////////////////////////////
										///////////Exercie 4///////////
										///////////////////////////////
/*!
* Fonction retournant 1 si i correspond à un indice valide pour la grille du gratte-ciel
* passé en paramètre, et 0 sinon
*
* \param p : pointeur sur un gratte-ciel
* \param i : indice à tester
*/

int indice_grille_valide(Gratte_ciel * p, int i)
{
    if (i >= 0 && i <= (p->n + 1))	/*On retourne 1 quand l'indice est compris entre 0 et n+1 inclus = valide */
	return 1;

    else
	return 0;		/*A l'inverse on retourne 0 */
}


										///////////////////////////////
										///////////Exercie 5///////////
										///////////////////////////////
/*!
* Fonction retournant la valeur de la case (i,j) de la grille du gratte-ciel p.
* Si la case (i,j) n’existe pas, la fonction renvoie -1.
*
* \param p : pointeur sur un gratte-ciel
* \param i : entier correspondant au numéro de ligne
* \param j : entier correspondant au numéro de colonne
*/
int get_case(Gratte_ciel * p, int i, int j)	// !Ne pas oublier! : i = ligne ; j = colonne
{
    if (i >= 0 && i < p->n + 2 && j >= 0 && j < p->n + 2)	//(si on sort pas de la grille) 
	return (p->grille[i * (p->n + 2) + j]);	/*retourne la valeur de la case */

    else
	return -1;		//sinon retourne -1 si on est en dehors de la                                                                                                                   grille
}


										///////////////////////////////
										///////////Exercie 6///////////
										///////////////////////////////
/*
* Fonction modifiant la valeur de la case (i,j) de la grille du gratte-ciel p
*
* \param p : pointeur sur un gratte-ciel
* \param i : entier correspondant au numéro de ligne
* \param j : entier correspondant au numéro de colonne
* \param valeur : valeur que l’on souhaite mettre dans la case (i,j)
*/
int set_case(Gratte_ciel * p, int i, int j, int val)
{
    if (get_case(p, i, j) != -1)	//si le resulat de la fonction est differente de -1 
    {
	if ((val >= 0) && (val <= (p->n)))	//contrôle de la valeur 0 et n inclus
	{
	    if (i >= 1 && i < p->n + 1 && j >= 1 && j < p->n + 1
		&& p->grille[i * (p->n + 2) + j] != 0 && val == 0)
		//on n'evite de sortir de la grille,et on s'assure que la valeur de la case est differente de 0 et si val entré en parametre = 0 et du coup liberation d'une case ;
		p->nb_cases_libres++;

	    if (i >= 1 && i < p->n + 1 && j >= 1 && j < p->n + 1
		&& p->grille[i * (p->n + 2) + j] == 0 && val != 0)
		p->nb_cases_libres--;	// a l'inverse si la valeur de la case est = 0 et que val est differente de 0 alors occupation d'une case en plus;
	    p->grille[i * (p->n + 2) + j] = val;	// la case de la grille prend la valeur de val passé en parametre;
	    return 1;
	}
    }
    return 0;

}

										///////////////////////////////
										///////////Exercie 7///////////
										///////////////////////////////
/*!
* Fontion retournant le nombre de cases libres du gratte-ciel passé en paramètre
*
*\param p : pointeur sur le gratte-ciel
*/


int get_nb_cases_libres(Gratte_ciel * p)
{
    return p->nb_cases_libres;	// on retourne le nb de case libres
}


										///////////////////////////////
										///////////Exercie 8///////////
										///////////////////////////////
/*!
* Fonction affichant la grille sur le terminal
*
* \param p : pointeur sur le gratte-ciel que l’on souhaite afficher
*/

int affichage_indice_horizontal(Gratte_ciel * p,int cases)
{
	int i=0;
		////LIGNE 1///
	printf("   ");
	printf("           ");
	printf("     ");
	while(i<p->n)
	{
		color_printf(WHITE,RED,"                 ");
		printf("     ");
		i++;
	}
	printf("           ");
	printf("\n");
		////LIGNE 2///
	i=0;
	printf("   ");
	printf("           ");
	cases++;
	printf("     ");
	while(i<p->n)
	{
		if(p->grille[cases]==0)
		{
			color_printf(WHITE,RED,"                 ");
			printf("     ");
		}
		else
		{
			color_printf(WHITE,RED,"        %d        ",p->grille[cases]);
			printf("     ");
		}
		cases++;
		i++;
	}
	printf("           ");
	cases++;
	printf("\n");
		////LIGNE 3///
	i=0;
	printf("   ");
	printf("           ");
	printf("     ");
	while(i<p->n)
	{
		color_printf(WHITE,RED,"                 ");
		printf("     ");
		i++;
	}
	printf("           ");
	printf("\n");
	
	return cases;
}	

int affichage_ligne_milieu(Gratte_ciel * p,int cases,int ligne)
{
	int i,line;
	char *coord="A";
		////2 PREMIERES LIGNES///
	for(line=0;line<2;line++)
	{
		printf("   ");
		i=0;
		color_printf(WHITE,RED,"           ");
		printf("     ");
		while(i<p->n)
		{
			color_printf(YELLOW,BLUE,"                 ");
			printf("     ");
			i++;
		}
		color_printf(WHITE,RED,"           ");
		printf("\n");
	}
		////LIGNE 2///
	i=0;
	printf("%c  ",*coord+ligne);
	if(p->grille[cases]==0)
		color_printf(WHITE,RED,"           ");
	else
		color_printf(WHITE,RED,"     %d     ",p->grille[cases]);
	cases++;
	printf("     ");
	while(i<p->n)
	{
		if(p->grille[cases]==0)
		{
			color_printf(YELLOW,BLUE,"                 ");
			printf("     ");
		}
		else
		{
			color_printf(YELLOW,BLUE,"        %d       ",p->grille[cases]*10);
			printf("     ");
		}
		cases++;
		i++;
	}
	if(p->grille[cases]==0)
		color_printf(WHITE,RED,"           ");
	else
		color_printf(WHITE,RED,"     %d     ",p->grille[cases]);
	cases++;
	printf("\n");
		////2 DERNIERES LIGNES///
	for(line=0;line<2;line++)
	{
		i=0;
		printf("   ");
		color_printf(WHITE,RED,"           ");
		printf("     ");
		while(i<p->n)
		{
			color_printf(YELLOW,BLUE,"                 ");
			printf("     ");
			i++;
		}
		color_printf(WHITE,RED,"           ");
		printf("\n");
	}
	return cases;
}	

void transition()
{
	printf("\n");
}

void coord_horizontale(Gratte_ciel * p)
{
	int i=0;
	printf("                   ");
	while(i<p->n)
	{
		printf("     %d                ",i+1);
		i++;
	}
	printf("\n");
	
}

void affichage_gratte_ciel (Gratte_ciel *p)
{
		int cases=0,i=0,ligne=0;
		printf("   ");
		coord_horizontale(p);
		cases=affichage_indice_horizontal(p,cases);
		while(i<p->n)
		{
			transition();
			cases=affichage_ligne_milieu(p,cases,ligne);
			ligne++;
			i++;
		}
		transition();
		affichage_indice_horizontal(p,cases);
		printf ("\n\n");
}

