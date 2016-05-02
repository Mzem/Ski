#ifndef DEF_GRAPH
#define DEF_GRAPH

#include "graphics.h"

#endif

//definition du nombre de sommets et du nombre d'arcs du graphe orienté représentant la carte
#define V 45		//nombre de sommets
#define E 100		//nombre d'arcs
#define DEBUTANT 1
#define EXPERT 0

//Structure principale representant un arc du graphe
typedef struct
{
	char* nom;		//noms de l'arc de poids le plus faible entre le sommet de depart et le sommet d'arrivee
	char* depart;	//nom du sommet de depart
	char* arrivee;	//nom du sommet d'arrivee
	int couleur;	//couleur de l'arc, utilisée pour colorier l'arc lors de l'affichage graphique
	int poids;		//poids de l'arc de poids le plus faible entre le sommet de depart et le sommet d'arrivee
} Arc;

Arc G[V][V];		//matrice d'adjascence représentant les arcs du graphe
					//la 1ère dimension (les lignes) représente les sommets de déprat
					//la 2ème dimension (les colonnes) représente les sommets d'arrivée
POINT points[V];	//tableau de coordonnées des sommets : à chaque sommet (repréré par son indice) correspond des coordonnées
					//utilisé uniquement pour l'interface graphique
