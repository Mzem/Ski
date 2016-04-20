#include "fonctions.h"
#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fonctions concernant la lecture et le traitement des éléments du graphe

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
		return "SOMMET 3060";
	if (indiceSommet==3)
		return "SARENNE BASSE";
	if (indiceSommet==4)
		return "CLOCHER DE MACLE";
	if (indiceSommet==5)
		return "LAC BLANC";
	if (indiceSommet==6)
		return "LIEVRE BLANC";
	if (indiceSommet==7)
		return "PLAT DES MARMOTTES";
	if (indiceSommet==8)
		return "MINE DE L'HERPIE";
	if (indiceSommet==9)
		return "SOMMET 2100";
	if (indiceSommet==10)
		return "SOMMET DES VACHETTES";
	if (indiceSommet==11)
		return "SIGNAL DE L'HOMME";
	if (indiceSommet==12)
		return "L'ALPETTE";
	if (indiceSommet==13)
		return "COL DU COUARD";
	if (indiceSommet==14)
		return "CASCADE";
	if (indiceSommet==15)
		return "CLOS GIRAUD";
	if (indiceSommet==16)
		return "MONFRAIS";
	if (indiceSommet==17)
		return "SIGNAL";
	if (indiceSommet==18)
		return "RIFNEL EXPRESS";
	if (indiceSommet==19)
		return "CHALVET";
	if (indiceSommet==20)
		return "AURIS EXPRESS";
	if (indiceSommet==21)
		return "FONTFROIDE";
	if (indiceSommet==22)
		return "LOUVETS";
	if (indiceSommet==23)
		return "POUTRAN";
	if (indiceSommet==24)
		return "CHAMP CLOTURE";
	if (indiceSommet==25)
		return "STADE";
	if (indiceSommet==26)
		return "SCHUSS";
	if (indiceSommet==27)
		return "ALPE D'HUEZ";
	if (indiceSommet==28)
		return "GRANDE SURE";
	if (indiceSommet==29)
		return "ECLOSE";
	if (indiceSommet==30)
		return "SURES";
	if (indiceSommet==31)
		return "COL";
	if (indiceSommet==32)
		return "AURIS EN OISANS";
	if (indiceSommet==33)
		return "LA VILLETTE";
	if (indiceSommet==34)
		return "VAUJANY";
	if (indiceSommet==35)
		return "L'EVERSIN D'OZ";
	if (indiceSommet==36)
		return "OZ EN OISANS";
	if (indiceSommet==37)
		return "PETIT PRINCE";
	if (indiceSommet==38)
		return "VILLAGE";
	if (indiceSommet==39)
		return "MARONNE";
	if (indiceSommet==40)
		return "VILLARD RECULAS";
	if (indiceSommet==41)
		return "HUEZ";
	if (indiceSommet==42)
		return "DOME DES PETITES ROUSSES";
	if (indiceSommet==43)
		return "ALPAURIS";
	if (indiceSommet==44)
		return "L'ALPETTE BASSE";
		
	return "SOMMET INCONNU";
}

int indiceSommet(char* nomSommet)
{	//prend un indice de sommet et retourne le nom du sommet correspondant
	 if (!strcmp(nomSommet,"PIC_BLANC"))
		return 0;
	 if (!strcmp(nomSommet,"GROTTE_DE_GLACE"))
		return 1;
	 if (!strcmp(nomSommet,"SOMMET_3060"))
		return 2;
	 if (!strcmp(nomSommet,"SARENNE_BASSE"))
		return 3;
	 if (!strcmp(nomSommet,"CLOCHER_DE_MACLE"))
		return 4;
	 if (!strcmp(nomSommet,"LAC_BLANC"))
		return 5;
	 if (!strcmp(nomSommet,"LIEVRE_BLANC"))
		return 6;
	 if (!strcmp(nomSommet,"PLAT_DES_MARMOTTES"))
		return 7;
	 if (!strcmp(nomSommet,"MINE_DE_L'HERPIE"))
		return 8;
	 if (!strcmp(nomSommet,"SOMMET_2100"))
		return 9;
	 if (!strcmp(nomSommet,"SOMMET_DES_VACHETTES"))
		return 10;
	 if (!strcmp(nomSommet,"SIGNAL_DE_L'HOMME"))
		return 11;
	 if (!strcmp(nomSommet,"L'ALPETTE"))
		return 12;
	 if (!strcmp(nomSommet,"COL_DU_COUARD"))
		return 13;
	 if (!strcmp(nomSommet,"CASCADE"))
		return 14;
	 if (!strcmp(nomSommet,"CLOS_GIRAUD"))
		return 15;
	 if (!strcmp(nomSommet,"MONFRAIS"))
		return 16;
	 if (!strcmp(nomSommet,"SIGNAL"))
		return 17;
	 if (!strcmp(nomSommet,"RIFNEL_EXPRESS"))
		return 18;
	 if (!strcmp(nomSommet,"CHALVET"))
		return 19;
	 if (!strcmp(nomSommet,"AURIS_EXPRESS"))
		return 20;
	 if (!strcmp(nomSommet,"FONTFROIDE"))
		return 21;
	 if (!strcmp(nomSommet,"LOUVETS"))
		return 22;
	 if (!strcmp(nomSommet,"POUTRAN"))
		return 23;
	 if (!strcmp(nomSommet,"CHAMP_CLOTURE"))
		return 24;
	 if (!strcmp(nomSommet,"STADE"))
		return 25;
	 if (!strcmp(nomSommet,"SCHUSS"))
		return 26;
	 if (!strcmp(nomSommet,"ALPE_D'HUEZ"))
		return 27;
	 if (!strcmp(nomSommet,"GRANDE_SURE"))
		return 28;
	 if (!strcmp(nomSommet,"ECLOSE"))
		return 29;
	 if (!strcmp(nomSommet,"SURES"))
		return 30;
	 if (!strcmp(nomSommet,"COL"))
		return 31;
	 if (!strcmp(nomSommet,"AURIS_EN_OISANS"))
		return 32;
	 if (!strcmp(nomSommet,"LA_VILLETTE"))
		return 33;
	 if (!strcmp(nomSommet,"VAUJANY"))
		return 34;
	 if (!strcmp(nomSommet,"L'EVERSIN_D OZ"))
		return 35;
	 if (!strcmp(nomSommet,"OZ_EN_OISANS"))
		return 36;
	 if (!strcmp(nomSommet,"PETIT_PRINCE"))
		return 37;
	 if (!strcmp(nomSommet,"VILLAGE"))
		return 38;
	 if (!strcmp(nomSommet,"MARONNE"))
		return 39;
	 if (!strcmp(nomSommet,"VILLARD_RECULAS"))
		return 40;
	 if (!strcmp(nomSommet,"HUEZ"))
		return 41;
	 if (!strcmp(nomSommet,"DOME_DES_PETITES_ROUSSES"))
		return 42;
	 if (!strcmp(nomSommet,"ALPAURIS"))
		return 43;
	 if (!strcmp(nomSommet,"L'ALPETTE_BASSE"))
		return 44;
	return 200;		//Sommet 200 n'existe pas donc sommet inconnu, donc pas de chemin
}

char* nomArc(int indiceArc)
{	//prend un indice d'arc et retourne le nom de l'arc correspondant
	if (indiceArc==0)
		return "descente SARENNE HAUTE / CHATEAU NOIR";
 	if (indiceArc==1)
		return "descente GLACIER";
 	if (indiceArc==2)
		return "descente BRECHE";
 	if (indiceArc==3)
		return "descente TUNNEL";
	if (indiceArc==4)
		return " descente CRISTAILLERE";
 	if (indiceArc==5)
		return "descente SARENNE BASSE";
 	if (indiceArc==6)
		return "descente DOME";
 	if (indiceArc==7)
		return "descente LAC BLANC";
 	if (indiceArc==8)
		return "descente PROMONTOIRE";
 	if (indiceArc==9)
		return "descente COMBE CHARBONNIERE";
 	if (indiceArc==10)
		return "descente ROUSSES";
 	if (indiceArc==11)
		return "descente CHAMOIS";
 	if (indiceArc==12)
		return "descente ANCOLIES";
 	if (indiceArc==13)
		return "descente CANYON";
 	if (indiceArc==14)
		return "descente CAMPANULES";
 	if (indiceArc==15)
		return "descente COL DE CLUY";
	if (indiceArc==16)
		return " descente VERNETTES";
 	if (indiceArc==17)
		return "descente CHALVET-ALPAURIS";
 	if (indiceArc==18)
		return "descente ETERLOUS";
 	if (indiceArc==19)
		return "descente FONTFROIDE";
 	if (indiceArc==20)
		return "descente PRE-ROND";
 	if (indiceArc==21)
		return "descente COL 1";
 	if (indiceArc==22)
		return "descente LES FARCIS";
 	if (indiceArc==23)
		return "descente GENTIANES";
 	if (indiceArc==24)
		return "descente COL 2";
 	if (indiceArc==25)
		return "descente CORNICHE";
	if (indiceArc==26)
		return " descente FONTFROIDE-LOUVETS";
	if (indiceArc==27)
		return " descente BARTAVELLES";
 	if (indiceArc==28)
		return "descente POUTRAN";
 	if (indiceArc==29)
		return "descente JEUX";
 	if (indiceArc==30)
		return "descente AGNEAUX";
 	if (indiceArc==31)
		return "descente LES BERGES";
 	if (indiceArc==32)
		return "descente LOUP BLANC";
 	if (indiceArc==33)
		return "descente POUSSINS";
 	if (indiceArc==34)
		return "descente ANEMONES";
 	if (indiceArc==35)
		return "descente SIGNAL-STADE";
 	if (indiceArc==36)
		return "descente SIGNAL";
 	if (indiceArc==37)
		return "descente SCHUSS-ECLOSE";
 	if (indiceArc==38)
		return "descente SCHUSS-GRANDE SURE";
 	if (indiceArc==39)
		return "descente ECLOSE-GRANDE SURE";
 	if (indiceArc==40)
		return "descente VILLAGE 1";
 	if (indiceArc==41)
		return "descente HUEZ";
 	if (indiceArc==42)
		return "descente VILLAGE 2";
 	if (indiceArc==43)
		return "descente PETIT PRINCE";
 	if (indiceArc==44)
		return "descente LA FORET";
 	if (indiceArc==45)
		return "descente L'OLMET";
 	if (indiceArc==46)
		return "descente CHAMPCLOTURY";
 	if (indiceArc==47)
		return "descente ALPETTE";
 	if (indiceArc==48)
		return "descente LUTINS";
 	if (indiceArc==49)
		return "descente CARRELET";
 	if (indiceArc==50)
		return "descente CHALETS";
 	if (indiceArc==51)
		return "descente LA FARE";
 	if (indiceArc==52)
		return "descente CASCADE";
 	if (indiceArc==53)
		return "descente ETOURNEAUX";
 	if (indiceArc==54)
		return "descente EDELWEISS";
 	if (indiceArc==55)
		return "descente VAUJANIATE";
 	if (indiceArc==56)
		return "descente VILLARD";
 	if (indiceArc==100)
		return "TELEPHERIQUE PIC BLANC";
 	if (indiceArc==101)
		return "TELESIEGE GLACIER";
 	if (indiceArc==102)
		return "TELESIEGE HERPIE";
 	if (indiceArc==103)
		return "FUNITEL MARMOTTES III";
 	if (indiceArc==104)
		return "TELESIEGE LAC BLANC";
 	if (indiceArc==105)
		return "TELEPHERIQUE ALPETTE-ROUSSES";
	if (indiceArc==106)
		return " DMC 2EME TRONCON";
 	if (indiceArc==107)
		return "TELESIEGE LIEVRE BLANC";
 	if (indiceArc==108)
		return "TELECABINE MARMOTTES II";
 	if (indiceArc==109)
		return "TELECABINE POUTRAN II";
 	if (indiceArc==110)
		return "DMC 1ER TRONCON";
 	if (indiceArc==111)
		return "TELESIEGE ROMAINS";
 	if (indiceArc==112)
		return "TELESIEGEBULLE MARMOTTES I";
 	if (indiceArc==113)
		return "TELEMIXTE RIFNEL EXPRESS";
 	if (indiceArc==114)
		return "TELESIEGE SIGNAL";
 	if (indiceArc==115)
		return "TELESKI STADE";
 	if (indiceArc==116)
		return "TELESKI ECLOSE-SCHUSS";
 	if (indiceArc==117)
		return "TELESIEGE GRANDE SURE";
 	if (indiceArc==118)
		return "TELECABINE TELEVILLAGE";
 	if (indiceArc==119)
		return "TELESIEGE BERGERS";
 	if (indiceArc==120)
		return "TELESKI PETIT PRINCE";
 	if (indiceArc==121)
		return "TELESIEGE TSD LE VILLARAIS";
 	if (indiceArc==122)
		return "TELESIEGE ALPAURIS-ALPE D'HUEZ";
 	if (indiceArc==123)
		return "TELESIEGE CHALVET";
 	if (indiceArc==124)
		return "TELESIEGE FONTFROIDE";
 	if (indiceArc==125)
		return "TELESIEGE LOUVETS";
 	if (indiceArc==126)
		return "TELESIEGE ALPAURIS";
 	if (indiceArc==127)
		return "TELESIEGE AURIS EXPRESS";
 	if (indiceArc==128)
		return "TELESKI COL";
 	if (indiceArc==129)
		return "TELESIEGE SURES";
 	if (indiceArc==130)
		return "TELESIEGE MARONNE";
 	if (indiceArc==131)
		return "TELECABINE L'ALPETTE";
 	if (indiceArc==132)
		return "TELESKI L'ALPETTE";
 	if (indiceArc==133)
		return "TELECABINE POUTRAN I";
 	if (indiceArc==134)
		return "TELESKI HAMP CLOTURE";
 	if (indiceArc==135)
		return "TELEPHERIQUE VAUJANY-ALPETTE";
 	if (indiceArc==136)
		return "TELESIEGE CLOS GIRAUD";
 	if (indiceArc==137)
		return "TELESKI MONTFRAIS";
 	if (indiceArc==138)
		return "TELESIEGE MONTFRAIS";
 	if (indiceArc==138)
		return "TELESIEGE VALLONNET";
 	if (indiceArc==140)
		return "TELECABINE VILLETTE-MONTFRAIS";
 	if (indiceArc==141)
		return "TELECABINE VAUJANY-VILLETTE";
 	if (indiceArc==142)
		return "TELECABINE VAUJANY-ENVERSIN";
	return "ARC INCONNU";
}


void lectureGraphe(char* nomFichier, Arc G[V][V])
{	//Lit le graphe à partir du fichier fourni
	FILE* F = fopen(nomFichier,"r");	//doit etre deja present, sinon NULL
	
	if (F == NULL){
		printf("fichier du graphe introuvable\n");
		return;
	}
	
	int k, temps, experience = getExperience();
	
	initialise(G);
		
	for (k = 0; k < E; k++)		//boucle qui parcourt les lignes du fichier : E lignes <=> E arcs
	{
		int i, j, indiceArc, couleur;
		//i : indiceSommetDepart, j : indiceSommetArrivee
		
		fscanf(F,"%d %d %d %d %d",&i, &j, &indiceArc, &couleur, &temps);

		G[i][j].nom = nomArc(indiceArc);
		G[i][j].depart = nomSommet(i);
		G[i][j].arrivee = nomSommet(j);
		G[i][j].couleur = couleur;
		G[i][j].poids = calculPoids(G[i][j].nom, couleur,temps,experience);
	}
	
	fclose(F);
}

void afficheGraphe(Arc G[V][V])
{	//Un affichage détaillé des arcs du graphe pour tester la lecture
	printf("\n######################################### AFFICHAGE DU GRAPHE #########################################\n");
	int i,j;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			if (G[i][j].poids!=1000)
				printf("%s   ->   %s   :   %s de poids %d\n",G[i][j].depart,G[i][j].arrivee,G[i][j].nom,G[i][j].poids);
}
