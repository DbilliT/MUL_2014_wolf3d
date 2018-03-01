/*
** my_create_window.c for my_create_window in /home/bechad_p/rendu/MUL_2014_wolf3d/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Jan  6 13:15:27 2015 Pierre Bechade
** Last update Tue Jan  6 13:42:26 2015 Pierre Bechade
*/

#include "my.h"

void	go_forward(t_graph *mlx)
{
  mlx->posx = mlx->posx + (0.08 * cos((mlx->angle /180.0) * M_PI));
  mlx->posy = mlx->posy + (0.08 * sin((mlx->angle /180.0) * M_PI));
  if (g_map[(int)(mlx->posx)][(int)(mlx->posy)] == 1)
    {
      mlx->posx = mlx->posx - (0.08 * cos((mlx->angle / 180.0) * M_PI));
      mlx->posy = mlx->posy - (0.08 * sin((mlx->angle / 180.0) * M_PI));
    }
}

void	go_back(t_graph *mlx)
{
  mlx->posx = mlx->posx - (0.08 * cos((mlx->angle /180.0) * M_PI));
  mlx->posy = mlx->posy - (0.08 * sin((mlx->angle /180.0) * M_PI));
  if (g_map[(int)(mlx->posx)][(int)(mlx->posy)]== 1)
    {
      mlx->posx = mlx->posx + (0.08 * cos((mlx->angle / 180.0) * M_PI));
      mlx->posy = mlx->posy + (0.08 * sin((mlx->angle / 180.0) * M_PI));
    }
}

void	rebuilt(t_graph mlx)
{
  write_pic(&mlx);
  build_wall(&mlx);
  mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img_ptr, 0, 0);
}

int	handle_key(int key_code, t_graph *my_data)
{
  if (key_code == 65361)
    my_data->angle += 15;
  else if (key_code == 65362)
    go_forward(my_data);
  else if (key_code == 65363)
    my_data->angle -= 15;
  else if (key_code == 65364)
    go_back(my_data);
  else if (key_code == 65307)
    {
      mlx_destroy_window(my_data->mlx, my_data->win);
      exit(0);
    }
  rebuilt(*my_data);
  return (0);
}

void	window(t_graph *my_data)
{
  my_data->img_ptr = mlx_new_image(my_data->mlx, LENGTH, HEIGHT);
  my_data->data = mlx_get_data_addr(my_data->img_ptr,
				    &my_data->bits_per_pixel,
				    &my_data->size_line,
				    &my_data->endian);
  create_image(my_data);
  write_pic(my_data);
  my_data->posx = 1.5;
  my_data->posy = 1.5;
  my_data->angle = 90;
  build_wall(my_data);
  mlx_put_image_to_window(my_data->mlx, my_data->win,
			  my_data->img_ptr, 0, 0);
  mlx_key_hook(my_data->win, handle_key, my_data);
}
