#ifndef PARTIE3_H
#define PARTIE3_H

void purger();
void clean (char *chaine);
void saisie_avec_espaces(char * chaine, int n);
void permute_lignes(Gratte_ciel * p, int i, int j);
void permute_colonnes(Gratte_ciel * p, int i, int j);
void permute_nombres(Gratte_ciel * p, int nb1, int nb2);
void remplir_quartier( Gratte_ciel * p);
int nombre_aleatoire(int min, int max );
void quartier_aleatoire(Gratte_ciel * p);
Gratte_ciel * creer_gratte_ciel_aleatoire (int n);
int retourne_valeur_lettre(Gratte_ciel * p,char lettre);
int retourne_colonne_immeuble(Gratte_ciel * p,char b);
int mouvement(Gratte_ciel * p);
void jouer(Gratte_ciel * p,int n);

#endif
