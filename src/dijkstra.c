#include "graphe.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>

void initialise_tableau_antecedant(antecedant a[])
{	//initialise le tableau antecedant
	int i;
	for (i = 0; i < V; i++)
	{
		a[i].sommet=i;
		a[i].pere=-1;
	}
}

void initialise_tableau_parcour(parcour p[],int depart)
{	//initialise le tableau parcour
	int i;
	for (i = 0; i < V; i++)
	{
		p[i].sommet=i;
		p[i].parcouru= 0;
		p[i].poid=G[depart][i].poids;
	}
}

int recherche_pere(parcour p[])
{	//recherche le sommet de poid minimum (le poid=1000 a modifier)
	int indice_pere=0;
	while((p[indice_pere].poid<1)&&(indice_pere<(V-1))) indice_pere++;
	int i;
	for (i = (indice_pere+1); i < V; i++)
	{
		if( ( p[i].poid < p[indice_pere].poid ) && ( p[i].poid > 0 ) && (p[i].parcouru!=1))
			indice_pere = i;
	}
	if(( p[indice_pere].poid < 1 ) || (p[indice_pere].parcouru == 1 ))
		return -1;
	return indice_pere;
}

int recherche_fils(int pere,int f[])
{//recherche tout les fils de pere 
	int nombre_fils=0;
	int i;
	for (i = 0; i < V; i++)
	{
		if ( G[pere][i].poids < 1000 ){
			f[nombre_fils] = i;
			nombre_fils++;
		}
	}
	return nombre_fils;
}

void dijkstra(int depart,int arrivee,antecedant a[],parcour p[])
{
	int pere=depart; 
	int i,j,fils;
	int f[10];
	if (depart==arrivee){
		 printf("Vous etes deja a destination '%s'\n\n\n",nomSommet(depart));
		return;}
	while(pere!=-1)
	{
		int nbf=recherche_fils(pere,f);
		for (i = 0; i < nbf; i++)
		{
			fils=f[i];
			if((p[fils].parcouru==0)&&((p[fils].poid==-1)||(p[pere].poid+G[pere][fils].poids<p[fils].poid)))
			{
				p[fils].poid=p[pere].poid+G[pere][fils].poids;
				a[fils].pere=pere;
			}
		}
		p[pere].parcouru=1;
		pere=recherche_pere(p);
	}
	//#############affichage####################
	int chemin[50];
	i=0;
	while(-1!=arrivee)
	{
		chemin[i]=arrivee;
		i++;
		arrivee=a[arrivee].pere;
	} 
	chemin[i]=depart;
	i++;
	for (j = 0; j < i-1 ; j++) 
	{
		drawArc(chemin[i-j-1], chemin[i-j-2]);
		printf("%d) vous devez partir du sommet '%s' et prendre '%s' jusqu'au sommet '%s'\n\n",j,nomSommet(chemin[i-j-1]),G[chemin[i-j-1]][chemin[i-j-2]].nom,nomSommet(chemin[i-j-2]));
	}
	printf("%d) vous etes arrivé a votre destination '%s' en %d secondes\n\n\n",j,nomSommet(chemin[0]),p[chemin[0]].poid);
}

//Test malloc

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
	

void dijkstra2(int pere[V], int sommetDepart)
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


