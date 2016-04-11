#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialise(Arc G[V][V])
{	//initialise le graphe
	int i, j;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
		{
			G[j][i].nom = "ARC INCONNU";
			G[j][i].poids = 1000;
			G[j][i].depart = "SOMMET INCONNU";
			G[j][i].arrivee = "SOMMET INCONNU";
		}
}
	
char* nomSommet(int indiceSommet)
{	//prend un indice de sommet et retourne le nom du sommet correspondant
	if (indiceSommet==0)
		return "PIC BLANC";
	if (indiceSommet==1)
		return "GROTTE DE GLACE";
	if (indiceSommet==2)
		return "LAC BLANC";
	if (indiceSommet==3)
		return "SOMMET 3060";
	if (indiceSommet==4)
		return "GLACIER DE SARENNE";
	return "SOMMET INCONNU";
}

int indiceSommet(char* nomSommet) 
{	//prend un nom de sommet et retourne son indice correspondant
	if (!strcmp(nomSommet,"PIC BLANC"))
		return 0;
	if (!strcmp(nomSommet,"GROTTE DE GLACE"))
		return 1;
	if (!strcmp(nomSommet,"LAC BLANC"))
		return 2;
	if (!strcmp(nomSommet,"SOMMET 3060"))
		return 3;
	return -1;
}

char* nomArc(int indiceArc)
{	//prend un indice d'arc et retourne le nom de l'arc correspondant
	if (indiceArc==0)
		return "descente du tunnel 1";
	if (indiceArc==1)
		return "descente de la breche";
	if (indiceArc==2)
		return "descente du tunnel 2";
	if (indiceArc==3)
		return "descente du glacier";
	if (indiceArc==4)
		return "descente de sarenne";
	if (indiceArc==5)
		return "telepherique pic blanc";
	if (indiceArc==6)
		return "telesiege glacier";
	return "arc inconnu";
}


void lectureGraphe(char* nomFichier, Arc G[V][V])
{
	FILE* F = fopen(nomFichier,"r");	//doit etre deja present, sinon NULL
	
	if (F == NULL){
		printf("fichier du graphe introuvable\n");
		return;
	}
	
	int i, temps, experience = getExperience();
	
	initialise(G);
		
	for (i = 0; i < E; i++)		//boucle qui parcourt les lignes du fichier : E lignes <=> E arcs
	{
		int indiceSommetDepart, indiceSommetArrivee, indiceArc, couleur;
		
		fscanf(F,"%d %d %d %d %d",&indiceSommetDepart, &indiceSommetArrivee, &indiceArc, &couleur, &temps);
		
		G[indiceSommetDepart][indiceSommetArrivee].nom = nomArc(indiceArc);
		G[indiceSommetDepart][indiceSommetArrivee].depart = nomSommet(indiceSommetDepart);
		G[indiceSommetDepart][indiceSommetArrivee].arrivee = nomSommet(indiceSommetArrivee);
		G[indiceSommetDepart][indiceSommetArrivee].poids = calculPoids(couleur,temps,experience);
	}
	
	fclose(F);
}

void afficheGraphe(Arc G[V][V])
{
	printf("\n######################################### AFFICHAGE DU GRAPHE #########################################\n");
	int i,j;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			printf("%s\t->\t%s\t : %s de poids %d\n",G[i][j].depart,G[i][j].arrivee,G[i][j].nom,G[i][j].poids);
}
