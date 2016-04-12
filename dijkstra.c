#include "definitions.h"
#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
			printf("le pere est %d\n",pere);
		int nbf=recherche_fils(pere,f);
		for (i = 0; i < nbf; i++)
		{
			fils=f[i];
			printf("le fils est %d\n",fils);
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
		printf("%d ) vous devez partir du sommet '%s' et prendre '%s' jusqu'au sommet '%s'\n\n",j,nomSommet(chemin[i-j-1]),G[chemin[i-j-1]][chemin[i-j-2]].nom,nomSommet(chemin[i-j-2]));
	}
	printf("%d ) vous etes arrivé a votre destination '%s' en %d secondes\n\n\n",j,nomSommet(chemin[0]),p[chemin[0]].poid);
}


