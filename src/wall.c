/*
** wall.c for wall in /home/bechad_p/rendu/MUL_2014_wolf3d/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Jan  6 13:33:42 2015 Pierre Bechade
** Last update Tue Jan  6 13:39:28 2015 Pierre Bechade
*/

#include "my.h"

void    new_walls(t_graph *mlx, int x, int h)
{
  int   k;
  int   y;

  k = 0;
  y = (HEIGHT / 2) - h;
  while (y < (HEIGHT / 2) + h)
    {
      mlx_pixel_put_to_img(mlx, x, y++, 0xFF0099);
      k++;
    }
}

void    build_wall(t_graph *mlx)
{
  float x_prime;
  float y_prime;
  float k;
  float h;

  mlx->x1 = 0.5;
  mlx->x = 0;
  mlx->a = mlx->angle / 180.0 * M_PI;
  while (mlx->x < LENGTH)
    {
      k = 1.0;
      mlx->y1 = ((LENGTH) / 2.0 - mlx->x) / (HEIGHT);
      x_prime = (mlx->x1 * cos(mlx->a)) - (mlx->y1 * sin(mlx->a));
      y_prime = (mlx->x1 * sin(mlx->a)) + (mlx->y1 * cos(mlx->a));
      while (g_map[(int)(mlx->posx
			 + k * x_prime)][(int)(mlx->posy
					       + k * y_prime)] == 0)
        k = k + 0.01;
      h = HEIGHT / (2.0 * k);
      mlx->x = mlx->x + 1;
      new_walls(mlx, mlx->x, h);
    }
}
