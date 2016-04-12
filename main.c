#include "graphe.h"
#include "fonctions.h"
#include <stdio.h> 


int main(int argc, char* argv[])
{
	Arc G[V][V];
	
	lectureGraphe("graphe.txt",G);
	afficheGraphe(G);
	
	/*
	char* sommetDepart;
	char* sommetArrivee;
	antecedant a[V];
	parcour p[V];

	printf("Ou vous trouvez-vous ?\n");
	scanf("%s",sommetDepart);
	printf("A quel endroit souhaitez-vous vous rendre ?\n");
	scanf("%s",sommetArrivee);
	printf("\n\n");
	initialise_tableau_antecedant(a);
	initialise_tableau_parcour(p,indiceSommet(depart));
	dijkstra(indiceSommet(depart),indiceSommet(arrivee),a,p);
	*/   
	return 0;
}
 //si poid arrivée==1000 demande de remonter un peu a pied car chemin inexistant
 //le poid =1000 a modifier
