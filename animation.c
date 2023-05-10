#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "animation.h"
#include "scrolling.h"
#include "Collisions.h"
#include <time.h>
#include <math.h>

#define width 1280

void setrects(SDL_Rect *clip)
{
  clip[0].x = 0;
  clip[0].y = 0;
  clip[0].w = 78;
  clip[0].h = 117;

  clip[1].x = 78;
  clip[1].y = 0;
  clip[1].w = 78;
  clip[1].h = 117;

  clip[2].x = 156;
  clip[2].y = 0;
  clip[2].w = 78;
  clip[2].h = 117;

  clip[3].x = 234;
  clip[3].y = 0;
  clip[3].w = 78;
  clip[3].h = 117;

  clip[4].x = 312;
  clip[4].y = 0;
  clip[4].w = 78;
  clip[4].h = 117;
}

int collisionBB(SDL_Rect rect_perso, SDL_Rect rects, Caractere enemy_D[])
{
  //|| perso[0].pos.y+perso[0].img->h <ennemi[0].pos.y || perso[0].pos.y > ennemi[0].pos.y+ennemi[0].img->h
  if (rect_perso.x + rects.w < enemy_D[0].p.x - 200 || rect_perso.x - 200 > enemy_D[0].p.x + enemy_D[0].image->w)
    return 0;
  else
    return 1;
}
void update(SDL_Surface *screen, SDL_Surface *Background, Perso sprite, Caractere enemy_D[], Caractere enemy_G[], int r_enemy, int l_enemy, int frame, float frame_enemy, SDL_Rect positionFond, int l_pers, int r_pers, Caractere box, SDL_Surface *texte, SDL_Surface *gestion_score, SDL_Rect position, SDL_Rect position2, Caractere life[], int nb_life, Caractere box2, SDL_Surface *mask, int first, Caractere enemy_2D[], Caractere enemy_2G[], Caractere chair, Caractere minimap, Caractere curseur_map)
{
  SDL_BlitSurface(Background, &positionFond, screen, NULL);
  SDL_BlitSurface(box.image, NULL, screen, &(box.p));
  SDL_BlitSurface(box2.image, NULL, screen, &(box2.p));
  ;

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

  if (r_pers)
    SDL_BlitSurface(sprite.image2, &sprite.clip[frame], screen, &sprite.p);
  else if (l_pers)
    SDL_BlitSurface(sprite.image, &sprite.clip[frame], screen, &sprite.p);

  SDL_BlitSurface(texte, NULL, screen, &position);
  SDL_BlitSurface(gestion_score, NULL, screen, &position2);
  SDL_BlitSurface(life[nb_life].image, NULL, screen, &(life[nb_life].p));

  SDL_BlitSurface(minimap.image, NULL, screen, &(minimap.p));
  SDL_BlitSurface(chair.image, NULL, screen, &(chair.p));
  SDL_BlitSurface(curseur_map.image, NULL, screen, &(curseur_map.p));

  SDL_Flip(screen);
}
void setup(int j,Perso *sprite, Caractere enemy_G[], Caractere enemy_D[], Caractere *box, Caractere life[], Caractere *box2, Caractere *mouse, Caractere *keyboard, Caractere *controller, Caractere *quitter, Caractere enemy_2G[], Caractere enemy_2D[], Caractere *chair, Caractere *minimap, int level, Caractere *curseur_map, Caractere *win, Perso *sprite2)
{
  int i;
  char chaine[20];

  win->image = IMG_Load("youwon.png");
  win->p.x = 0;
  win->p.y = 0;

  curseur_map->image = IMG_Load("curseur.png");
  curseur_map->p.x = 20;
  curseur_map->p.y = 245;

  if (level == 1)
    minimap->image = IMG_Load("minimap1.png");
  else if (level == 2)
    minimap->image = IMG_Load("minimap2.png");
  else if (level == 3)
    minimap->image = IMG_Load("minimap3.png");

  minimap->p.x = 20;
  minimap->p.y = 230;
  if (level == 1)
    chair->image = IMG_Load("chair2.png");
  if (level == 2)
    chair->image = IMG_Load("chair2.png");
  if (level == 3)
    chair->image = IMG_Load("chair.png");

  chair->p.x = 4600;
  chair->p.y = 570;

  quitter->image = IMG_Load("saveyes.png");
  quitter->p.x = 270;
  quitter->p.y = 0;

  mouse->image = IMG_Load("Souris.png");
  mouse->p.x = 0;
  mouse->p.y = 0;

  controller->image = IMG_Load("Manette.png");
  controller->p.x = 0;
  controller->p.y = 0;

  keyboard->image = IMG_Load("Clavier.png");
  keyboard->p.x = 0;
  keyboard->p.y = 0;

  sprite2->image = IMG_Load("sprite_hero_left.png");
  sprite2->image2 = IMG_Load("sprite_hero_right.png");
  sprite2->p.x = 0;
  sprite2->p.y = 400;

  sprite2->clip[0].x = 0;
  sprite2->clip[0].y = 10;
  sprite2->clip[0].w = 126;
  sprite2->clip[0].h = 169;

  sprite2->clip[1].x = 126 * 1 + 1;
  sprite2->clip[1].y = 10;
  sprite2->clip[1].w = 126;
  sprite2->clip[1].h = 169;

  sprite2->clip[2].x = 126 * 2 + 2;
  sprite2->clip[2].y = 10;
  sprite2->clip[2].w = 126;
  sprite2->clip[2].h = 169;

  sprite2->clip[3].x = 126 * 3 + 3;
  sprite2->clip[3].y = 10;
  sprite2->clip[3].w = 126;
  sprite2->clip[3].h = 169;

  sprite2->clip[4].x = 126 * 4 + 4;
  sprite2->clip[4].y = 10;
  sprite2->clip[4].w = 126;
  sprite2->clip[4].h = 169;

  sprite2->clip[5].x = 126 * 5 + 5;
  sprite2->clip[5].y = 10;
  sprite2->clip[5].w = 126;
  sprite2->clip[5].h = 169;

  sprite2->clip[6].x = 126 * 6 + 6;
  sprite2->clip[6].y = 10;
  sprite2->clip[6].w = 126;
  sprite2->clip[6].h = 169;
  if (j== 1)
  {
    sprite->image = IMG_Load("sprite_hero_left.png");
    sprite->image2 = IMG_Load("sprite_hero_right.png");
  }

  else 
  {
    sprite->image = IMG_Load("sprite_hero_left2.png");
    sprite->image2 = IMG_Load("sprite_hero_right2.png");
  }


  sprite->p.x = 0;
  sprite->p.y = 100;

  sprite->clip[0].x = 0;
  sprite->clip[0].y = 20;
  sprite->clip[0].w = 126;
  sprite->clip[0].h = 169;

  sprite->clip[1].x = 126 * 1 + 1;
  sprite->clip[1].y = 20;
  sprite->clip[1].w = 126;
  sprite->clip[1].h = 169;

  sprite->clip[2].x = 126 * 2 + 2;
  sprite->clip[2].y = 20;
  sprite->clip[2].w = 126;
  sprite->clip[2].h = 169;

  sprite->clip[3].x = 126 * 3 + 3;
  sprite->clip[3].y = 20;
  sprite->clip[3].w = 126;
  sprite->clip[3].h = 169;

  sprite->clip[4].x = 126 * 4 + 4;
  sprite->clip[4].y = 20;
  sprite->clip[4].w = 126;
  sprite->clip[4].h = 169;

  sprite->clip[5].x = 126 * 5 + 5;
  sprite->clip[5].y = 20;
  sprite->clip[5].w = 126;
  sprite->clip[5].h = 169;

  sprite->clip[6].x = 126 * 6 + 6;
  sprite->clip[6].y = 20;
  sprite->clip[6].w = 126;
  sprite->clip[6].h = 169;

  box->image = IMG_Load("F.png");
  box->p.x = 1820;
  box->p.y = 470;

  box2->image = IMG_Load("F.png");
  box2->p.x = 4000;
  box2->p.y = 470;

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

  for (i = 0; i < 5; i++)
  {
    sprintf(chaine, "coeur%d.png", i + 1);
    life[i].image = IMG_Load(chaine);
    if (i == 4)
    {
      life[i].p.x = 400;
      life[i].p.y = 200;
    }
    else
    {
      life[i].p.x = 20;
      life[i].p.y = 20;
    }
  }
}
void move_ennemi(Caractere enemy_D[], int *r_enemy, int *l_enemy, float *frame , SDL_Rect posperso)
{
  int s;
  srand(time(NULL));

  if (*frame < 4)
  {
    (*frame) += 0.1;
    if ((*r_enemy) == 1)
    {
      if (enemy_D[0].p.x >= (width - 200))
      {
        *l_enemy = 1;
        *r_enemy = 0;
      }
      else
        enemy_D[0].p.x += 2;
	          if (abs(enemy_D[0].p.x-posperso.x)<200) {enemy_D[0].p.x += 3;}
    }
    if ((*l_enemy) == 1)
    {
      if (enemy_D[0].p.x <= 200)
      {
        *l_enemy = 0;
        *r_enemy = 1;
      }
      else
        enemy_D[0].p.x -= 2;
	          if (abs(enemy_D[0].p.x-posperso.x)<200) {enemy_D[0].p.x -= 3;}
    }
  }
  if (*frame >= 4)
  {
    *l_enemy = 0;
    *r_enemy = 0;
    *frame = 0;
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
}
int animate(int jj,SDL_Surface *screen, SDL_Surface *sprit, SDL_Surface *sprite2, SDL_Surface *sprite3, SDL_Surface *Background, SDL_Rect positionFond, int *running, SDL_Surface *mask, int *save, int level)
{
  TTF_Init();

  srand(time(NULL));

  Perso sprite,  sprite22;
  enigme en, e;
  sprite.num_joueur=1;
  sprite.nb_joueurs=1;
  int exit = 0, exitt = 0;
  Caractere enemy_G[10], enemy_D[10], box, life[5], box2, mouse, controller, keyboard, quitter, enemy_2G[10], enemy_2D[10], chair, minimap, curseur_map, win;
  SDL_Surface *Level = NULL;
  int up, fast = 0, running4, i = 0, running5 = 1, j = 2;
  SDL_Rect rect, rects[5], dst, rect1, pos;
  int n, collision = 0, alea;
  SDL_Color couleurBlanche = {255, 255, 255};
  TTF_Font *police;
  SDL_Surface *gestion_score;
  SDL_Surface *texte;
  SDL_Rect pos_enemy, pos_collision;
  int score_finale = 1000, first = 0, prec = 0, prec1 = 0, actu = 0, actu1 = 0, nb_life = 0, collision2, enigme2 = 0;
  int r_enemy = 1, l_enemy = 0, l_pers = 0, r_pers = 1, collision1, enigme = 0, running2 = 1, running3 = 1, r, s, seconde = 0, compteurr, tempsPrecedent = 0, tempsActuel = 0, minute = 0;
  float frame_enemy = 0, D, D1, frame = 0, curseurpos = 20;
  int controller1 = 0, mouse1 = 0, keyboard1 = 0, choose1 = 0;
  char image[20], score[10], temps[20];
  SDL_Rect position1, position2;
  Coordinate C;
  SDL_Event event;
  Caractere quitter2;

  quitter2.image = IMG_Load("saveno.png");
  quitter2.p.x = 270;
  quitter2.p.y = 0;

  police = TTF_OpenFont("angelina.TTF", 65);
  sprintf(temps, "00 :%d : %d", minute, seconde);
  sprintf(score, "Score: %d", score_finale);
  (gestion_score) = TTF_RenderText_Blended(police, score, couleurBlanche);
  (texte) = TTF_RenderText_Blended(police, temps, couleurBlanche);

  position1.x = 1280 / 2 - 100;
  position1.y = 20;

  position2.x = 1280 - 300;
  position2.y = 20;

  en.p.x = 0;
  en.p.y = 0;

  e.p.x = 400;
  e.p.y = 150;

  dst.x = 0;
  dst.y = 0;
  dst.h = 720;
  dst.w = 1280;

  rect.x = 93;
  rect.y = 535;

  pos.x = 1626;
  pos.y = 535;

  setup(jj,&sprite, enemy_G, enemy_D, &box, life, &box2, &mouse, &keyboard, &controller, &quitter, enemy_2G, enemy_2D, &chair, &minimap, level, &curseur_map, &win, &sprite22);

  if (*save)
  {
    *save = 0;
    FILE *f = fopen("save_file", "r");
    fscanf(f, "%hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %d %d %d %d", &(positionFond.x), &(positionFond.y), &(sprite.p.x), &(sprite.p.y), &(enemy_D[0].p.x), &(enemy_D[0].p.y), &(box.p.x), &(box.p.y), &(box2.p.x), &(box2.p.y), &(nb_life), &(score_finale), &seconde, &minute);
    fclose(f);
  }

  sprite.vx = 0;
  update(screen, Background, sprite, enemy_D, enemy_G, r_enemy, l_enemy, frame, frame_enemy, positionFond, l_pers, r_pers, box, texte, gestion_score, position1, position2, life, nb_life, box2, mask, first, enemy_2D, enemy_2G, chair, minimap, curseur_map);
  //SDL_BlitSurface(controller.image,NULL,screen,&(controller.p));

  while (*running)
  {
    up = 0;

    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        exit = 1;
        //*running = 0;
        break;
      case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == (SDL_BUTTON_LEFT || SDL_BUTTON_RIGHT))
        {
          if (event.button.x > (1280 / 2))
          {
            l_pers = 0;
            r_pers = 1;
            if ((sprite.p.y == 720 - 210) || (sprite.p.y != 720 - 210 && sprite.vx >= 0))
              sprite.vx = 5;
          }
          if (event.button.x < (1280 / 2))
          {
            l_pers = 1;
            r_pers = 0;
            if ((sprite.p.y == 720 - 210) || (sprite.p.y != 720 - 210 && sprite.vx <= 0))
              sprite.vx = -5;
          }
        }
        break;
      case SDL_KEYDOWN:

        switch (event.key.keysym.sym)

        {
        case SDLK_LSHIFT:
          fast = 1;
          break;
        case SDLK_ESCAPE:
          exit = 1;
          //*running=0 ;

          break;

        case SDLK_UP:
          up = 1;

          if (sprite.jump == 0)
          {
            sprite.vy = -11;
            sprite.jump = 1;
          }

          break;
        case SDLK_RIGHT:
          l_pers = 0;
          r_pers = 1;
          if ((sprite.p.y == 720 - 210) || (sprite.p.y != 720 - 210 && sprite.vx >= 0))
            sprite.vx = 5;

          break;
        case SDLK_LEFT:
          l_pers = 1;
          r_pers = 0;
          if ((sprite.p.y == 720 - 210) || (sprite.p.y != 720 - 210 && sprite.vx <= 0))
            sprite.vx = -5;

          break;
        }
        break;
      case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_LSHIFT)
          fast = 0;
        if (event.key.keysym.sym == SDLK_RIGHT)
        {

          sprite.vx = 0;
        }
        if (event.key.keysym.sym == SDLK_LEFT)
        {

          sprite.vx = 0;
        }
        break;
      }
    }

    /*         	 if((sprite.p.y!=720-210) && ( sprite.jump == 1) && up==1 )
					{   
						sprite.vy = -11 ;
						sprite.jump =0 ;
            up=0 ;
				  } */
    if ((sprite.p.y == 720 - 210))
      sprite.jump = 0;

    if (sprite.p.y == 720 - 210 && sprite.jump == 0)
    {

      // sprite.vx = 0;
      sprite.stop = 0;
    }
    sprite.vy += 0.4;
    sprite.p.y += (int)sprite.vy;

    if (sprite.p.y + 210 > 720)
    {
      sprite.p.y = 720 - 210;
      sprite.vy = 0;
    }

    if (sprite.vx > 0)
    {
      if (positionFond.x < 8000 - 1280)
      {
        if (fast)
        {
          positionFond.x += 15;
          enemy_D[0].p.x -= 15;
          box.p.x -= 15;
          box2.p.x -= 15;
          chair.p.x -= 15;
          sprite.p.x += 2;
          curseurpos += 0.4;
          curseur_map.p.x = (int)curseurpos;
        }
        else
        {
          positionFond.x += 10;
          enemy_D[0].p.x -= 10;
          box.p.x -= 10;
          box2.p.x -= 10;
          chair.p.x -= 10;
          curseurpos += 0.4;
          curseur_map.p.x = (int)curseurpos;
          sprite.p.x += 1;
        }
      }
      else
      {
        if (sprite.p.x + sprite.clip[0].w < 1280)
        {
          if (fast)
          {
            sprite.p.x += 7;
          }

          else
          {
            sprite.p.x += 5;
          }
        }
      }

      frame += 0.2;
      if (frame > 4)
      {
        frame = 0;
      }

      //sprite.p.x +=5 ;
    }

    if (sprite.vx < 0)
    {
      if (positionFond.x >= 0)
      {
        if (fast)
        {
          positionFond.x -= 15;
          sprite.p.x -= 2;
          curseurpos -= 0.4;
          curseur_map.p.x = (int)curseurpos;
          enemy_D[0].p.x += 15;
          box.p.x += 15;
          box2.p.x += 15;
          chair.p.x += 15;
        }
        else
        {
          positionFond.x -= 10;
          sprite.p.x -= 1;
          curseurpos -= 0.4;
          curseur_map.p.x = (int)curseurpos;
          enemy_D[0].p.x += 10;
          box.p.x += 10;
          box2.p.x += 10;
          chair.p.x += 10;
        }
      }
      else
      {
        if (sprite.p.x - sprite.clip[0].w > 0)
        {
          if (fast)
          {

            sprite.p.x -= 7;
          }

          else
          {

            sprite.p.x -= 5;
          }
        }
      }
      frame += 0.2;
      if (frame > 4)
      {
        frame = 0;
      }
      //sprite.p.x-= 5 ;
    }

    calculer_centre_rayon(&sprite, &box);
    D = calculer_distance(sprite, box);
    collision1 = verif_collision(sprite, box, D);

    calculer_centre_rayon(&sprite, &box2);
    D = calculer_distance(sprite, box2);
    collision2 = verif_collision(sprite, box2, D);

    /* collision1 = collisionBB(sprite.p, sprite.clip[0], box.p); */
    collision = collisionBB(sprite.p, sprite.clip[0], enemy_D);
    C.X = positionFond.x + sprite.p.x + 70;
    C.Y = sprite.p.y + (sprite.clip[0].h / 2);
    /*     SDL_LockSurface(mask);
    collision2 = Collision_Parfaite(mask, C);
    SDL_UnlockSurface(mask); */
    if (collision2 && enigme2 != 1)
    {
      sprite.vx = 0;
      enigme2 = 1;
      running2 = 1, r = 0;
      update(screen, Background, sprite, enemy_D, enemy_G, r_enemy, l_enemy, frame, frame_enemy, positionFond, l_pers, r_pers, box, texte, gestion_score, position1, position2, life, nb_life, box2, mask, first, enemy_2D, enemy_2G, chair, minimap, curseur_map);

if(sprite.nb_joueurs==1)
{
sprite.num_joueur=choose(screen);
}
      do
      {
        running2 = 1;
        SDL_BlitSurface(Background, &positionFond, screen, NULL);
        r=maine(screen,sprite);
        SDL_Flip(screen);

     
        while (running2)
        {

          SDL_WaitEvent(&event);
          switch (event.type)
          {
          case SDL_QUIT:
            running2 = 0;
            *running = 0;
            break;
          case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
            case SDLK_RETURN:
              running2 = 0;

              break;
            case SDLK_SPACE:
              running2 = 0;
              break;
            }
            break;
          }
        }
        if (r != 1)
          score_finale -= 50;
        else
          score_finale += 500;
      } while (r != 1);
    }
    if (collision && first != 1) //ennemi collision
    {
      first = 1;
    }
    prec = SDL_GetTicks();
    prec1 = SDL_GetTicks();
    if (first && prec - actu > 10)
    {
      actu = SDL_GetTicks();
      if (abs(enemy_D[0].p.x - sprite.p.x) <= 300)
      {
        if (abs(sprite.p.x - enemy_D[0].p.x) < 10 && prec1 - actu1 > 3000 && (sprite.p.y + sprite.clip[0].h) >= enemy_D[0].p.y)
        {
          actu1 = SDL_GetTicks();
          if (nb_life < 4)
            nb_life++;
          score_finale -= 50;
        }
        if (sprite.p.x > enemy_D[0].p.x && abs(sprite.p.x - enemy_D[0].p.x) > 10)
        {
          if (frame_enemy >= 3.9)
            frame_enemy = 0;
          else
            frame_enemy += 0.3;
          enemy_D[0].p.x += 3;
          r_enemy = 1;
          l_enemy = 0;
        }
        if (sprite.p.x < enemy_D[0].p.x && abs(sprite.p.x - enemy_D[0].p.x) > 10)
        {
          if (frame_enemy >= 3.9)
            frame_enemy = 0;
          else
            frame_enemy += 0.3;
          enemy_D[0].p.x -= 3;
          r_enemy = 0;
          l_enemy = 1;
        }
      }
      else
      {
        first = 0;
      }
    }
    else if (first != 1)
    {
      if ((positionFond.x > 2100 && positionFond.x < 3700))
      {
        /* if(enemy_D[0].p.x>2100 && enemy_D[0].p.x<3700) */
        move_ennemi(enemy_D, &r_enemy, &l_enemy, &frame_enemy,sprite.p);
		}
    }
    if (collision1 && enigme == 0)
    {

      sprite.vx = 0;
      enigme = 1;
      running2 = 1, r = 0;
      update(screen, Background, sprite, enemy_D, enemy_G, r_enemy, l_enemy, frame, frame_enemy, positionFond, l_pers, r_pers, box, texte, gestion_score, position1, position2, life, nb_life, box2, mask, first, enemy_2D, enemy_2G, chair, minimap, curseur_map);
     if(sprite.nb_joueurs==1)
{
sprite.num_joueur=choose(screen);
}
      do
      {
        running2 = 1;
        SDL_BlitSurface(Background, &positionFond, screen, NULL);
        r=maine(screen,sprite);
        SDL_Flip(screen);

      
        while (running2)
        {

          SDL_WaitEvent(&event);
          switch (event.type)
          {
          case SDL_QUIT:
            running2 = 0;
            *running = 0;
            break;
          case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
            case SDLK_RETURN:
              running2 = 0;

              break;
            case SDLK_SPACE:
              running2 = 0;
              break;
            }
            break;
          }
        }
        if (r != 1)
          score_finale -= 50;
        else
          score_finale += 500;
      } while (r != 1);
    }
    if (nb_life == 4 || score_finale <= 0)
    {
      while (running3)
      {
        //SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
        SDL_BlitSurface(life[4].image, NULL, screen, &(life[4].p));
        SDL_Flip(screen);
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
          running3 = 0;
          *running = 0;
          break;
        case SDL_KEYDOWN:

          switch (event.key.keysym.sym)

          {
          case SDLK_ESCAPE:
            running3 = 0;
            *running = 0;
            break;
          }
          break;
        }
      }
    }
    if (exit)
    {
        if (j == 2)
          SDL_BlitSurface(quitter.image, NULL, screen, &(quitter.p));
        else if (j == 1)
          SDL_BlitSurface(quitter2.image, NULL, screen, &(quitter2.p));
      exitt = 1;
      running5 = 1;
      exit = 0;
      while (running5)
      {



        SDL_Flip(screen);
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:

          break;
        case SDL_KEYDOWN:

          switch (event.key.keysym.sym)

          {
          case SDLK_ESCAPE:
            break;
          case SDLK_RIGHT:
            update(screen, Background, sprite, enemy_D, enemy_G, r_enemy, l_enemy, frame, frame_enemy, positionFond, l_pers, r_pers, box, texte, gestion_score, position1, position2, life, nb_life, box2, mask, first, enemy_2D, enemy_2G, chair, minimap, curseur_map);

            j = 1;
            if (j == 2)
              SDL_BlitSurface(quitter.image, NULL, screen, &(quitter.p));
            else if (j == 1)
              SDL_BlitSurface(quitter2.image, NULL, screen, &(quitter2.p));
            break;
          case SDLK_LEFT:
            update(screen, Background, sprite, enemy_D, enemy_G, r_enemy, l_enemy, frame, frame_enemy, positionFond, l_pers, r_pers, box, texte, gestion_score, position1, position2, life, nb_life, box2, mask, first, enemy_2D, enemy_2G, chair, minimap, curseur_map);

            j = 2;
            if (j == 2)
              SDL_BlitSurface(quitter.image, NULL, screen, &(quitter.p));
            else if (j == 1)
              SDL_BlitSurface(quitter2.image, NULL, screen, &(quitter2.p));
            break;
          case SDLK_RETURN:
            if (j)
            {
              running5 = 0;
              *running = 0;
            }
            if (j == 2)
            {
              FILE *f = fopen("save_file", "w");
              fprintf(f, "%hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %d %d %d %d %d \n", positionFond.x, positionFond.y, sprite.p.x, sprite.p.y, enemy_D[0].p.x, enemy_D[0].p.y, box.p.x, box.p.y, box2.p.x, box2.p.y, nb_life, score_finale, seconde, minute, level);

              running5 = 0;
              *running = 0;
              fclose(f);
            }

            break;
          }
          break;
        }
      }
    }
    update_fonts(&tempsActuel, &tempsPrecedent, &compteurr, &seconde, temps, score, &score_finale, &texte, &gestion_score, police, couleurBlanche, &minute);
    //if(enemy_D[0].p.x>2100 && enemy_D[0].p.x<3700)
    if ((positionFond.x > 2100 && positionFond.x < 3700))
        move_ennemi(enemy_D, &r_enemy, &l_enemy, &frame_enemy,sprite.p);
	
    update(screen, Background, sprite, enemy_D, enemy_G, r_enemy, l_enemy, frame, frame_enemy, positionFond, l_pers, r_pers, box, texte, gestion_score, position1, position2, life, nb_life, box2, mask, first, enemy_2D, enemy_2G, chair, minimap, curseur_map);
    if (sprite.p.x > 1150)
    {
      if (level == 1)
        level = 2;
      else if (level == 2)
        level = 3;
      else if (level == 3)
        level = 4;

      *running = 0;
    }
    else if (level == 3)
    {
      if (exitt == 1)
        level = 0;
    }
  }
  TTF_Quit();
  return level;
}
