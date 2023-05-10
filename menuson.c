#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "definitions.h"

void init(bouton b[4])
{
b[0].image = IMG_Load("voice.png");
b[1].image = IMG_Load("fullscreen.png");
b[2].image = IMG_Load("exit1.png");
b[3].image = IMG_Load("exit2.png");


b[0].pos.x = -40;
b[1].pos.x = 150;
b[2].pos.x = 300;
b[3].pos.x = 450;

b[0].pos.y = 130;
b[1].pos.y = 140;
b[2].pos.y = 80;
b[3].pos.y = 120;

}

int menuson(int *volume)

{
SDL_Init(SDL_INIT_VIDEO);

SDL_Surface *ecran = NULL, *bg = NULL;
bouton b[4];
SDL_Rect pos;
int i;

pos.x=0;
pos.y=0;


ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("SETTINGS", NULL);

init(b);
bg = IMG_Load("selectt.png");
SDL_BlitSurface(bg,NULL,ecran,&pos);
for (i=0;i<4;i++)
SDL_BlitSurface(b[i].image, NULL, ecran, &(b[i].pos));
SDL_Flip(ecran);

int continuer = 1;
SDL_Event event;


while(continuer)
{
   SDL_PollEvent(&event);

     if (event.type == SDL_QUIT)
     {
       continuer = 0;

     }
     else if( event.type == SDL_MOUSEBUTTONDOWN )
     {

        if( event.button.button == SDL_BUTTON_LEFT )
        {
   //VOLUME ON OFF
          if ((event.button.x > b[0].pos.x) && (event.button.x < b[0].pos.x + b[0].pos.w) && (event.button.y > b[0].pos.y) && (event.button.y < b[0].pos.y + b[0].pos.h))
            {
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[0].image, NULL, ecran, &(b[0].pos));
              SDL_BlitSurface(b[1].image, NULL, ecran, &(b[1].pos));
              SDL_BlitSurface(b[2].image, NULL, ecran, &(b[2].pos));
             
             

              if(Mix_PausedMusic() == 1)//Si la musique est en pause
                    {
                        Mix_ResumeMusic(); //Reprendre la musique
                        SDL_BlitSurface(b[0].image, NULL, ecran, &(b[0].pos));
                    }
                    else
                    {
                        Mix_PauseMusic(); //Mettre en pause la musique
                        SDL_BlitSurface(b[0].image, NULL, ecran, &(b[0].pos));
                    }
              SDL_Flip(ecran);
            }
// Fullscreen
else if ((event.button.x > b[1].pos.x) && (event.button.x < b[1].pos.x + b[1].pos.w) && (event.button.y > b[1].pos.y) && (event.button.y < b[1].pos.y + b[1].pos.h))
            {
              SDL_WM_ToggleFullScreen(ecran);
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[0].image, NULL, ecran, &(b[0].pos));
              SDL_BlitSurface(b[1].image, NULL, ecran, &(b[1].pos));
              SDL_BlitSurface(b[2].image, NULL, ecran, &(b[2].pos));
              
             

              SDL_Flip(ecran);
            }

//QUIT
else if ((event.button.x > b[2].pos.x) && (event.button.x < b[2].pos.x + b[2].pos.w) && (event.button.y > b[2].pos.y) && (event.button.y < b[2].pos.y + b[2].pos.h))
            {
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[0].image, NULL, ecran, &(b[0].pos));
              SDL_BlitSurface(b[1].image, NULL, ecran, &(b[1].pos));
              SDL_BlitSurface(b[3].image, NULL, ecran, &(b[3].pos));
              SDL_Flip(ecran);
              continuer =0;
              
            }




        }}}}





Extras initialisation_extra(Extras e)
{

         e.barre[0] = IMG_Load("1.png");
         e.barre[1] = IMG_Load("2.png");
         e.barre[2] = IMG_Load("3.png");
         e.barre[3] = IMG_Load("4.png");
         e.barre[4] = IMG_Load("5.png");
         e.barre[5] = IMG_Load("6.png");
         e.barre[6] = IMG_Load("7.png");
e.Img_barre = e.barre[0];

e.pos_barre.x = 5;
e.pos_barre.y =5;
         e.life[0] = IMG_Load("6vies.png");
         e.life[1] = IMG_Load("5vies.png");
         e.life[2] = IMG_Load("4vies.png");
         e.life[3] = IMG_Load("3vies.png");
         e.life[4] = IMG_Load("2vies.png");
         e.life[5] = IMG_Load("1vie.png");
         e.life[6] = IMG_Load("0vies.png");
         e.life[7] = IMG_Load("novie.png");
e.pos_life.x = 220;
e.pos_life.y= 5;
e.Img_life = e.life[0];
         e.bonus[0] = IMG_Load("bonus.png");
         e.bonus[1] = IMG_Load("artefact.png");
         e.pos_bonus.x = 800;
         e.pos_bonus.y = 80;
         e.Img_bonus = e.bonus[0];

return e;
}
