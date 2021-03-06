#include "fonctions.h"

//Pour éviter les Warnings "implicit declaration"
extern void afficheMenu();
extern int clicBoutonDebutant(POINT choix);
extern int clicBoutonExpert(POINT choix);
extern void afficheBoutonDebutant();
extern void afficheBoutonExpert();
extern void lectureGraphe(char* nomFichier, Arc G[V][V], int experience);

int main(int argc, char* argv[])
{
	init_graphics(1100,600);	//fenetre fixée à 1100x600
	
	while (1)
	{	
		afficheMenu();
		
		POINT choix = wait_clic();
	
		if ( clicBoutonDebutant(choix) )
		{
			afficheBoutonDebutant();
			
			lectureGraphe("../data/graphe.txt",G, DEBUTANT);	//lecture du graphe à partir du fichier le représentant et le stocker dans G
			
			itineraire(G);	//fonction principale, demande un sommet de départ et un sommet d'arrivée et recherche le + court chemin
		}
		else if ( clicBoutonExpert(choix) )
		{
			afficheBoutonExpert();
			
			lectureGraphe("../data/graphe.txt",G, EXPERT);		//lecture du graphe à partir du fichier le représentant et le stocker dans G
			
			itineraire(G);	//fonction principale, demande un sommet de départ et un sommet d'arrivée et recherche le + court chemin
		}
	}
	wait_escape();
	
	return 0;
}
