/*
** my_tools.c for my_tools in /home/bechad_p/rendu/MUL_2014_wolf3d/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Jan  6 13:14:28 2015 Pierre Bechade
** Last update Tue Jan  6 13:43:32 2015 Pierre Bechade
*/

#include "my.h"

void	my_putchar_e(char c)
{
  write(2, &c, 1);
}

void	my_putstr_e(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar_e(str[i]);
      i++;
    }
}

void	my_error(char *str)
{
  my_putstr_e(str);
  exit(0);
}

void	*my_xmalloc(int size)
{
  void	*tmp;

  if ((tmp = malloc(size)) == NULL)
    {
      write(2, "Error malloc\n", 13);
      exit(0);
    }
  return (tmp);
}
