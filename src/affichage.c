#include "graphics.h"
#include "definitions.h"
#include <stdio.h>

POINT points[V];	//tableau de points de coordonnees des sommets

void colorierSommets()
{
	points[0].x = 573; points[0].y = 556;
	draw_fill_circle(points[0],5,gold); 
	points[1].x = 470; points[1].y = 386;
	draw_fill_circle(points[1],5,gold); 
	points[2].x = 573; points[2].y = 556;
	draw_fill_circle(points[2],5,gold); 
	points[3].x = 573; points[3].y = 556;
	draw_fill_circle(points[3],5,gold); 
	points[4].x = 573; points[4].y = 556;
	draw_fill_circle(points[4],5,gold); 
	points[5].x = 573; points[5].y = 556;
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
	points[11].x = 960; points[11].y = 279;
	draw_fill_circle(points[11],5,gold); 
	points[12].x = 300; points[12].y = 281;
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
	points[42].x = 573; points[42].y = 556;
	draw_fill_circle(points[42],5,gold); 
	points[43].x = 573; points[43].y = 556;
	draw_fill_circle(points[43],5,gold); 
	points[44].x = 573; points[44].y = 556;
	draw_fill_circle(points[44],5,gold); 
}

void drawBigLine(POINT P1, POINT P2, COULEUR c)
{
	draw_line(P1,P2,c);
	
	P1.x -= 1; P2.x -= 1;
	draw_line(P1,P2,c);
	
	P1.x += 2;
	P2.x += 2;
	draw_line(P1,P2,c);
}

void drawTriangle(POINT centre, int rayon, COULEUR c)	//dessine le triangle equilateral inscrit dans le cercle passé en paramètre
{
	POINT A, B, C;
	A.x = centre.x;
	A.y = centre.y + rayon;
	B.x = centre.x - rayon*0.86;
	B.y = centre.y - rayon/2;
	C.x = centre.x + rayon*0.86;
	C.y = centre.y - rayon/2;
	
	draw_fill_triangle(A,B,C,c);
}

void drawFleche(int depart, int arrivee)	//Pour avoir des fleches il faut les afficher les arcs dans l'ordre inverse
{
	if (G[depart][arrivee].poids != 1000)		//si l'arc existe
	{
		switch(G[depart][arrivee].couleur)
		{
			case 0 : 	drawBigLine(points[depart],points[arrivee],vert);	
						drawTriangle(points[arrivee],5,vert);	
						break;
			case 1 : 	drawBigLine(points[depart],points[arrivee],bleu);	
						drawTriangle(points[arrivee],5,bleu);
						break;
			case 2 : 	drawBigLine(points[depart],points[arrivee],rouge); 
						drawTriangle(points[arrivee],5,rouge);	
						break;
			case 3 : 	drawBigLine(points[depart],points[arrivee],noir); 	
						drawTriangle(points[arrivee],5,noir);	
						break;
			default : 	drawBigLine(points[depart],points[arrivee],blanc);
						drawTriangle(points[arrivee],5,blanc);	
						break;
			
		}
		draw_fill_circle(points[depart],5,yellow);
	}
}

int testClic(POINT clic)	//renvoie l'indice du sommet clique, -1 sinon
{
	int i;
	for (i = 0; i < V; i++)
	{
		if (clic.x < points[i].x + 5 && clic.x > points[i].x - 5 && clic.y < points[i].y + 5 && clic.y > points[i].y - 5)
		{
			draw_fill_circle(points[i],5,vert);
			return i;
		}
	}
	
	return -1;
}

void afficheFenetre()
{
	init_graphics(1032,617);
	POINT bg; bg.x = 0; bg.y = 617;
	affiche_image("../data/map.bmp",bg,1032,617);
	
	colorierSommets();
	drawFleche(0,1);
	drawFleche(1,12);
	drawFleche(0,11);
	
	POINT sommetDepart;
	do{
	sommetDepart = wait_clic();
	printf("test : %d\n",testClic(sommetDepart));
	}
	while (sommetDepart.y < 600);
	
	wait_escape();
}

