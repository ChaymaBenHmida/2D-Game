#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"


#define width 1280
#define height 720

#define b_w 303 //button width
#define b_h 109  //button height

typedef struct 
{

  SDL_Surface *img ;
  SDL_Rect pos ;
  SDL_Rect pos_text  ;

  
}Objet ;

int menuu (int *j) ;
void initialiser (Objet *game,Objet *newgame,Objet *loadgame ,Objet *settings,Objet *exit ) ;
void update_menu (SDL_Surface *screen , Objet *surface1) ;
int verif_motion_surface (SDL_Event event,Objet surface) ;
void mouse_motion_main_menu (SDL_Surface *screen ,SDL_Event event,Mix_Chunk *effect,int *curseur,Objet newgame,Objet exit,Objet loadgame,Objet settings) ;
void mouse_clic_main_menu (SDL_Event event,int * curseur,int *running,int *running2,Objet newgame,Objet exit,Objet loadgame,Objet settings) ;
void liberate (Objet *game,Objet *newgame,Objet *loadgame ,Objet *settings,Objet *exit) ;
