#ifndef DEF_DEF
#define DEF_DEF

#endif

//definition du nombre de sommets et du nombre d'arcs du graphe orienté représentant la carte
#define V 45		//nombre de sommets
#define E 99		//nombre d'arcs

typedef struct
{
	char* nom;		//noms de l'arc de poids le plus faible entre le sommet de depart et le sommet d'arrivee
	char* depart;	//nom du sommet de depart
	char* arrivee;	//nom du sommet d'arrivee
	int poids;		//poids de l'arc de poids le plus faible entre le sommet de depart et le sommet d'arrivee
} Arc;

typedef struct
{
	int sommet;
	int poid;
	int parcouru;
}parcour;

typedef struct
{
	int sommet;
	int pere;
}antecedant;

Arc G[V][V];
