#include "definitions.h"
#include <stdio.h>
#include <string.h>

void afficheMenu()
{
	affiche_auto_off();
	POINT bg; bg.x = 0; bg.y = 600;
	affiche_image("../data/img/menu.bmp",bg,1100,600);
	affiche_all();
}
void afficheBoutonDebutant()
{
	POINT bg; bg.x = 0; bg.y = 600;
	affiche_image("../data/img/menu1.bmp",bg,1100,600);
	affiche_all();
	attendre(150);
}
void afficheBoutonExpert()
{
	POINT bg; bg.x = 0; bg.y = 600;
	affiche_image("../data/img/menu2.bmp",bg,1100,600);
	affiche_all();
	attendre(150);
}
int clicBoutonDebutant(POINT clic)
{
	if (clic.x > 300 && clic.x < 800 && clic.y < 340 && clic.y > 240)
		return 1;
	return 0;
}
int clicBoutonExpert(POINT clic)
{
	if (clic.x > 300 && clic.x < 800 && clic.y < 194 && clic.y > 94)
		return 1;
	return 0;
}
int clicBoutonMenu(POINT clic)
{
	if (clic.x > 15 && clic.x < 150 && clic.y < 587 && clic.y > 532)
		return 1;
	return 0;
}

void colorierSommets()
{	//Dessine des cercles pour représenter les sommets sur la carte, chaque sommet étant repréré par un indice (voir sommets.txt)
	//tout en stockant les coordonnées de chaque sommet dans le tableau points
	points[0].x = 425; points[0].y = 511;
	draw_fill_circle(points[0],5,gold); 
	points[1].x = 354; points[1].y = 384;
	draw_fill_circle(points[1],5,gold); 
	points[2].x = 449; points[2].y = 480;
	draw_fill_circle(points[2],5,gold); 
	points[3].x = 520; points[3].y = 446;
	draw_fill_circle(points[3],5,gold); 
	points[4].x = 488; points[4].y = 411;
	draw_fill_circle(points[4],5,gold); 
	points[5].x = 411; points[5].y = 365;
	draw_fill_circle(points[5],5,gold); 
	points[6].x = 573; points[6].y = 556;
	draw_fill_circle(points[6],5,gold); 
	points[7].x = 573; points[7].y = 556;
	draw_fill_circle(points[7],5,gold); 
	points[8].x = 573; points[8].y = 556;
	draw_fill_circle(points[8],5,gold); 
	points[9].x = 573; points[9].y = 556;
	draw_fill_circle(points[9],5,gold); 
	points[10].x = 573; points[10].y = 556;
	draw_fill_circle(points[10],5,gold); 
	points[11].x = 400; points[11].y = 279;
	draw_fill_circle(points[11],5,gold); 
	points[12].x = 213; points[12].y = 277;
	draw_fill_circle(points[12],5,gold); 
	points[13].x = 573; points[13].y = 556;
	draw_fill_circle(points[13],5,gold); 
	points[14].x = 573; points[14].y = 556;
	draw_fill_circle(points[14],5,gold); 
	points[15].x = 573; points[15].y = 556;
	draw_fill_circle(points[15],5,gold); 
	points[16].x = 573; points[16].y = 556;
	draw_fill_circle(points[16],5,gold); 
	points[17].x = 573; points[17].y = 556;
	draw_fill_circle(points[17],5,gold); 
	points[18].x = 573; points[18].y = 556;
	draw_fill_circle(points[18],5,gold); 
	points[19].x = 573; points[19].y = 556;
	draw_fill_circle(points[19],5,gold); 
	points[20].x = 573; points[20].y = 556;
	draw_fill_circle(points[20],5,gold); 
	points[21].x = 573; points[21].y = 556;
	draw_fill_circle(points[21],5,gold); 
	points[22].x = 573; points[22].y = 556;
	draw_fill_circle(points[22],5,gold); 
	points[23].x = 573; points[23].y = 556;
	draw_fill_circle(points[23],5,gold); 
	points[24].x = 573; points[24].y = 556;
	draw_fill_circle(points[24],5,gold); 
	points[25].x = 573; points[25].y = 556;
	draw_fill_circle(points[25],5,gold); 
	points[26].x = 573; points[26].y = 556;
	draw_fill_circle(points[26],5,gold); 
	points[27].x = 573; points[27].y = 556;
	draw_fill_circle(points[27],5,gold); 
	points[28].x = 573; points[28].y = 556;
	draw_fill_circle(points[28],5,gold); 
	points[29].x = 573; points[29].y = 556;
	draw_fill_circle(points[29],5,gold); 
	points[30].x = 573; points[30].y = 556;
	draw_fill_circle(points[30],5,gold); 
	points[31].x = 573; points[31].y = 556;
	draw_fill_circle(points[31],5,gold); 
	points[32].x = 573; points[32].y = 556;
	draw_fill_circle(points[32],5,gold); 
	points[33].x = 573; points[33].y = 556;
	draw_fill_circle(points[33],5,gold); 
	points[34].x = 573; points[34].y = 556;
	draw_fill_circle(points[34],5,gold); 
	points[35].x = 573; points[35].y = 556;
	draw_fill_circle(points[35],5,gold); 
	points[36].x = 573; points[36].y = 556;
	draw_fill_circle(points[36],5,gold); 
	points[37].x = 573; points[37].y = 556;
	draw_fill_circle(points[37],5,gold); 
	points[38].x = 573; points[38].y = 556;
	draw_fill_circle(points[38],5,gold); 
	points[39].x = 573; points[39].y = 556;
	draw_fill_circle(points[39],5,gold); 
	points[40].x = 573; points[40].y = 556;
	draw_fill_circle(points[40],5,gold); 
	points[41].x = 573; points[41].y = 556;
	draw_fill_circle(points[41],5,gold); 
	points[42].x = 297; points[42].y = 409;
	draw_fill_circle(points[42],5,gold); 
	points[43].x = 573; points[43].y = 556;
	draw_fill_circle(points[43],5,gold); 
	points[44].x = 573; points[44].y = 556;
	draw_fill_circle(points[44],5,gold); 
}

void afficheCarte()
{
	POINT bg; bg.x = 0; bg.y = 600;
	affiche_image("../data/img/map1.bmp",bg,1100,600);
	colorierSommets();	//affiche un cercle sur tous les sommets
	affiche_all();
}

int clicSommet(POINT clic, COULEUR c)	
{	//renvoie l'indice du sommet cliqué et -1 sinon
	int i;
	for (i = 0; i < V; i++)
	{
		if (clic.x < points[i].x + 5 && clic.x > points[i].x - 5 && clic.y < points[i].y + 5 && clic.y > points[i].y - 5)
		{
			draw_fill_circle(points[i],5,c);
			affiche_all();
			return i;
		}
	}
	return -1;
}

void afficheTexte(char* texte, POINT HG, COULEUR c)
{
	int taille = 0, longeur = strlen(texte);

	if (longeur <= 13)
	{
		HG.x += (13 - longeur)*6;
		taille = 25;
	}
	else if (longeur <= 20)
	{
		HG.x += (20 - longeur)*2;
		taille = 20;
	}
	else if (longeur <= 25)
	{
		HG.x += (25 - longeur)/3;
		taille = 15;
	}
	else if (longeur <= 30)
	{
		HG.x += (30 - longeur)/5;
		taille = 10;
	}
	else 
	{
		HG.x += (40 - longeur)/10;
		taille = 12;
	}
	aff_pol(texte, taille, HG, c);
	affiche_all();
}

void drawBigLine(POINT P1, POINT P2, COULEUR c)
{	//Dessine un grand trait entre 2 points
	draw_line(P1,P2,c);
	
	P1.x -= 1; P2.x -= 1;
	draw_line(P1,P2,c);
	
	P1.x += 2;
	P2.x += 2;
	draw_line(P1,P2,c);
}

void drawArc(int depart, int arrivee)
{	//Dessine un arc colorié entre le sommet de départ et le sommet d'arrivée, chaque sommet étant repréré par un indice (voir sommets.txt)
	if (G[depart][arrivee].poids != 1000)	//si l'arc existe
	{
		switch(G[depart][arrivee].couleur)
		{
			case 0 : 	drawBigLine(points[depart],points[arrivee],vert);
						break;
			case 1 : 	drawBigLine(points[depart],points[arrivee],bleu);
						break;
			case 2 : 	drawBigLine(points[depart],points[arrivee],rouge); 
						break;
			case 3 : 	drawBigLine(points[depart],points[arrivee],gris);
						break;
			case 4 : 	drawBigLine(points[depart],points[arrivee],noir);
						break;
			default : 	drawBigLine(points[depart],points[arrivee],blanc);
						break;
		}
		draw_fill_circle(points[depart],5,yellow);
		affiche_all();
	}
}

