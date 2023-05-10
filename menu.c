#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "menu2.h"


int menuu(int *j)
{
  TTF_Init();

 int save =2 ;
  if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) < 0)
  {
    printf("Unable to open audio!\n");
    exit(1);
  }
  Mix_Music *song = NULL; //format mp3
  Mix_Music *intro = NULL;
  Mix_Chunk *click = NULL; //format wav

  Mix_VolumeMusic(MIX_MAX_VOLUME);
  intro = Mix_LoadMUS("gamemenu/intro.ogg");
  Mix_PlayMusic(intro, MIX_MAX_VOLUME);
  ecran = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE);
  posbackground.x = 0;
  posbackground.y = 0;
  while (y < 160)
  {
    sprintf(menu, "gamemenu/intro/%d.png", y);
    intro_[y] = IMG_Load(menu);
    SDL_BlitSurface(intro_[y], NULL, ecran, &posbackground);
    SDL_Delay(20);
    y++;
    SDL_Flip(ecran); //vider le cache

    SDL_FreeSurface(intro_[y]); //refrech
  }

  y = 0;
  while (y < 300)
  {
    sprintf(menu, "gamemenu/intro2/%d.jpg", y);
    intro2_[y] = IMG_Load(menu);
    SDL_BlitSurface(intro2_[y], NULL, ecran, &posbackground);
    SDL_Delay(20);
    y++;
    SDL_Flip(ecran);
    SDL_FreeSurface(intro2_[y]);
  }

  //fonction predifenie fel bibliotheque sdl1.2
  click = Mix_LoadWAV("gamemenu/bref.ogg");
  Mix_VolumeMusic(MIX_MAX_VOLUME);
  //Mix_PlayMusic(song, MIX_MAX_VOLUME);
  police = TTF_OpenFont("gamemenu/police.ttf", 65);
  texte = TTF_RenderText_Blended(police, "THE FLESH PREVAILS", CN); 

  while (run)
  {                                                         // madamo ye5dem
    ecran = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE); // kobr fenetre

    SDL_WM_SetCaption("THE FLESH PREVAILS ", NULL); //ktiba bare fo9

    
    posplay1.x = 28+350;
    posplay1.y = 200;

    possetting1.x = 28+350;
    possetting1.y = 308;

    posexit1.x = 28+350;
    posexit1.y = 410;

    posplay2.x = 28+350;
    posplay2.y = 200;

    possetting2.x = 28+350;
    possetting2.y = 308;

    posexit2.x = 28+350;
    posexit2.y = 410;


    posson.x = 100; // ta3 sous menu
    posson.y = 300;
    on.x = 300;
    on.y = 300;
    of.x = 500;
    of.y = 300;
    posback.x = 500;
    posback.y = 500;
    text.x = 50;
    text.y = 0;
    posjoystic.x = 543;
    posjoystic.y = 89;
    posclavier.x = 328;
    posclavier.y = 96;
    possouris.x = 152;
    possouris.y = 92;

    x = 2;
    background = IMG_Load("gamemenu/menu.jpg"); // tjiblek el imqge

    play = IMG_Load("gamemenu/play.png");
    setting = IMG_Load("gamemenu/setting.png");

    exite = IMG_Load("gamemenu/exit.png");
    play2 = IMG_Load("gamemenu/play2.png");
    setting2 = IMG_Load("gamemenu/setting2.png");

    exit2 = IMG_Load("gamemenu/exit3.png");
    son = IMG_Load("gamemenu/son.png");
    on1 = IMG_Load("gamemenu/on1.png");
    on2 = IMG_Load("gamemenu/on2.png");
    of1 = IMG_Load("gamemenu/of1.png");
    joystic = IMG_Load("gamemenu/joystic.png");
    souris = IMG_Load("gamemenu/clavier.png");
    clavier = IMG_Load("gamemenu/souris.png");
    joystic2 = IMG_Load("gamemenu/joystic2.png");
    souris2 = IMG_Load("gamemenu/clavier2.png");
    clavier2 = IMG_Load("gamemenu/souris2.png");

    back = IMG_Load("gamemenu/back.png");
    of2 = IMG_Load("gamemenu/of2.png");

    //{//loading menu principale
    sprintf(menu, "gamemenu/image/%d.jpg", i);
    Menu_anime[i] = IMG_Load(menu);

    SDL_BlitSurface(Menu_anime[i], NULL, ecran, &posbackground);
    SDL_Delay(150);

    SDL_BlitSurface(play, NULL, ecran, &posplay1);
    SDL_BlitSurface(setting, NULL, ecran, &possetting1);
    SDL_BlitSurface(help, NULL, ecran, &poshelp1);
    SDL_BlitSurface(exite, NULL, ecran, &posexit1);
    SDL_BlitSurface(texte, NULL, ecran, &text);
    i++;

    SDL_Flip(ecran); //tfrgh el cache
    if (i > 7)
    {
      i = 1;
    }

    if (curseur == 1)
    {
      SDL_BlitSurface(play2, NULL, ecran, &posplay2);
      curseurr = 0;
    }
    if (curseur == 2)
    {
      SDL_BlitSurface(setting2, NULL, ecran, &possetting2);
      curseurr = 0;
    }

    if (curseur == 4)
    {
      SDL_BlitSurface(exit2, NULL, ecran, &posexit2);
      curseurr = 0;
    }
    SDL_Flip(ecran);
    if (curseurr == 1)
    {
      SDL_BlitSurface(play2, NULL, ecran, &posplay2);
      curseur = 0;
    }
    if (curseurr == 2)
    {
      SDL_BlitSurface(setting2, NULL, ecran, &possetting2);
      curseur = 0;
    }

    if (curseurr == 4)
    {
      SDL_BlitSurface(exit2, NULL, ecran, &posexit2);
      curseur = 0;
    }
    SDL_Flip(ecran);
    while (SDL_PollEvent(&event))
    { //while event
      switch (event.type)
      { //switch event
      case SDL_QUIT:
      { // case sdl quit
        run = 0;
      }
      case SDL_MOUSEMOTION:
      { //SDL_MOUSEMOTION
        if ((event.motion.x > posplay1.x) && (event.motion.x < posplay1.x + posplay1.w) && (event.motion.y > posplay1.y) && (event.motion.y < posplay1.y + posplay1.h))
        { //loading 2eme button start
          curseur = 1;
          Mix_PlayChannel(-1, click, 0);
        }
        if ((event.motion.x > possetting1.x) && (event.motion.x < possetting1.x + possetting1.w) && (event.motion.y > possetting1.y) && (event.motion.y < possetting1.y + possetting1.h))
        {
          curseur = 2;
          Mix_PlayChannel(-1, click, 0);
        }
        if ((event.motion.x > posexit1.x) && (event.motion.x < posexit1.x + posexit1.w) && (event.motion.y > posexit1.y) && (event.motion.y < posexit1.y + posexit1.h))
        {
          curseur = 4;
          Mix_PlayChannel(-1, click, 0);
        }
      }
      case SDL_KEYDOWN: //manwoula deja bel clavier
      {
        if (event.key.keysym.sym == SDLK_DOWN)
        {

          if (c == 1)
          {
            curseurr = 1;
            c++;
            Mix_PlayChannel(-1, click, 0);
          }
          else if (c == 2)
          {
            curseurr = 2;
            c++;
            Mix_PlayChannel(-1, click, 0);
          }
          else if (c == 3)
          {
            curseurr = 3;
            c++;
            Mix_PlayChannel(-1, click, 0);
          }
          else if (c == 4)
          {
            curseurr = 4;
            c++;
            Mix_PlayChannel(-1, click, 0);
          }

          if (c > 4)
          {
            c = 1;
          }
        }
        if (event.key.keysym.sym == SDLK_UP)
        {
          if (c1 == 4)
          {
            curseurr = 4;
            c1--;
            Mix_PlayChannel(-1, click, 0);
          }
          else if (c1 == 3)
          {
            curseurr = 3;
            c1--;
            Mix_PlayChannel(-1, click, 0);
          }
          else if (c1 == 2)
          {
            curseurr = 2;
            c1--;
            Mix_PlayChannel(-1, click, 0);
          }
          else if (c1 == 1)
          {
            curseurr = 1;
            c1--;
            Mix_PlayChannel(-1, click, 0);
          }

          if (c1 < 1)
          {
            c1 = 4;
          }
        }

      case SDL_MOUSEBUTTONUP: //manwoula bel sourie
      {
        if ((event.button.button == SDL_BUTTON_LEFT) && (curseur == 4))
        { // ki tenzel al exit yokhrej

          save=1;
          run = 0;
        }

        SDL_Flip(ecran);

        if ((event.button.button == SDL_BUTTON_LEFT) && (curseur == 1))
        {  ///////////////////////////////////////////////////affichage joueurs//////////////////////
        int run_e=1,running_e=1;
SDL_Surface *screen;
 SDL_Surface * img_choix;
img_choix=NULL;

SDL_Rect pos_choix;
   pos_choix.x=0;
    pos_choix.y=0;
    SDL_Event event;
         
screen=SDL_SetVideoMode(960,670,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );

   while (run_e)
    {
       running_e=1 ;
        
       
       img_choix=IMG_Load("joueur.png");
        
                    
                     
            SDL_BlitSurface(img_choix, NULL, screen, &pos_choix) ;
              SDL_Flip(screen);
                SDL_Event event ;
                SDL_PollEvent(&event);
                switch(event.type)
                {
                case SDL_QUIT:
                    running_e= 0 ;
                    run_e = 0;
                    break ;

                case SDL_KEYDOWN :
                    switch( event.key.keysym.sym )
                    {
                    case  SDLK_UP:
                        
                        (*j)=1;
                         SDL_Delay(50);
                         run_e=0;
                         
                        break ;
                    case  SDLK_DOWN:
       
                        (*j)=2;
                         SDL_Delay(50);
                    run_e=0;
                        break;
                    }
                    break ;


                }
            
}
////////////////////////////////////////
          int i;
             save=0 ;
          run = 0;

          /*SDL_Surface* screenTEMP = SDL_ConvertSurface(ecran, ecran->format, SDL_SWSURFACE);//Copie du contenu du screen
						for (i = 0; i < 180; i++)//Rotozoom avant chaque debut d'un niveau
						{
							SDL_Surface* effect = rotozoomSurface(screenTEMP, i, 1.0, SMOOTHING_ON);
							SDL_BlitSurface(effect, NULL, ecran, NULL);
							SDL_FreeSurface(effect);
							SDL_Flip(ecran);
						}*/
          ///teb3a el play //////***********************************
/*           y = 0;
          while (y < 743)
          {
            sprintf(menu, "gamemenu/cine/%d.jpg", y);
            cinematique[y] = IMG_Load(menu);
            SDL_BlitSurface(cinematique[y], NULL, ecran, &posbackground);
            //SDL_Delay(20);
            y++;
            SDL_Flip(ecran);
            SDL_FreeSurface(cinematique[y]); // tab3a el play
          } */
        }
        if ((event.button.button == SDL_BUTTON_LEFT) && (curseur == 2))
        {

          while (x == 2)
          {

            SDL_BlitSurface(Menu_anime[i], NULL, ecran, &posbackground);
            SDL_Delay(150);

            SDL_BlitSurface(son, NULL, ecran, &posson);
            SDL_BlitSurface(on1, NULL, ecran, &on);
            SDL_BlitSurface(of1, NULL, ecran, &of);
            SDL_BlitSurface(back, NULL, ecran, &posback);
            SDL_BlitSurface(joystic, NULL, ecran, &posjoystic);
            SDL_BlitSurface(souris, NULL, ecran, &possouris);
            SDL_BlitSurface(clavier, NULL, ecran, &posclavier);
            SDL_BlitSurface(texte, NULL, ecran, &text);

            i++;

            SDL_Flip(ecran);
            if (i > 7)
            {
              i = 1;
            }
            while (SDL_PollEvent(&event))
            { //while event
              switch (event.type)
              {
              case SDL_MOUSEMOTION:
                if ((event.motion.x > on.x) && (event.motion.x < on.x + on.w) && (event.motion.y > on.y) && (event.motion.y < on.y + on.h))
                {
                  curseur2 = 1;
                }
                if ((event.motion.x > of.x) && (event.motion.x < of.x + of.w) && (event.motion.y > of.y) && (event.motion.y < of.y + of.h))
                {
                  curseur2 = 2;
                }
                if ((event.motion.x > posjoystic.x) && (event.motion.x < posjoystic.x + posjoystic.w) && (event.motion.y > posjoystic.y) && (event.motion.y < posjoystic.y + posjoystic.h))
                {
                  curseur2 = 4;
                }
                if ((event.motion.x > posclavier.x) && (event.motion.x < posclavier.x + posclavier.w) && (event.motion.y > posclavier.y) && (event.motion.y < posclavier.y + posclavier.h))
                {
                  curseur2 = 5;
                }
                if ((event.motion.x > possouris.x) && (event.motion.x < possouris.x + possouris.w) && (event.motion.y > possouris.y) && (event.motion.y < possouris.y + possouris.h))
                {
                  curseur2 = 6;
                }
                if ((event.motion.x > posback.x) && (event.motion.x < posback.x + posback.w) && (event.motion.y > posback.y) && (event.motion.y < posback.y + posback.h))
                {
                  curseur2 = 3;
                }

              case SDL_MOUSEBUTTONUP:

                if ((event.button.button == SDL_BUTTON_LEFT) && (curseur2 == 3))
                {
                  x = 0;
                }

                SDL_Flip(ecran);
                if ((event.button.button == SDL_BUTTON_LEFT) && (curseur2 == 1))
                {
                  if (Mix_PausedMusic() == 1)
                  {
                    Mix_ResumeMusic();
                  } //thabes l ghnee
                }
                if ((event.button.button == SDL_BUTTON_LEFT) && (curseur2 == 2))
                {
                  if (Mix_PlayingMusic() == 1)
                  {
                    Mix_PauseMusic();
                  } //trajaa l ghnee
                }
              }
            }
            if (curseur2 == 1)
            {
              SDL_BlitSurface(on2, NULL, ecran, &on);
              SDL_Flip(ecran);
            }
            if (curseur2 == 2)
            {
              SDL_BlitSurface(of2, NULL, ecran, &of);
              SDL_Flip(ecran);
            }
            if (curseur2 == 4)
            {
              SDL_BlitSurface(joystic2, NULL, ecran, &posjoystic);
              SDL_Flip(ecran);
            }
            if (curseur2 == 5)
            {
              SDL_BlitSurface(clavier2, NULL, ecran, &posclavier);
              SDL_Flip(ecran);
            }
            if (curseur2 == 6)
            {
              SDL_BlitSurface(souris2, NULL, ecran, &possouris);
              SDL_Flip(ecran);
            }
          }
        }
        SDL_Flip(ecran);
      }
      }
      }
    }
  }
  SDL_FreeSurface(background); /* On libère la surface */

  SDL_FreeSurface(play);
  SDL_FreeSurface(setting);
  SDL_FreeSurface(exite);

  TTF_CloseFont(police);
  return save ;
}
