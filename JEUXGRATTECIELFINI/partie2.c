#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <time.h>
#include "couleurs_terminal.h"
#include "partie1.h"
#include "partie2.h"

///////////////////////////////////////////////////////////////////PARTIE 2 ://////////////////////////////////////////////////////////

										///////////////////////////////
										///////////Exercie 9///////////
										///////////////////////////////

/*!
* Fonction retournant 1 si (i,j) est une case de la bordure (n’est pas une case inutilisée),
* 0 sinon
*
* \param p : pointeur sur gratte-ciel
* \param i : indice de ligne
* \param j : indice de colonne
*/

int est_case_bordure(Gratte_ciel * p, int i, int j)
{
    if(get_case(p,i,j)==-1)		//Si c'est pas une case -> return 0
		return 0;
	if( (i>0 && i<p->n+1) && (j>0 && j<p->n+1) ) //Si case de la grille -> return 0 
		return 0;
	if( (i==0 && j==0) || (i==0 && j==p->n+1) || (i==p->n+1 && j==p->n+1) || (j==0 && i==p->n+1) ) //Si case du coin -> return 0
		return 0;
	return 1; 

}


										///////////////////////////////
										///////////Exercie 10//////////
										///////////////////////////////
/*!
* Fonction retournant le nombre d’immeubles visibles depuis la case (i,j)
*
* si (i,j) n’est pas une case de la bordure ou si c’est une case inutilisée,
* la fonction retourne -1
*
* \param p : pointeur sur gratte-ciel
* \param i : indice de ligne
* \param j : indice de colonne
*/


int nb_immeubles_visibles(Gratte_ciel * p, int i, int j)
{
	if(est_case_bordure(p,i,j)==0)		//Si pas case bordure -> return -1
		{
			return -1;
		}										
		
		
		
	int compteur=0; 
	int minim=0;
	if(i==0)			//Bordure du gauche  
	{
		i=1;
		while(i<p->n+1)
		{
			if(minim<p->grille[i*(p->n+2)+j])  //Comparaison permettant l'incrémentation du compteur pour nb immbeuble visible
			{
				compteur++;
				minim=p->grille[i*(p->n+2)+j];
			}
			i++;
		}
	}	
			
	else if(i==p->n+1)		//Bordure de droite 
	{
		i=p->n;
		while(i>0)
		{
			if(minim<p->grille[i*(p->n+2)+j])
			{
				compteur++;
				minim=p->grille[i*(p->n+2)+j];
			}
			i--; 					//décalage  vers la gauche pour compteur bordure droit
		}
	}
		
	else if(j==0)		//Bordure haut
	{
		j=1;
		while(j<p->n+1)
		{
			
			if(minim<p->grille[i*(p->n+2)+j])
			{
				compteur++;
				minim=p->grille[i*(p->n+2)+j];
			}
		j++;
		}
	}	
	
	else 			//Bordure bas
	{
		j=p->n;
		while(j>0)
		{
			if(minim<p->grille[i*(p->n+2)+j])
			{
				compteur++;
				minim=p->grille[i*(p->n+2)+j];
			}
		j--;
	
		}
	}
	return compteur;
}

										///////////////////////////////
										///////////Exercie 11//////////
										///////////////////////////////
/*!
* Fonction mettant à jour la bordure avec le nombre d’immeubles du quartier visibles
* depuis chaque case.
*
* \param p : pointeur sur gratte-ciel
*/
void calcul_bordure(Gratte_ciel *p)
{
	int j;					
	int i=0;					
	while(i<p->n+2)
	{
			j=0;
			while(j<p->n+2) 
			{
				if(est_case_bordure(p,i,j))					//Si case bordure -> mets nb immeubles visibles (fonction)
					p->grille[i*(p->n+2)+j]=nb_immeubles_visibles(p,i,j);
				j++;
			}
		i++;
	}
}

										///////////////////////////////
										///////////Exercie 12//////////
										///////////////////////////////
/*!
* Fonction retournant 1 si les immeubles de la ligne ind sont tous de taille différente
*
* \param p : pointeur sur gratte-ciel
* \param ind : indice de ligne
*/
int valeurs_differentes_ligne(Gratte_ciel *p, int ind)
{
	if(ind<=0 || ind>p->n)		//Si ind != une ligne -> return 0 
   	 {
        	return 0;
   	 }

	int i=1;
	while(i<p->n)
	{
		int j=i+1;
		while(j<=p->n)
		{
			if(p->grille[ind*(p->n+2)+i]==p->grille[ind*(p->n+2)+j] && p->grille[ind*(p->n+2)+i] != 0 && p->grille[ind*(p->n+2)+j] !=0) //Si 2 cases identiques et !=0 -> return 0 (ligne)
				return 0;
		j++;
		}   
	i++;
}
        return 1;
}


										///////////////////////////////
										///////////Exercie 13//////////
										///////////////////////////////
/*!
* Fonction retournant 1 si les immeubles de la colonne ind sont tous de taille différente
*
* \param p : pointeur sur gratte-ciel
* \param ind : indice de colonne
*/
int valeurs_differentes_colonne (Gratte_ciel * p, int ind)
{
	if(ind<=0 || ind>p->n)
   	 {
        	return 0;
   	 }
int j=1;
	while(j<p->n)
	{
		int i=j+1;
		while(i<=p->n)
		{
			if(p->grille[i*(p->n+2)+ind]==p->grille[j*(p->n+2)+ind] && p->grille[i*(p->n+2)+ind]!= 0 && p->grille[j*(p->n+2)+ind] !=0)  //Si 2 cases identiques et !=0 -> return 0 (colonne)
				return 0;
		i++;
		}   
	j++;
}
        return 1;
}


										///////////////////////////////
										///////////Exercie 14//////////
										///////////////////////////////
/*!
* Fonction retournant 1 s’il n’y a pas deux immeubles de même hauteur
* dans une ligne ou une colonne du quartier
*
* \param p : pointeur sur gratte-ciel
*/
int valeurs_differentes_quartier (Gratte_ciel * p)
{
    int ind=1;
    while(ind< p->n)
    {
        if(valeurs_differentes_ligne (p,ind)!=1 || valeurs_differentes_colonne(p,ind)!=1) //Si immeuble même hauteur dans ligne ou colonne -> return 0 
            return 0;
        ind++;
    }
    return 1;							//Si aucun immeuble même hauteur dans ligne ou colonne -> return 1
}
 
										///////////////////////////////
										///////////Exercie 15//////////
										///////////////////////////////
/*
*
* Fonction retournant 1 si les valeurs non-nulles de la bordure correspondent
* au nombre d’immeubles que l’on aperçoit dans le quartier à partir de la bordure,
* et 0 sinon.
*
* \param p : pointeur sur gratte-ciel
*/


int bordure_correcte(Gratte_ciel *p)
{
    int i=0;
    while(i<p->n+2)
    {
        int j=0;           
        while (j<p->n+2)
        {
            if(est_case_bordure(p,i,j) && get_case(p,i,j)!=0) 		//Si case de la bordure et valeur case !=0 ->  
                if(nb_immeubles_visibles(p,i,j)!=get_case(p,i,j))	//Si nb immeuble visible != valeur case -> return 0
                    {
                        return 0;
                    }
            j++;
        }

	i++;
     }
    return 1;	//Sinon validé
	
}

										///////////////////////////////
										///////////Exercie 16//////////
										///////////////////////////////
/*!
* Fonction retournant 1 si le placement des immeubles dans le quartier correspond
* à une solution du jeu du gratte-ciel, et 0 sinon.
*
* \param p : pointeur sur gratte-ciel
*/
int quartier_est_solution ( Gratte_ciel * p) 
{ 

if(valeurs_differentes_quartier (p) && bordure_correcte(p) && p->nb_cases_libres==0) 		//On verifie si ttes cases occupées et chq val immeubles != et chq bordures correctes 
	return 1;
else
	return 0; 

}
