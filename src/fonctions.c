#include "definitions.h"
#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fonctions diverses

int getExperience()
{	//connaitre l'experience du skieur
	char c;
	while(1){
		printf("Etes vous debutant o/n ?\n");
		scanf("%c",&c);
		if (c == 'o')
			return 1;
		if (c == 'n')
			return 0;
		scanf("%c",&c);	//libere le buffer
	}
}

int calculPoids(char* nomArc, int couleur, int temps, int experience)
{	//convertit la couleur et le temps de l'arc en poids en fonction de l'experience du skieur
	//0Vert 1Bleu 2Rouge 3Noir
	double typeRemontee = 1;
	//typeRemontee est le nombre par lequel on multiplie (ou plutot divise) le poids de la remontee en fonction de son type
	
	if (couleur==0)
	{	//Les remontees sont des arcs de couleur 0
		//Plus ce type de remontée est rapide plus son poids va diminuer
		if (strstr(nomArc, "TELEPHERIQUE") != NULL)
			typeRemontee = 0.3;
		if (strstr(nomArc, "FUNITEL") != NULL)
			typeRemontee = 0.5;
		if (strstr(nomArc, "DMC") != NULL)
			typeRemontee = 0.6;
		if (strstr(nomArc, "TELECABINE") != NULL)
			typeRemontee = 0.7;
		if (strstr(nomArc, "TELEMIXSTE") != NULL)
			typeRemontee = 0.8;
		if (strstr(nomArc, "TELESIEGEBULLE") != NULL)
			typeRemontee = 0.85;
		if (strstr(nomArc, "TELESIEGE") != NULL)
			typeRemontee = 0.9;
		return (int)(temps*typeRemontee);
	}
	if (couleur==1)
		return (experience*temps + temps);
	if (couleur==2)
		return (experience*2*temps + temps);
	if (couleur==3)
		return (experience*3*temps + temps);
	return 1000;
}
