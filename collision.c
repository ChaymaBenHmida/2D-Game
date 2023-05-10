#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation.h"
#include <math.h>


void calculer_centre_rayon (Perso *perso,Caractere *box)
{

 perso->c.x=perso->p.x+ (perso->clip[0].w)/2  ;
 perso->c.y=perso->p.y+ (perso->clip[0].h)/2 ;
 perso->c.rayon=sqrt( pow( (perso->clip[0].w)/2 , 2) + pow( (perso->clip[0].h)/2 , 2) ) ;
 /*  pour le circle inscrit :
 if(width<height)
 {
 perso->c.rayon= (perso->img->w)/2 ;
 tab [0]->c.rayon= (tab [0]->img->w)/2 ;
 }
 else 
 {
 perso->c.rayon= (perso->img->h)/2 ;
 tab [0]->c.rayon= (tab [0]->img->h)/2 ;
 } */
 box->c.x=box->p.x+ (box->image->w)/2 ;
 box->c.y=box->p.y+ (box->image->h)/2 ;
 box->c.rayon=sqrt( pow( (box->image->w)/2 , 2) + pow( (box->image->h)/2 , 2) ) ;
}
float calculer_distance (Perso perso,Caractere box) 
{
  float D ;

  D=sqrt( pow( (perso.c.x) - (box.c.x) ,2 ) + pow ( (perso.c.y) - (box.c.y) , 2  ) ) ;

  return D ;

}

int verif_collision (Perso perso,Caractere box,float D1 )
{
  float D2 ;
  int collision=0 ;

  D2=perso.c.rayon + box.c.rayon ;
/* printf("D1= %f ,D2=%f",D1,D2); */
  if(D1<=(D2))
    collision= 1 ;
  
  return collision ;
}
int Collision_Parfaite(SDL_Surface *Background,Coordinate C)
{
 int collision=0;
 SDL_Color color ;


 SDL_GetRGB(getpixel(Background,C),Background->format,&color.r,&color.g,&color.b);

 if (color.r==0 && color.g==0 && color.b==0)
 {collision=1;}

 return collision;

}
Uint32 getpixel(SDL_Surface *surface,Coordinate C)
{
    int bpp = surface->format->BytesPerPixel;
   
    Uint8 *p = (Uint8 *)surface->pixels + C.Y * surface->pitch + C.X * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;       
    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;      
    }
}
