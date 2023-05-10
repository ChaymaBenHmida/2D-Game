/**
* @file enigf.c
*@author meriam abidi
*@brief implementation des fonctions
*@brief enigme sans fichier
*/

#include <stdio.h>
#include <stdlib.h>


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "animation.h"


/**
* @brief generer enigme
* @param image 
* @return e enigme
*/

enigme generer(char image[])
{
    int alea ;
    enigme e;
    e.p.x=0;
    e.p.y=0;
    e.img=NULL;
    srand(time(NULL));
    alea = 1+ rand()%3;

    sprintf(image,"img/%d.png",alea);
    e.img=IMG_Load(image);
    return e;
};



/**
* @brief afficher
* @param screen the screen
* @param image
* @param e enigme
* @return Nothing
*/

void afficherEnigme(enigme e, SDL_Surface* screen)
{
    SDL_BlitSurface(e.img,NULL,screen,&(e.p)) ;
    SDL_Flip(screen) ;
};


 /**
* @brief comparer et afficher resultat
* @param screen the screen
* @param s entier
* @param r entier
* @param en enigme
* @param e enigme
* @return 1 or 0
*/

int maine(SDL_Surface *screen, Perso p)
{ 
int i=0;
char timer[20];
SDL_Surface * cc;
SDL_Rect post;
post.x=0;
post.y=0;
SDL_Surface * t;
SDL_Rect pt;
t=IMG_Load("time.png");

SDL_Surface * up;
SDL_Rect pos;
    enigme  e;
    enigme en;
    int s,r,run =1,running=1,alea;
    char image[30]="";
    SDL_Event event;
    int verif=0;
    screen=SDL_SetVideoMode(960,670,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
switch(p.nb_joueurs)
{ case 1:
pt.x=300;
pt.y=200;
switch (p.num_joueur)
{ case 1: 
    while (run)
    {
       en.p.x=300;
    en.p.y=200;
    en.img=NULL;

        running=1,r=0 ;
        SDL_Event event ;
        SDL_PollEvent(&event);

            e=generer(image);
            afficherEnigme(e,screen);


            if(strcmp(image,"img/1.png")==0)
            {
                s =1 ;
            }
            else  	if(strcmp(image,"img/2.png")==0)
            {
                s=2;

            }
            else 	if(strcmp(image,"img/3.png")==0)
            {
                s=1;
            }
            do
            { i++;
                SDL_Event event ;
                SDL_PollEvent(&event);
                switch(event.type)
                {
                case SDL_QUIT:
                    running= 0 ;
                    run = 0;
                    break ;

                case SDL_KEYDOWN :
                    switch( event.key.keysym.sym )
                    {
                    case  SDLK_a:
                        r= 1;
                        break ;
                    case  SDLK_b :
                        r= 2;
                        break;
                    }
                    break ;


                }
                sprintf(timer,"tt/%d.png",i);
              cc=IMG_Load(timer);
              SDL_BlitSurface(cc, NULL, screen, &post) ;
                    SDL_Flip(screen);
                    SDL_Delay(1000);
                
            }
            while((r>2 || r<1) && running!=0 && i!=11 ) ;

if(i==11)
 {r=0;};
            while(running)
            {

                 if(r==0)
                {
                SDL_BlitSurface(t,NULL, screen, &pt) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 0;
                }
                else if (r==s)
                {
                    en.img=IMG_Load("img/00.jpg");//afficher image past
                    SDL_BlitSurface(en.img, NULL, screen, &(en.p)) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 1;
                }
                else
                {
                    en.img=IMG_Load("img/11.jpg"); //afficher l'image failled
                    SDL_BlitSurface(en.img, NULL, screen, &(en.p)) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 0;
                }
            }
        }
break;
case 2:
 while (run)
    {
       en.p.x=300;
    en.p.y=200;
    en.img=NULL;

        running=1,r=0 ;
        SDL_Event event ;
        SDL_PollEvent(&event);

            e=generer(image);
            afficherEnigme(e,screen);


            if(strcmp(image,"img/1.png")==0)
            {
                s =1 ;
            }
            else  	if(strcmp(image,"img/2.png")==0)
            {
                s=2;

            }
            else 	if(strcmp(image,"img/3.png")==0)
            {
                s=1;
            }
            do
            { i++;
                SDL_Event event ;
                SDL_PollEvent(&event);
                switch(event.type)
                {
                case SDL_QUIT:
                    running= 0 ;
                    run = 0;
                    break ;

                case SDL_KEYDOWN :
                    switch( event.key.keysym.sym )
                    {
                    case  SDLK_UP:
                        r= 1;
                        break ;
                    case  SDLK_DOWN:
                        r= 2;
                        break;
                    }
                    break ;


                }
               sprintf(timer,"tt/%d.png",i);
              cc=IMG_Load(timer);
              SDL_BlitSurface(cc, NULL, screen, &post) ;
                    SDL_Flip(screen);
                    SDL_Delay(1000);
                
            }
            while((r>2 || r<1) && running!=0 && i!=11 ) ;

if(i==11)
 {r=0;};
            while(running)
            {

                 if(r==0)
                {
                SDL_BlitSurface(t,NULL, screen, &pt) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 0;
                }
                else if (r==s)
                {
                    en.img=IMG_Load("img/00.jpg");//afficher image past
                    SDL_BlitSurface(en.img, NULL, screen, &(en.p)) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 1;
                }
                else
                {
                    en.img=IMG_Load("img/11.jpg"); //afficher l'image failled
                    SDL_BlitSurface(en.img, NULL, screen, &(en.p)) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 0;
                }
            }
        }
break;
}
break;
                    case 2:
                        switch(p.num_joueur)
                        {
                        case 1:
                        pt.x=300;
                        pt.y=0;
                             while (run)
    {
    up=IMG_Load("up.png");
      pos.x=0;
      pos.y=0;
    SDL_BlitSurface(up, NULL, screen, &pos) ;
              SDL_Flip(screen);
    SDL_Delay(1000); 

      en.p.x=300;
    en.p.y=0;
    en.img=NULL;
        running=1,r=0 ;
        SDL_Event event ;
        SDL_PollEvent(&event);

       e.p.x=120;
    e.p.y=0;
e.img=NULL;
              srand(time(NULL));
    alea = 1+ rand()%3;

    sprintf(image,"img1/%d.png",alea);
    e.img=IMG_Load(image);

            afficherEnigme(e,screen);


            if(strcmp(image,"img1/1.png")==0)
            {
                s =1 ;
            }
            else  	if(strcmp(image,"img1/2.png")==0)
            {
                s=2;

            }
            else 	if(strcmp(image,"img1/3.png")==0)
            {
                s=1;
            }
            do
            { i++;
                            SDL_Event event ;
                SDL_PollEvent(&event);
                switch(event.type)
                {
                case SDL_QUIT:
                    running= 0 ;
                    run = 0;
                    break ;

                case SDL_KEYDOWN :
                    switch( event.key.keysym.sym )
                    {
                    case  SDLK_UP:
                        r= 1;
                        break ;
                    case  SDLK_DOWN :
                        r= 2;
                        break;
                    }
                    break ;


                }
            sprintf(timer,"tt/%d.png",i);
              cc=IMG_Load(timer);
              SDL_BlitSurface(cc, NULL, screen, &post) ;
                    SDL_Flip(screen);
                    SDL_Delay(1000);
                
            }
            while((r>2 || r<1) && running!=0 && i!=11 ) ;

if(i==11)
 {r=0;};
            while(running)
            {

                 if(r==0)
                {
                SDL_BlitSurface(t,NULL, screen, &pt) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 0;
                }
                else if (r==s)
                {
                    en.img=IMG_Load("img/00.jpg");//afficher image past
                    SDL_BlitSurface(en.img, NULL, screen, &(en.p)) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 1;
                }
                else
                {
                    en.img=IMG_Load("img/11.jpg"); //afficher l'image failled
                    SDL_BlitSurface(en.img, NULL, screen, &(en.p)) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 0;
                }
            }
        }

                            break;

                    case 2:
pt.x=300;
pt.y=390;
 while (run)
    {     up=IMG_Load("a_b.png");
      pos.x=0;
      pos.y=330;
    SDL_BlitSurface(up, NULL, screen, &pos) ;
              SDL_Flip(screen);
    SDL_Delay(1000); 

      en.p.x=300;
    en.p.y=390;
    en.img=NULL;
        running=1,r=0 ;
        SDL_Event event ;
        SDL_PollEvent(&event);

       e.p.x=120;
    e.p.y=400;
e.img=NULL;
              srand(time(NULL));
    alea = 1+ rand()%3;

    sprintf(image,"img1/%d.png",alea);
    e.img=IMG_Load(image);

            afficherEnigme(e,screen);


            if(strcmp(image,"img1/1.png")==0)
            {
                s =1 ;
            }
            else  	if(strcmp(image,"img1/2.png")==0)
            {
                s=2;

            }
            else 	if(strcmp(image,"img1/3.png")==0)
            {
                s=1;
            }
            do
            { i++;
                SDL_Event event ;
                SDL_PollEvent(&event);
                switch(event.type)
                {
                case SDL_QUIT:
                    running= 0 ;
                    run = 0;
                    break ;

                case SDL_KEYDOWN :
                    switch( event.key.keysym.sym )
                    {
                    case  SDLK_a:
                        r= 1;
                        break ;
                    case  SDLK_b:
                        r= 2;
                        break;
                    }
                    break ;


                }
           sprintf(timer,"tt/%d.png",i);
              cc=IMG_Load(timer);
              SDL_BlitSurface(cc, NULL, screen, &post) ;
                    SDL_Flip(screen);
                    SDL_Delay(1000);
                
            }
            while((r>2 || r<1) && running!=0 && i!=11 ) ;

if(i==11)
 {r=0;};
            while(running)
            {

                 if(r==0)
                {
                SDL_BlitSurface(t,NULL, screen, &pt) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 0;
                }
                else if (r==s)
                {
                    en.img=IMG_Load("img/00.jpg");//afficher image past
                    SDL_BlitSurface(en.img, NULL, screen, &(en.p)) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 1;
                }
                else
                {
                    en.img=IMG_Load("img/11.jpg"); //afficher l'image failled
                    SDL_BlitSurface(en.img, NULL, screen, &(en.p)) ;
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return 0;
                }
            }
        }

                        break;

}
 break;
}
    SDL_FreeSurface(screen);
    SDL_Quit();
}







 /**
* @brief choix input enigme
*/




int choose(SDL_Surface *screen)
{
int run_e=1,running_e=1,num_joueur;

 SDL_Surface * img_e;
img_e=NULL;

SDL_Rect pos_e;
   pos_e.x=0;
    pos_e.y=0;
    SDL_Event event;
         
screen=SDL_SetVideoMode(960,670,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );

   while (run_e)
    {
       running_e=1 ;
        
       
       img_e=IMG_Load("choose1.png");
        
                    
                     
            SDL_BlitSurface(img_e, NULL, screen, &pos_e) ;
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
                        
                        num_joueur=1;
                         SDL_Delay(250);
                         return 1;
                        break ;
                    case  SDLK_DOWN:
       
                        num_joueur=2;
                         SDL_Delay(250);
                    return 2;
                        break;
                    }
                    break ;


                }
            
}



    SDL_FreeSurface(screen);
    SDL_Quit();
}


void update_fonts(int *tempsActuel,int *tempsPrecedent,int *compteurr,int *seconde,char temps [],char score [],int *score_finale,SDL_Surface **texte,SDL_Surface **gestion_score,TTF_Font *police,SDL_Color couleurBlanche,int *minute )
{
 int heure = 0  ;	
                         (*tempsActuel) = SDL_GetTicks();
                       if ((*tempsActuel) -  (*tempsPrecedent) >= 1000) 
                      {
/*                        (*compteurr) += 100; 
                       if((*compteurr) % 1000<=0)
                         { */
													 
                            (*seconde) +=1 ;
                             if((*seconde) %10==0)
                              (*score_finale)-=10 ;
			 if(*seconde==60)
			  {
			 (*seconde)=0 ;
			  *minute= 1 ;
			}
                        // }
                           sprintf(temps, " %d: %d: %d",heure,*minute, *seconde); 
                          sprintf(score, "Score: %d", *score_finale); 
													
                          SDL_FreeSurface(*texte); 
                          SDL_FreeSurface(*gestion_score);    
                          (*gestion_score)=TTF_RenderText_Blended(police,score, couleurBlanche) ;  
                          (*texte) = TTF_RenderText_Blended(police, temps, couleurBlanche); 
                          (*tempsPrecedent) = (*tempsActuel);  

                      }
                        
}






