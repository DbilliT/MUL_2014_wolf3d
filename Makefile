##
## Makefile for Makefile in /home/bechad_p/rendu/MUL_2014_wolf3d
## 
## Made by Pierre Bechade
## Login   <bechad_p@epitech.net>
## 
## Started on  Tue Jan  6 13:16:09 2015 Pierre Bechade
## Last update Tue Jan  6 13:37:40 2015 Pierre Bechade
##

CC      =       gcc

RM      =       rm -f

CFLAGS  +=      -Werror -Wall -W -Wextra

CFLAGS	+=	-I./include/

CFLAGS	+=	-lXext -lX11 -lm -lmlx

NAME    =       wolf3d

SRCS    =       src/main.c		\
		src/my_create_window.c	\
		src/my_create_window2.c	\
		src/wall.c		\
		src/my_tools.c		\
		src/map.c

OBJS    =       $(SRCS:.c=.o)

all	: 	$(NAME)

$(NAME)	: 	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
