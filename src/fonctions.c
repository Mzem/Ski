#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichage.h"
#include "graphe.h"
#include "dijkstra.h"

//Fonctions principales

void plusCourtChemin(Arc G, int sommetDepart, int sommetArrivee)
{
	POINT HG;
	HG.x = 880;
	HG.y = 580;
	
	if (sommetDepart == sommetArrivee)
	{
		printf("Vous etes deja a destination '%s'\n\n",nomSommet(sommetDepart));
		return;
	}
	
	int pere[V];
	dijkstra2(pere,sommetDepart);	//Modifie le tableau pere
	
	//On exploite le tableau pere pour remonter du sommetArrivee au sommetDepart
	int depart, arrivee = sommetArrivee;
	do {
		depart = pere[arrivee];	//Le sommet de départ est le pere du sommet d'arrivee
		if (depart == -1)
		{
			printf("Il n'existe pas de chemin entre '%s' et '%s'\n\n",nomSommet(sommetDepart),nomSommet(sommetArrivee));
			return;
		}
		drawArc(depart,arrivee);
		arrivee = depart; 		//Le nouveau sommet d'arrivee est l'ancien sommet de départ
	} while (depart != sommetDepart);
	
	
	/*
	
	antecedant a[V];
	parcour p[V];

	initialise_tableau_antecedant(a);
	initialise_tableau_parcour(p, sommetDepart);

	dijkstra(sommetDepart, sommetArrivee, a, p);
	*/
}

void itineraire(Arc G, int experience)
{	//Lance le choix du point de départ et d'arrivée en mode graphique
	
	int sommetDepart, sommetArrivee = -1;
	POINT HG;
	
	while(1)	//ne s'arrete que si l'on clique sur le bouton menu
	{
		POINT clic = wait_clic();
		HG.x = 880; HG.y = 370;
	
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
					afficheTexte(nomSommet(sommetArrivee),HG,vert);
					plusCourtChemin(G, sommetDepart, sommetArrivee);	//Lance le calcul du plus court chemin en mode graphique
			}
		}
	}
}
