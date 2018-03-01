/*
** my.h for my in /home/bechad_p/rendu/MUL_2014_wolf3d/include
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Jan  6 13:11:52 2015 Pierre Bechade
** Last update Tue Jan  6 13:37:14 2015 Pierre Bechade
*/

#ifndef _WOLF_H
# define _WOLF_H

# define HEIGHT	(1000)
# define LENGTH	(1900)

#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <mlx.h>

typedef struct	s_graph
{
  void		*mlx;
  void		*win;
  char		*data;
  void		*img_ptr;
  int		bits_per_pixel;
  int		size_line;
  int		endian;
  int		*map;
  int		angle;
  int		init;
  float		x1;
  float		y1;
  float		x;
  float		a;
  float		posx;
  float		posy;
}		t_graph;

/* IN SRC/MY_CREATE_WINDOW.C */
void    go_forward(t_graph *mlx);
void    go_back(t_graph *mlx);
void    rebuilt(t_graph mlx);
int     handle_key(int key_code, t_graph *my_data);
void    window(t_graph *my_data);

/* IN SRC/MY_CREATE_WINDOW2.C */
void    mlx_pixel_put_to_img(t_graph *my_data, int x, int y, int color);
void    create_image(t_graph *graph);
void    write_pic(t_graph *graph);

/* IN SRC/MY_TOOLS.C */
void    my_putchar_e(char c);
void    my_putstr_e(char *str);
void    my_error(char *str);
void    *my_xmalloc(int size);

/* IN SRC/WALL.C */
void    new_walls(t_graph *mlx, int x, int h);
void    build_wall(t_graph *mlx);

extern int	g_map[10][10];

#endif /* WOLF_H */
