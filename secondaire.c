/**
* @file secondaire.c
* @brief les fonctions qui ont une relation avec l'entité secondaire.
* @author ghost runners -ahmed chm-
* @version 2
* @date Apr 04.2021
*
* 
*
*/
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include "animation.h"


/**

*@brief deplacement aleatoire ia 
*@param enemy_D , enemy_2D , enemy_2D , enemy_2G
*@return void

**/

void deplacerIA( caractere * enemy_D,caractere * enemy_G , int *r_enemy , int *l_enemy , int first , SDL_Rect posPerso) {

  
if (first ==0 )
  {
    *l_enemy = 0;
    *r_enemy = 0;
    s = rand();
    if (s % 2 == 0)
    {
      *r_enemy = 1;
    }
    if (s % 2 == 1)
    {
      *l_enemy = 1;
    }
  }


    if ((*r_enemy) == 1)
    {
      if (enemy_D[0].p.x >= 1080 )
      {
        *l_enemy = 1;
        *r_enemy = 0;
      }
      else if (abs(enemy_D[0].p.x-posperso<200)) {enemy_D[0].p.x += 5;}
       else { enemy_D[0].p.x += 2;}
    }
    if ((*l_enemy) == 1)
    {
      if (enemy_D[0].p.x <= 200)
      {
        *l_enemy = 0;
        *r_enemy = 1;
      }
      else  if (abs(enemy_D[0].p.x-posperso<200)) {enemy_D[0].p.x += 5;}
       else { enemy_D[0].p.x -= 2;}
    }
  }
  
  
}


}









}
/**

*@brief deplacement aleatoire 
*@param enemyy
*@return void

**/
caractere deplacer (caractere enemyy)
{ 
time_t t;
srand((unsigned) time(&t));

int r ; 
r = (rand()%2);

 if (r%2==0) { 
 if (enemyy[0].p.x<1080 ) {enemyy[0].p.x+=2; }
 }
 else 
              {  
if (enemyy[0].p.x>0 ) {enemyy[0].p.x-=2 ;   }
        
} 

   return (enemyy) ;   
}

/**

*@brief initialisation de l'ennemi
*@param enemy_D , enemy_2D , enemy_2D , enemy_2G
*@return void

**/

void initEnnemi(caractere *enemy_D,caractere *enemy_2D , caractere *enemy_G , caractere *enemy_2G)
{
int i ; 
char chaine[50];

for (i = 0; i < 6; i++)
  {
    sprintf(chaine, "ennemiD/%d.png", i + 1);
    enemy_D[i].image = IMG_Load(chaine);
    enemy_D[i].p.x = 2900;
    enemy_D[i].p.y = 510;
  }
  for (i = 0; i < 6; i++)
  {
    sprintf(chaine, "ennemi/%d.png", i + 1);
    enemy_G[i].image = IMG_Load(chaine);
    enemy_G[i].p.x = 510;
    enemy_G[i].p.y = 535;
  }

  for (i = 0; i < 6; i++)
  {
    sprintf(chaine, "ennemi2D/%d.png", i + 1);
    enemy_2D[i].image = IMG_Load(chaine);
    enemy_2D[i].p.x = 2900;
    enemy_2D[i].p.y = 510;
  }
  for (i = 0; i < 6; i++)
  {
    sprintf(chaine, "ennemi2D/%d.png", i + 1);
    enemy_2G[i].image = IMG_Load(chaine);
    enemy_2G[i].p.x = 510;
    enemy_2G[i].p.y = 535;
  }

}
/**

*@brief animation de l'ennemi
*@param enemy_D , enemy_2D , enemy_2D , enemy_2G
*@return void

**/



void animer (int l_enemy , int r_enemy , caractere enemy_D ,caractere enemy_G , caractere enemy_2D , caractere enemy_2G , int first ,  SDL_Surface *screen)
{
  if (first)
  {
    if (l_enemy)
    {
      if (enemy_D[0].p.x <= 1280)
        SDL_BlitSurface(enemy_2G[(int)frame_enemy].image, NULL, screen, &(enemy_D[0].p));
    }
    else if (r_enemy)
    {
      if (enemy_D[0].p.x >= 0)

        SDL_BlitSurface(enemy_2D[(int)frame_enemy].image, NULL, screen, &(enemy_D[0].p));
    }
  }
  else
  {
    if (l_enemy)
    {
      if (enemy_D[0].p.x <= 1280)
        SDL_BlitSurface(enemy_G[(int)frame_enemy].image, NULL, screen, &(enemy_D[0].p));
    }
    else if (r_enemy)
    {
      if (enemy_D[0].p.x >= 0)

        SDL_BlitSurface(enemy_D[(int)frame_enemy].image, NULL, screen, &(enemy_D[0].p));
    }
  }
  SDL_Flip(screen);

}


/**

*@brief collision bounding box
*@param perso , ennemi 
*@return 1 ou 0

**/



int collisionBB(personnage perso, caractere en)
{
  if (perso[0].pos.y+perso[0].img->h <ennemi[0].pos.y || perso[0].pos.y > ennemi[0].pos.y+ennemi[0].img->h)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}






