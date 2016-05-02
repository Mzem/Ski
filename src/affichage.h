#ifndef DEF_DEF
#define DEF_DEF

#include "definitions.h"

#endif

//Fonctions qui gèrent l'interface graphique

void afficheMenu();
void afficheBoutonDebutant();
void afficheBoutonExpert();
void afficheBoutonRecommencer();
int clicBoutonDebutant(POINT clic);
int clicBoutonExpert(POINT clic);
int clicBoutonMenu(POINT clic);
int clicBoutonRecommencer(POINT clic);

void afficheCarte();	//Affiche l'image de la carte et un cercle sur chaque sommet

int clicSommet(POINT clic, COULEUR c);	//Retourne l'indice du sommet cliqué et -1 sinon

void afficheTexte(char* texte, POINT HG, COULEUR c);
void drawArc(int depart, int arrivee);
