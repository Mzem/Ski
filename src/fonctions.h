#ifndef DEF_DEF
#define DEF_DEF

#include "definitions.h"

#endif

//Fonctions qui lancenet le calcul du plus court chemin et qui affichent ce chemin

void itineraire(Arc G[V][V]);	//Lance le choix du point de départ et d'arrivée en mode graphique

void plusCourtChemin(Arc G[V][V], int sommetDepart, int sommetArrivee);	//Calcule le plus court chemin entre deux sommets et affiche ce chemin
