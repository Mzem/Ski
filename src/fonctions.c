#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichage.h"
#include "graphe.h"
#include "dijkstra.h"

//Fonctions qui lancenet le calcul du plus court chemin et qui affichent ce chemin

typedef struct element
{	//Liste chainées utilisée pour stocker les sommets constituant le plus court chemin (moins gourmand qu'un tableau)
    int val;
    struct element* suiv;
} Element;

typedef Element* Liste;		

Liste ajoutDebut(Liste l, int x)
{
    Element* nouveau = malloc(sizeof(Element)) ;

    nouveau->val = x ;
    nouveau->suiv = l ;
    l = nouveau ;
    return l;
}
void printListeChemin(Liste l, Arc G[V][V])
{
    if (l==NULL || l->suiv == NULL) {		//Cas impossible, donc on peut ne pas le gérer
		printf("La liste est vide\n");
		return;
	}
    while(l->suiv != NULL) {
		printf("- Vous devez partir du sommet \"%s\" en prenant \"%s\" jusqu'au sommet \"%s\".\
		\n", nomSommet(l->val), G[l->val][l->suiv->val].nom, nomSommet(l->suiv->val));
        l = l->suiv;
	}
}

//Fonctions principales

void plusCourtChemin(Arc G[V][V], int sommetDepart, int sommetArrivee)
{	//Calcule le plus court chemin entre deux sommets et affiche ce chemin
	POINT HG = {880,170};
	
	if (sommetDepart == sommetArrivee)
	{
		printf("Vous etes deja a destination '%s'\n\n",nomSommet(sommetDepart));
		afficheTexte("A DESTINATION",HG,blanc);
		return;
	}
	
	int pere[V];	//Tableau des pères modifié par dijkstra et va etre exploité pour afficher le plus court chemin
	Liste chemin = NULL;	//Liste qui va stocker le plus court chemin
	int tempsTotal = 0;
	
	dijkstra(pere,sommetDepart);	//Modifie le tableau pere

	//On exploite le tableau pere pour remonter du sommetArrivee au sommetDepart
	int depart, arrivee = sommetArrivee;
	
	chemin = ajoutDebut(chemin,arrivee);	//On ajoute le sommet d'arrivée actuel à la fin de la liste	
	
	do {
		depart = pere[arrivee];	//Le sommet de départ actuel est le pere du sommet d'arrivee actuel
		if (depart == -1)
		{
			printf("Il n'existe pas de chemin entre '%s' et '%s'\n\n",nomSommet(sommetDepart),nomSommet(sommetArrivee));
			afficheTexte("PAS DE CHEMIN",HG,blanc);
			return;
		}
		drawArc(depart,arrivee);
		tempsTotal += G[depart][arrivee].poids;
		chemin = ajoutDebut(chemin,depart);
		
		arrivee = depart; 		//Le nouveau sommet d'arrivee est l'ancien sommet de départ
	} while (depart != sommetDepart);
	
	//Affichage du chemin et du temps (en console et partiellement en graphique)
	draw_fill_circle(points[sommetDepart],5,rouge);
	printListeChemin(chemin,G);
	printf("Vous etes arrivé en %d minutes\n",tempsTotal);
	char ch[3];
	sprintf(ch,"%d MINUTES",tempsTotal);
	afficheTexte(ch,HG,blanc);
	affiche_all();
}

void itineraire(Arc G[V][V])
{	//Lance le choix du point de départ et d'arrivée en mode graphique
	POINT HG;
	
	while(1)	//ne s'arrete que si l'on clique sur le bouton menu
	{
		afficheCarte();
		
		POINT clic = wait_clic();
		HG.x = 880; HG.y = 370;
		int sommetDepart, sommetArrivee = -1;
	
		if (clicBoutonMenu(clic))	//si on clique sur le bouton menu, la fonction se termine
			return;
		
		if ( (sommetDepart = clicSommet(clic,rouge)) != -1 )	//si on clique sur un 1er sommet
		{
			afficheTexte(nomSommet(sommetDepart),HG,rouge);
			
			while(sommetArrivee == -1)	//on attend un clic sur un 2ème sommet
			{
				clic = wait_clic();
				HG.y = 270;
				
				if ( (sommetArrivee = clicSommet(clic,vert)) != -1 )
				{
					afficheTexte(nomSommet(sommetArrivee),HG,vert);
					plusCourtChemin(G, sommetDepart, sommetArrivee);	//Lance le calcul du plus court chemin en mode graphique
				}
			}
		
			afficheBoutonRecommencer();
			while(1)	//ne s'arrete que si l'on clique sur le bouton recommencer ou menu
			{
				clic = wait_clic();
				if(clicBoutonMenu(clic))
					return;
				if(clicBoutonRecommencer(clic))
					break;
			}
		}
	}
}
