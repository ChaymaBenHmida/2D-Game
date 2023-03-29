/*
commande d'execution
gcc -o game  *.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL_gfx -lm ; ./game
*/

/** 
* @file main.c 
* @brief Testing Program. 
* @author chayma 
* @version 0.1
* @date Apr 2021
* 
* Testing program for background init affichage scrolling nd partage d'ecran * 
*/
#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#include "background.h"

int volume=100;

int main(int argc, char const *argv[]) {

SDL_Init(SDL_INIT_VIDEO);
//creation fenetre
SDL_Surface *screen=NULL;
screen=SDL_SetVideoMode(1100,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF|);

if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }

//declaration et initiliser background 
background bg;
init_back(&bg,1);

/** 
* @brief To initialize the background b . 
* @param bg the background 
* @param 1 the nb of the image  
* @return Nothing 
*/ 


//declaration et initiliser background 2
background bg2;
init_back(&bg2,2);


//initialiser musique fond
music m;
init_music (&m,volume);

/** 
* @brief To initialize the music . 
* @param m variable music
* @param volume   
* @return Nothing 
*/ 

//activer musique
play_music (&m);


//initialiser boucle pseudo infinie
int running=1;

SDL_Event event;
SDL_EnableKeyRepeat(200,0);

while (running) {

  if(SDL_PollEvent(&event)){
    switch (event.type) {
//boutton X rouge de la fenetre
      case SDL_QUIT:
      running=0;
      break;

//avec clavier
      case SDL_KEYDOWN:
switch (event.key.keysym.sym) {

  //scroll bg 1
  case SDLK_RIGHT:
scroll_right(&bg);
  break;
  case SDLK_LEFT:
scroll_left(&bg);
  break;

 //scroll bg 2
  case SDLK_d:
scroll_right(&bg2);
  break;
  case SDLK_q:
scroll_left(&bg2);
  break;
}
      break;

    }

  }//fin poll event

//afficher bg
afficher_back(bg,screen);
afficher_back(bg2,screen);


//rafraichir l'affichage
SDL_Flip(screen);


}//fin while
SDL_Quit();
  return 0;
}

