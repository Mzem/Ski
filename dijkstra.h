#ifndef DEF_DEF
#define DEF_DEF

#include "definitions.h"

#endif

void initialise_tableau_antecedant(antecedant a[]);

void initialise_tableau_parcour(parcour p[],int depart);

int recherche_pere(parcour p[]);

int recherche_fils(int pere,int f[]);

void dijkstra(int depart,int arrivee,antecedant a[],parcour p[]);
