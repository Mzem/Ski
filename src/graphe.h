#ifndef DEF_DEF
#define DEF_DEF

#include "definitions.h"

#endif

//Fonctions concernant la lecture et le traitement des éléments du graphe

char* nomSommet(int indiceSommet);

char* nomArc(int indiceArc);

void lectureGraphe(char* nomFichier, Arc G[V][V], int experience);
