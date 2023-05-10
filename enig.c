/** 
* ... @file enig.c ... 
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
* @brief load randomly 
* @param screen and images
* @param alea the random enigme 
* @return nothing 
*/ 
void AfficherEnigme(SDL_Surface *screen , char image [],Imm *e2,int *alea)
{ 
	int test=*alea ;
do{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
e2->pos.x=0;
e2->pos.y=0;
 sprintf(image ,"enigme/%d.jpg",*alea);
e2->srf = IMG_Load(image);
 SDL_BlitSurface(e2->srf,NULL,screen,&(e2->pos)) ;
  SDL_Flip(screen) ;
}
 /** 
* @brief To open the file and read the correct answer . 
* @param num_q the question number   
* @return solution 
*/ 


 int genererEnigme (int num_q)
 {
 	int solution =0 ,i=0;
 	
    	FILE* pf=NULL;

    	pf=fopen("test.txt","r");
    	while((pf)&&(i!=num_q)){
	    fscanf(pf,"%d",&solution);
	    i++;
    	}

        fclose(pf);

 	return solution;
 }
 
 /** 
* @brief check the input aka the player's answer  
* @param running and run to finish   
* @return the player's answer  
*/ 
 int check_input_enigme(int * running,int *run )
{
	SDL_Event event ;
  	int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
            case SDL_QUIT:
		*running= 0 ;
                *run = 0;
		break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
			   break ;
			   case  SDLK_z :
			   r= 2;
			   break;
			   case SDLK_e: 
			   r=3 ;
			   break;
			    }
       break ;

                 
	}
  return r ;
}
 int mainenig(SDL_Surface *screen)
{ 

	Imm e2,eng;
	int s,r,run =1,running=1,alea;
	char image[30]="";
	SDL_Event event;
    
   
	 
	 SDL_Init ( SDL_INIT_VIDEO ) ;



	 screen=SDL_SetVideoMode(960,670,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
	
	
	 while (run)
	 {
	    running=1,r=0 ;
	     SDL_PollEvent(&event);
           switch(event.type)
            {
              case SDL_QUIT:
                run = 0;
		break ;
            }
        	
      AfficherEnigme(screen,image,&e2,&alea);
      s=genererEnigme(alea);
      printf("%d",s);
      do{
          r=check_input_enigme(&running,&run);
      }while((r>3 || r<1) && running!=0) ;
	
      while(running){

		     
		     if (r==s)
 	{
 		eng.srf=IMG_Load("000.jpg");
 		SDL_BlitSurface(eng.srf, NULL, screen, &(eng.pos)) ;
        SDL_Flip(screen);
        SDL_Delay(1000);
        return 1;
 	}
 	else
 	{
 		eng.srf=IMG_Load("11.jpg");
 		SDL_BlitSurface(eng.srf, NULL, screen, &(eng.pos)) ;
        SDL_Flip(screen);
         SDL_Delay(1000);
        return 0;
 	}
		     SDL_WaitEvent(&event);
                     switch(event.type)
                       {
					     case SDL_QUIT :
                              			running =0 ;
						run=0 ;
					     break ;
                         case SDL_KEYDOWN :
						    
                             switch( event.key.keysym.sym )
                                  {
			                        case  SDLK_ESCAPE: 
			                           running= 0 ;
			                        break ;
			                      }
						 break ;
                       }
                    }
	}	
      SDL_FreeSurface(screen);
      SDL_Quit();
	
}

