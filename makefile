p: menuson.o menu.o scrolling.o animation.o collision.o enigf.o level2.o level3.o main.o
	gcc menu.o menuson.o scrolling.o animation.o collision.o enigf.o enig.o level2.o level3.o main.o -o p -lSDL -lSDL_image -lSDL_mixer -g -lm -lSDL_ttf
menuson.o:
	gcc -c menuson.c -lSDL -lSDL_image -lSDL_mixer -g
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_image -lSDL_mixer -g
scrolling.o:scrolling.c
	gcc -c scrolling.c -lSDL -lSDL_image  -g
animation.o:animation.c
	gcc -c animation.c -lSDL -lSDL_image -g
collision.o:collision.c 
	gcc -c collision.c -lSDL -lSDL_image -g
enigf.o:enigf.c
	gcc -c enigf.c -g 	
enig.o:enig.c
        gcc -c enig.c -g  
level2.o:level2.c
	gcc -c level2.c -g 	
level3.o:level3.c
	gcc -c level3.c -g
 
