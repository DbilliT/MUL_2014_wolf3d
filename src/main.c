/*
** main.c for main in /home/bechad_p/rendu/MUL_2014_wolf3d/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Jan  6 13:33:57 2015 Pierre Bechade
** Last update Tue Jan  6 14:14:12 2015 Pierre Bechade
*/

#include "my.h"

int	handle_expose(t_graph *my_data)
{
  mlx_put_image_to_window(my_data->mlx,
			  my_data->win, my_data->img_ptr, 0, 0);
  return (0);
}

int		main()
{
  t_graph	*my_data;

  my_data = my_xmalloc(sizeof(t_graph));
  if ((my_data->mlx = mlx_init()) == NULL)
    {
      my_putstr_e("Issue with mlx_init or no environment\n");
      exit(0);
    }
  my_data->win = mlx_new_window(my_data->mlx,
				LENGTH, HEIGHT, "wolf3d bechad_p");
  window(my_data);
  mlx_expose_hook(my_data->win, &handle_expose, my_data);
  mlx_loop(my_data->mlx);
  return (0);
}
