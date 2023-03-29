#ifndef background_H_INCLUDED
#define background_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>



typedef struct {
SDL_Surface *image_back;
SDL_Rect pos_back;
SDL_Rect camera;
} background;

typedef struct {
Mix_Music *music;
} music;

void init_back(background *bg, int x);
void afficher_back(background bg,SDL_Surface *screen);
void scroll_right(background *bg);
void scroll_left(background *bg);
void init_music (music *m, int volume);
void play_music (music *m);



#endif
