#include "graphe.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>

int tousLesSommetsTraites(int sommetsTraites[V])
{	//Retourne vrai (1) si le tableau ne contient que des 1
	int i;
	for (i = 0; i < V; i++)
		if (sommetsTraites[i] == 0)
			return 0;
	return 1;
}

void initTableauPere(int pere[V])
{	//Initialise le tableau pere à -1 (-1 : pas de père)
	int i;
	for (i = 0; i < V; i++)
		pere[i] = -1;
}
	

void dijkstra(int pere[V], int sommetDepart)
{	//Modifie le tableau pere pour donner le tableau des plus courts chemins pour un sommet de départ donné
	//Structures et initialisations
	int sommetsTraites[V] = {0};	//quand le sommet i sera traité, sommetsTraites[i] vaudra 1
									//tous les sommets du graphe seront traités si ce tableau ne contient que des 1
	int plusCourteDistance[V];		//plusCourteDistance[i] vaut la plus courte distance entre le sommet de départ et le sommet i
	initTableauPere(pere);			//pere[i] vaut le père du sommet i, -1 veut dire pas de père
	
	sommetsTraites[sommetDepart] = 1;	//le sommet de départ est traité
	
	int i;
	//Cette boucle initialise le tableau plusCourteDistance[]
	//Pour tout sommet du graphe
	for (i = 0; i < V; i++)
	{	
		//Si c'est un successeur du sommet de départ, sa plusCourteDistance au sommet de départ vaut le poids de l'arc
		if (G[sommetDepart][i].poids != 1000)
		{
			plusCourteDistance[i] = G[sommetDepart][i].poids;
			pere[i] = sommetDepart;
		}
		//Sinon sa plusCourteDistance au sommet de départ vaut 1000 (infinie)
		else
			plusCourteDistance[i] = 1000;
	}
	
	plusCourteDistance[sommetDepart] = 0;	//le sommet de départ n'a pas une distance infinie à lui-meme
	
	//Boucle principale
	//Tant que tous les sommets n'ont pas été traités
	while (!tousLesSommetsTraites(sommetsTraites))
	{	
		//On cherche le prochain sommet à traiter : celui dont la plusCourteDistance au sommet de départ est minimale
		int min = 1000, aTraiter;
		//Pour tout sommet
		for (i = 0; i < V; i++)
		{
			//Si le sommet n'est pas traité
			if (sommetsTraites[i] == 0)		
			{
				//Si sa plusCourteDistance au sommet de départ est inférieur au minimum
				if (plusCourteDistance[i] <= min)	
				{
					aTraiter = i;
					min = plusCourteDistance[i];
				}
			}
		}	
		
		//Traitement du sommet aTraiter
		sommetsTraites[aTraiter] = 1;	
		for (i = 0; i < V; i++)
		{
			//Pour chaque successuer du sommet aTraiter
			if (G[aTraiter][i].poids != 1000)
			{
				//Si la plus courteDistance de ce sommet au sommet de départ est plus grande que celle passant par le sommet aTraiter
				if (plusCourteDistance[i] >= plusCourteDistance[aTraiter] + G[aTraiter][i].poids)
				{	//On met cette distance à jour (la plus petite), et surtout on renseigne le père
					plusCourteDistance[i] = plusCourteDistance[aTraiter] + G[aTraiter][i].poids;
					pere[i] = aTraiter;
				}
			}
		}
	}
}
