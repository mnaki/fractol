# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/05 14:47:20 by nmohamed          #+#    #+#              #
#    Updated: 2015/11/16 14:24:03 by nmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		:=	callbacks.c draw_seg.c fill_img.c hook.c init_callbacks.c init_callbacks2.c main.c put_pixel_to_img.c vector.c mouse_callback.c julia.c

CC		:=	gcc
NAME	:=	fractol
INC		:=	-I/home/nmohamed/minilibx/ -I./ -I./libft -I$(HOME)/minilibx_macos
OBJ		:=	$(SRC:.c=.o)
CFLAGS	:=	-Wall -Wextra -Werror -Wmissing-prototypes -g
LDFLAGS	:=	-L./libft -lft -L$(HOME)/minilibx_macos -L$(HOME)/minilibx/ -lmlx -lpthread

ifeq ($(shell uname), Darwin)
LDFLAGS += -framework OpenGL -framework AppKit
else
LDFLAGS += -lX11 -lXext
endif

all		:	libft $(NAME)

$(NAME)	:	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)  $(LDFLAGS) -lm

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
