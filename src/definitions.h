//definition du nombre de sommets et du nombre d'arcs du graphe orienté représentant la carte
#define V 45		//nombre de sommets
#define E 100		//nombre d'arcs

//Structure principale representant un arc du graphe
typedef struct
{
	char* nom;		//noms de l'arc de poids le plus faible entre le sommet de depart et le sommet d'arrivee
	char* depart;	//nom du sommet de depart
	char* arrivee;	//nom du sommet d'arrivee
	int couleur;	//utilisee pour colorier l'arc lors de l'affichage graphique
	int poids;		//poids de l'arc de poids le plus faible entre le sommet de depart et le sommet d'arrivee
} Arc;

typedef struct
{
	int sommet;
	int poid;
	int parcouru;
} parcour;

typedef struct
{
	int sommet;
	int pere;
} antecedant;

Arc G[V][V];
