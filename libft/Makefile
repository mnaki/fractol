# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/05 14:47:20 by nmohamed          #+#    #+#              #
#    Updated: 2014/04/16 15:35:48 by nmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		:=	\
			ft_atoi.c \
			ft_bzero.c \
			for_each.c \
			delete_each.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isblank.c \
			ft_iscntrl.c \
			ft_isdigit.c \
			ft_isgraph.c \
			ft_islower.c \
			ft_isprint.c \
			ft_ispunct.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_isxdigit.c \
			ft_itoa.c \
			ft_itoa_u.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memrchr.c \
			ft_memset.c \
			ft_printf.c \
			ft_printf_aux.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_replace_chr.c \
			ft_replace_wspace.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strnchr.c \
			ft_strnclr.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnrchr.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strsplit_spaces.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_delim.c \
			get_next_line.c \
			for_each_address.c

CC		:=	clang
NAME	:=	libft.a
INC		:=	./
OBJ		:=	$(SRC:.c=.o)
CFLAGS	:=	-Wall -Wextra -Werror -fPIC
DFLAGS	:=	-g -D DEBUG=1
ARFLAGS	:=	-rcs
AR		:=	ar

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o		:	%.c
			@$(CC) -o $@ -c -I $(INC) $(CFLAGS) $^

clean	:
			@-$(RM) $(OBJ)

fclean	:	clean
			@-$(RM) $(OBJ)
			@-$(RM) $(NAME)

re		:	fclean all

pre		:
			$(eval CFLAGS += $(DFLAGS))

debug	:	pre all
			@$(CC) -o test -I $(INC) $(CFLAGS) $(OBJ) main.c

.PHONY	:	all clean fclean re dry pre test debug
