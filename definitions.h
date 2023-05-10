#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define CMode 32

#define SPEED 5


#define SPRITE_H 148
#define SPRITE_W 102
#define MAX_FRAMES 6


typedef struct
{
  SDL_Surface *image;
  SDL_Rect pos;

}bouton;
typedef struct
{
  SDL_Surface *barre[7];
  SDL_Surface *life[8];
  SDL_Surface *bonus[2];
  SDL_Rect pos_barre;
  SDL_Rect pos_life;
  SDL_Rect pos_bonus;
  SDL_Surface *Img_barre;
  SDL_Surface *Img_life;
  SDL_Surface *Img_bonus;

}Extras;
int jeux(SDL_Surface *screen);
int menuson(int *volume);
int help();

