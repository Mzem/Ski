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
void printListeChemin(Liste l, Arc G[V][V], char* tempsTotal)
{
    if (l==NULL || l->suiv == NULL) {		//Cas impossible, donc on peut ne pas le gérer
		printf("La liste est vide\n");
		return;
	}
	int i=0;
	POINT HGs = {880,410};
	POINT HGa = {890,395};
    while(l->suiv != NULL) {
		printf("- Vous devez partir du sommet \"%s\" en prenant \"%s\" jusqu'au sommet \"%s\".\
		\n", nomSommet(l->val), G[l->val][l->suiv->val].nom, nomSommet(l->suiv->val));
		if(i!=0)
			aff_pol(nomSommet(l->val),14,HGs,gold);
		aff_pol(G[l->val][l->suiv->val].nom,12,HGa,blanc);
		HGs.y -= 30;
		HGa.y -= 30;
        l = l->suiv;
        i++;
	}
	aff_pol(nomSommet(l->val),14,HGs,vert);
	HGa.y -= 10;
	aff_pol(tempsTotal,17,HGa,blanc);
}

//Fonctions principales

void plusCourtChemin(Arc G[V][V], int sommetDepart, int sommetArrivee)
{	//Calcule le plus court chemin entre deux sommets et affiche ce chemin
	POINT HGmsg = {890,370};
	
	if (sommetDepart == sommetArrivee)
	{
		printf("Vous etes deja a destination '%s'\n\n",nomSommet(sommetDepart));
		POINT HGs2 = {880,390};
		aff_pol(nomSommet(sommetArrivee),14,HGs2,vert);
		aff_pol("a destination",14,HGmsg,blanc);
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
			POINT HGs2 = {880,390};
			aff_pol(nomSommet(sommetArrivee),14,HGs2,vert);
			aff_pol("pas de chemin",14,HGmsg,blanc);
			return;
		}
		drawArc(depart,arrivee);
		tempsTotal += G[depart][arrivee].poids;
		chemin = ajoutDebut(chemin,depart);
		
		arrivee = depart; 		//Le nouveau sommet d'arrivee est l'ancien sommet de départ
	} while (depart != sommetDepart);
	
	//Affichage du chemin et du temps (en console et graphique)
	draw_fill_circle(points[sommetDepart],5,rouge);
	char ch[3];
	sprintf(ch,"%d MINUTES",tempsTotal);
	printListeChemin(chemin,G,ch);
	printf("Vous etes arrivé en %d minutes\n",tempsTotal);

	affiche_all();
}

void itineraire(Arc G[V][V])
{	//Lance le choix du point de départ et d'arrivée en mode graphique
	
	while(1)	//ne s'arrete que si l'on clique sur le bouton menu
	{
		afficheCarte();
		
		POINT clic = wait_clic();
		POINT HG = {880,410};
		
		int sommetDepart, sommetArrivee = -1;
	
		if (clicBoutonMenu(clic))	//si on clique sur le bouton menu, la fonction se termine
			return;
		
		if ( (sommetDepart = clicSommet(clic,rouge)) != -1 )	//si on clique sur un 1er sommet
		{
			aff_pol(nomSommet(sommetDepart),14,HG,rouge);
			affiche_all();
			
			while(sommetArrivee == -1)	//on attend un clic sur un 2ème sommet
			{
				clic = wait_clic();
				
				if ( (sommetArrivee = clicSommet(clic,vert)) != -1 )
				{
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
