#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL_mixer.h"
#include "animation.h"
#include "scrolling.h"
#include "menu.h"

int main()
{
int joueur;
  SDL_Surface *screen = NULL, *level1 = NULL;
  Perso sprite, start, settings, quitter, jour, set, nuit, newgame, sousmenu, loadgame, clavier, load_newgame, souris, manette, enemy_D[20], box, box2, win;
  int run = 1, i = 2, curseur = 1, actuel, prec, starting = 0, running2 = 1, save = 2, settingss = 0, j = 0, k = 0, souris1 = 0, manette1 = 0, clavier1 = 0, level = 1, nb_life, score_finale, seconde, minute, run2 = 1;
  SDL_Event event;
  SDL_Rect posfond, positionFond;
  Mix_Chunk *effect;
  win.image = IMG_Load("youwon.png");
  win.p.x = 320;
  win.p.y = 100;
  SDL_Init(SDL_INIT_EVERYTHING);
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }

   save=menuu(&joueur) ;










        if (save == 1 || save == 0)
        {

            screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
          running2 = 1;

          if (save)
          { 

            FILE *f = fopen("save_file", "r");
            fscanf(f, "%hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %d %d %d %d %d", &(positionFond.x), &(positionFond.y), &(sprite.p.x), &(sprite.p.y), &(enemy_D[0].p.x), &(enemy_D[0].p.y), &(box.p.x), &(box.p.y), &(box2.p.x), &(box2.p.y), &(nb_life), &(score_finale), &seconde, &minute, &level);
            fclose(f);
            if (level == 1)
              level = scroll1(screen, level1, &running2, posfond, &save, level,joueur);
            if (level == 2)
            {

              running2 = 1;
              level = scroll2(screen, level1, &running2, posfond, &save, level,joueur);
              //level = 3;
            }
            if (level == 3)
            {
              running2 = 1;
              level = scroll3(screen, level1, &running2, posfond, &save, level,joueur);
              if (level== 4)
              {
                while (run2)
                {
                  SDL_BlitSurface(win.image, NULL, screen, &(win.p));
                  SDL_Flip(screen);
                  SDL_WaitEvent(&event);
                  switch (event.type)
                  {

                  case SDL_QUIT:
                    run2 = 0;
                    break;
                  case SDL_KEYDOWN:

                    switch (event.key.keysym.sym)

                    {
                    case SDLK_ESCAPE:
                      run2 = 0;
                      break;
                    }

                    break;
                  }
                }
              }
            }
          }
          else
          {
            level = scroll1(screen, level1, &running2, posfond, &save, level,joueur);
            if (level == 2)
            {
              running2 = 1;
              level = scroll2(screen, level1, &running2, posfond, &save, level,joueur);
            FILE *b = fopen("save", "w");
            fprintf(b,"level= %d",level);
            fclose(b);
              //level = 3;
            }
            if (level == 3)
            {
              running2 = 1;
              level = scroll3(screen, level1, &running2, posfond, &save, level,joueur);
              if (level== 4)
              {
                while (run2)
                {
                  SDL_BlitSurface(win.image, NULL, screen, &(win.p));
                  SDL_Flip(screen);
                  SDL_WaitEvent(&event);
                  switch (event.type)
                  {

                  case SDL_QUIT:
                    run2 = 0;
                    break;
                  case SDL_KEYDOWN:

                    switch (event.key.keysym.sym)

                    {
                    case SDLK_ESCAPE:
                      run2 = 0;
                      break;
                    }

                    break;
                  }
                }
              }
            }
          }
        }
      
      


  
}
