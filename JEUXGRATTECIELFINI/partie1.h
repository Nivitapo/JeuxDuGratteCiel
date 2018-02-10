#ifndef PARTIE1_H
#define PARTIE1_H

										///////////////////////////////
										///////////Exercie 1///////////
										///////////////////////////////
typedef struct {
    int *grille;
    int n;
    int nb_cases_libres;
} Gratte_ciel;

void clear_terminal();
int color_printf(COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, const char * format, ...);
Gratte_ciel *creer_gratte_ciel(int nb);
void detruire_gratte_ciel(Gratte_ciel * p);
int indice_grille_valide(Gratte_ciel * p, int i);
int get_case(Gratte_ciel * p, int i, int j);
int set_case(Gratte_ciel * p, int i, int j, int val);
int get_nb_cases_libres(Gratte_ciel * p);
int affichage_indice_horizontal(Gratte_ciel * p,int cases);
int affichage_ligne_milieu(Gratte_ciel * p,int cases,int ligne);
void transition();
void coord_horizontale(Gratte_ciel * p);
void affichage_gratte_ciel (Gratte_ciel *p);

#endif

