#include <stdio.h>
#include  <stdlib.h>
 #include  <SDL/SDL.h>
 #include <SDL/SDL_image.h>
 #include <SDL/SDL_mixer.h>
 #include <math.h>
 #include <stdbool.h>
 
 
 int CollisionBB( SDL_Rect position , SDL_Rect position1  )
 {
	 
	 if (((position.x+position.w == position1.x)&&(position.y+position.h==position1.y+position1.h))  || ((position.x == position1.x + position1.w)&&(position.y+position.h==position1.y+position1.h)) || ((position.y+position.h == position1.y)&&(position.x==position1.x)) || ((position.y == position1.y + position1.h)&&(position.x==position1.x))) 
     {
		 return 1 ; 
	 }
   else return 0 ; 
	 
	 
 }
