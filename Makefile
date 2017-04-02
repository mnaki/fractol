# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/05 14:47:20 by nmohamed          #+#    #+#              #
#    Updated: 2015/11/22 16:13:47 by nmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		:=	callbacks.c draw_seg.c fill_img.c hook.c init_callbacks.c init_callbacks2.c init_callbacks3.c julia.c main.c mandelbrot.c mouse_callback.c put_pixel_to_img.c sets.c utils.c fracfrac.c

CC		:=	gcc
NAME	:=	fractol
INC		:=	-I/home/nmohamed/minilibx/ -I./ -I./libft -I./minilibx
OBJ		:=	$(SRC:.c=.o)
CFLAGS	:=	-Wall
LDFLAGS	:=	-L./libft -lft -L./minilibx -L$(HOME)/minilibx/ -lpthread -lmlx_Linux

ifeq ($(shell uname), Darwin)
LDFLAGS += -L/usr/X11/lib -framework OpenGL -framework AppKit -lX11 -lXext
else
LDFLAGS += -lX11 -lXext
endif

all		:	libft $(NAME)

$(NAME)	:	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) -lm 

libft	:
			@make -j -C libft

%.o		:	%.c
			@$(CC) -o $@ -c $(INC) $(CFLAGS) $^

clean	:
			-$(RM) $(OBJ)

fclean	:	clean
			-$(RM) $(OBJ)
			-$(RM) $(NAME)
			-make -C libft fclean

re		:	clean all

.PHONY: libft
.SILENT: all $(NAME) libft clean fclean re $(OBJ)
