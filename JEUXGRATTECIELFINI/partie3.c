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

///////////////////////////////////////////////////////////////////PARTIE 3 ://////////////////////////////////////////////////////////



/*!
* Fonction permutant les lignes i et j dans la grille si i et j correspondent à des indices
* différents de lignes du quartier.
*
* \param p : pointeur sur gratte-ciel
* \param i : indice de ligne
* \param j : indice de ligne
*/
void permute_lignes(Gratte_ciel * p, int i, int j) 
{


		if (indice_grille_valide(p,i)==1 && indice_grille_valide(p,j)==1 && i!=j)
	{

	int tmp[p->n];
	int colonne=1;
		int a=0;
		while(a<(p->n))
		{
			tmp[a]=get_case(p,i,colonne);
			colonne++;
			a++;
		}
		colonne=1;
		int m=0;
		while(m<(p->n))
		{

		 int test1=set_case(p,i,colonne,get_case(p,j,colonne));
		if(test1!=1)
		
		printf("SetCase mauvais");
		
		
		colonne++;
		m++;
		}
		colonne=1;
		int z=0;
		while(z<p->n)
		{
		
		int test2=set_case(p,j,colonne,tmp[z]);
		if(test2!=1)
		printf("SetCase mauvais");
		

		
		colonne++;
		z++;
		}


	}





 }


/*!
* Fonction permutant les colonnes i et j dans la grille si i et j correspondent à des indices
* différents de colonnes du quartier.
*
* \param p : pointeur sur gratte-ciel
* \param i : indice de colonne
* \param j : indice de colonne
*/
void permute_colonnes(Gratte_ciel * p, int i, int j) { 

	if (indice_grille_valide(p,i)==1 && indice_grille_valide(p,j)==1 && i!=j)
	{

	int tmp[p->n];
	int ligne=1;
		int a=0;
		while(a<(p->n))
		{
			tmp[a]=get_case(p,ligne,i);
			ligne++;
			a++;
		}
		ligne=1;
		int m=0;
		while(m<(p->n))
		{

		 int test1=set_case(p,ligne,i,get_case(p,ligne,j));
		if(test1!=1)
		printf("SetCase mauvais");
		

		ligne++;
		m++;
		}
		ligne=1;
		int z=0;
		while(z<p->n)
		{
		
		int test2=set_case(p,ligne,j,tmp[z]);
		if(test2!=1)
		printf("SetCase mauvais");
		

		ligne++;
		z++;
		}


	}







 }



/*
* Fonction permutant les valeurs nb1 et nb2 dans le quartier si nb1 et nb2 correspondent à des
* valeurs différentes pour des immeubles (entre 1 et n inclus) et si le quartier est entièrement
* rempli.
*
* \param p : pointeur sur gratte-ciel
* \param nb1 : première valeur
* \param nb2 : deuxième valeur
*/
void permute_nombres(Gratte_ciel * p, int nb1, int nb2) 
{

if(get_nb_cases_libres(p)==0 && nb1!=nb2 && nb1>=1 && nb1<=p->n && nb2>=1 && nb2<=p->n)
{
	int i=1;
	int j=1;
	while(i<p->n+1)
	{
			j=1;
		while(j<p->n+1)              
	{
		
		if(get_case(p,i,j)==nb1)
		{
			set_case(p,i,j,nb2);
			j++;
		}
		else if(get_case(p,i,j)==nb2)
		{
			set_case(p,i,j,nb1);
			j++;
		}
		
		else
		j++;
		
		
	}
	i++;
	}	




 }



}

/*
* Fonction remplissant le quartier selon un schéma précis
* (10 étages sur la diagonale et +10 étages pour le voisin de droite)
*
* \param p : pointeur sur gratte-ciel
*/

void remplir_quartier( Gratte_ciel * p) 
{ 


	int i;
	for(i=1;i<p->n+1;i++)
	{
		set_case(p,i,i,1); 				//DIAGONALE 
		set_case(p,1,i,i);				//Remplissage de la premiere ligne
		set_case(p,i,p->n,p->n+1-i);			//Remplissage de la derniere case pour la ligne i
	if(i!=1)
	set_case(p,i,1,get_case(p,i-1,p->n));	// remplissage de la premiere case  : prend la valeur de n eme case de la ligne d'avant 
					
		int j=1;						
		for(j=1;j<p->n+1;j++)
		{
			if(get_case(p,i,j)==0)
			{
				set_case(p,i,j,get_case(p,i,j-1)+1);
			}
		   
		}
	
	}
	
}


/*
2
* Fonction retournant un nombre entier aléatoire entre min et max inclus, -1 si min > max.
3
*
4
* \param min : borne inférieure de l’intervalle
5
* \param max : borne supérieure de l’intervalle
6
*/


int nombre_aleatoire(int min, int max ) 
{
	if(min>max)									//NE PAS OUBLIER LE SRANDTIMENULL
	return -1;
	
	else
	{
		int a = rand()%(max - min + 1) + min;
		return a;
	}





}



/*
2
* Fonction générant aléatoirement un quartier de manière qu’il n’y ait pas deux immeubles
3
* de même taille sur une même ligne ou colonne.
4
*
5
* \param p : pointeur sur gratte-ciel
6
*/

void quartier_aleatoire(Gratte_ciel * p)
{
	
	int m;
	remplir_quartier(p);
	int a=nombre_aleatoire(50,100);
	int x;
	
			m=0;
			while(m<a)
		{
			x=nombre_aleatoire(1,3); 
			
			if(x==1)
			permute_lignes(p,nombre_aleatoire(1,p->n),nombre_aleatoire(1,p->n));
			
			if(x==2)									
			permute_colonnes(p,nombre_aleatoire(1,p->n),nombre_aleatoire(1,p->n));
		
			if(x==3)
			permute_nombres(p,nombre_aleatoire(1,p->n),nombre_aleatoire(1,p->n));
		
			m++;
		}

	

		

}
/*!
* Fonction créant une instance du jeu Gratte-ciel. Le quartier est généré aléatoirement,
* la bordure est mise à jour et le quartier est finalement effacé.
* La fonction renvoie l’adresse du gratte-ciel ainsi créé.
*
* \param n : Nombre d’immeubles par ligne et par colonne du quartier
*/
Gratte_ciel * creer_gratte_ciel_aleatoire (int n)
{
	
	Gratte_ciel *p=creer_gratte_ciel(n);
	quartier_aleatoire(p);
	calcul_bordure(p);
	int j=0;
	int i=0;
	int m;
	while(i<n+1)
	{
		j=0;
		while(j<n+1)
		{
			m=rand()%2+1;
			if (m==1)
				set_case(p,i,j,nombre_aleatoire(0,0));
			j++;
		}
	i++;
	}
	
	
	return p;
}


/*!
* Fonction permettant au joueur de saisir un emplacement d’immeuble et modifiant le quartier en
* conséquence. Si le joueur veut arrêter, il saisit la chaîne "stop". La saisie est répétée
* jusqu’à ce que la saisie corresponde à une saisie d’un immeuble sur une case.
*
* Format : "B1 30" pour mettre un immeuble de 30 étages sur la case du quartier de la 2ème ligne
* et de la 1ère colonne
*/





int retourne_valeur_lettre(Gratte_ciel * p,char lettre)
{
		
	int i=1;
	char x='A';
	while(i<p->n+1)
{
		if(lettre==x)
		{
			return i;
		}
				else
				{
					x++;
					i++;
				 }
}
return 0;
}
	
int retourne_colonne_immeuble(Gratte_ciel * p,char b)
{
	int a=0;
	char x='0';
	while(b>47 && b<58)
	{
		if(b==x)
		{
			return a;
		}
		else
		a++;
		x++;
	



	}

return 0;
}

int mouvement(Gratte_ciel * p) 
{	
	char ch1[5];
	char ch2[5]="stop";
	int m;
	int z;
	int j;
	int w=0;
	
printf("Veuillez saisir l'emplacement et ensuite saisir la taille de l'immeuble a placer a cette endroit : \n");
saisie_avec_espaces(ch1,6);
printf("Vous avez taper : %s \n", ch1);

if(strcmp(ch1,ch2)==0)					//if ==0  les chaines sont pareils !//
return 0;

else 
{	
	
	m=retourne_valeur_lettre(p,ch1[0]);
	j=retourne_colonne_immeuble(p,ch1[1]);
	z=retourne_colonne_immeuble(p,ch1[3]);
		if(get_case(p,m,j)==1 && est_case_bordure(p,m,j)==0)
			w++;	

					
		if(get_case(p,m,j)==-1)
	{
	
		
			while(w==0)
		{
			printf("Veuillez saisir l'emplacement et ensuite saisir la taille de l'immeuble a placer a cette endroit : \n");
			saisie_avec_espaces(ch1,6);
			printf("Vous avez taper : %s \n", ch1);
			if(get_case(p,m,j)==1 && est_case_bordure(p,m,j)==0 )
			w++;
		}
	}

	
}



m=retourne_valeur_lettre(p,ch1[0]);
j=retourne_colonne_immeuble(p,ch1[1]);
z=retourne_colonne_immeuble(p,ch1[3]);
set_case(p,m,j,z);
affichage_gratte_ciel(p);

return 1;
 }


void jouer(Gratte_ciel * p,int n)
{
	

	while(p->nb_cases_libres!=0)
	{
		mouvement(p);
		

	}
	int res=quartier_est_solution(p);
	if(res==1)
	{
	calcul_bordure(p);
	affichage_gratte_ciel(p);
	printf("Partie gagnée \n");
	}
	
	else
	{
	calcul_bordure(p);
	affichage_gratte_ciel(p);
	printf("Partie perdue \n");
	}

}
