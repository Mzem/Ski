all: ski
	make clean

run:	ski
		./ski
		
ski: 	main.o graphe.o fonctions.o dijkstra.o affichage.o graphics.o
			gcc -g -Wall main.o graphe.o fonctions.o dijkstra.o affichage.o graphics.o -o ski `sdl-config --libs` -lSDL_ttf -lm
		
main.o:	main.c graphe.h dijkstra.h affichage.h
		gcc -c -Wall main.c

graphe.o:	graphe.c fonctions.h definitions.h
				gcc -c -Wall graphe.c

fonctions.o:	fonctions.c
				gcc -c -Wall fonctions.c

dijkstra.o:	dijkstra.c graphe.h
				gcc -c -Wall dijkstra.c

affichage.o : affichage.c graphics.h definitions.h
				gcc -c -Wall affichage.c

#construit le fichier binaire graphics.o
graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics.c

clean:
	rm *.o
	rm ski
