#ifndef DEF_DEF
#define DEF_DEF

#include "definitions.h"

#endif

void afficheMenu();
void afficheBoutonDebutant();
void afficheBoutonExpert();
int clicBoutonDebutant(POINT clic);
int clicBoutonExpert(POINT clic);
int clicBoutonMenu(POINT clic);
void afficheCarte();

void drawArc(int depart, int arrivee);

int clicSommet(POINT clic, COULEUR c);
void afficheTexte(char* texte, POINT HG, COULEUR c);
