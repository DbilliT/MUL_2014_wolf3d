/*
** my_create_window2.c for my_create_window2 in /home/bechad_p/rendu/MUL_2014_wolf3d/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Jan  6 13:35:28 2015 Pierre Bechade
** Last update Tue Jan  6 13:43:17 2015 Pierre Bechade
*/

#include "my.h"

void	mlx_pixel_put_to_img(t_graph *my_data, int x, int y, int color)
{
  int	i;

  if (x > 0 && y > 0)
    {
      i = (my_data->size_line * y) + (x * my_data->bits_per_pixel / 8);
      my_data->data[i + 0] = color >> 0;
      my_data->data[i + 1] = color >> 8;
      my_data->data[i + 2] = color >> 16;
    }
}

void	create_image(t_graph *graph)
{
  graph->img_ptr = mlx_new_image(graph->mlx, LENGTH, HEIGHT);
  graph->data = mlx_get_data_addr(graph->img_ptr, &graph->bits_per_pixel,
                                  &graph->size_line, &graph->endian);
}

void	write_pic(t_graph *graph)
{
  int	x;
  int	y;

  y = 0;
  while (y < (HEIGHT / 2))
    {
      x = 0;
      while (x < LENGTH)
        {
          mlx_pixel_put_to_img(graph, x, y, 0x3399CC);
          x++;
        }
      y++;
    }
  while (y < HEIGHT)
    {
      x = 0;
      while (x < LENGTH)
        {
          mlx_pixel_put_to_img(graph, x, y, 0x663300);
          x++;
        }
      y++;
    }
}
