#ifndef PARTIE2_H
#define PARTIE2_H

int est_case_bordure(Gratte_ciel * p, int i, int j);
int nb_immeubles_visibles(Gratte_ciel * p, int i, int j);
void calcul_bordure(Gratte_ciel *p);
int valeurs_differentes_ligne(Gratte_ciel *p, int ind);
int valeurs_differentes_colonne (Gratte_ciel * p, int ind);
int valeurs_differentes_quartier (Gratte_ciel * p);
int bordure_correcte(Gratte_ciel *p);
int quartier_est_solution ( Gratte_ciel * p);

#endif
