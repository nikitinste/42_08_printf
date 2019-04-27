# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uhand <uhand@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 12:42:26 by uhand             #+#    #+#              #
#    Updated: 2019/04/27 11:41:39 by uhand            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEAD = ft_printf.h
SRC = ft_printf.c lib_printf.c add_fnctns.c set_format.c apply_flags.c \
formats_c_s.c format_float.c formats_int.c pft_itoa.c pft_unsigned_itoa.c \
pft_float_itoa.c

OBJ = $(addprefix $(OBJPATH)/,$(SRC:.c=.o))
FLAGS = -Wall -Wextra -Werror -g
LIB = -L libft -lft
LIBPATH = ./libft

OBJPATH = ./objects

all:
	mkdir -p $(OBJPATH)
	@make $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) libft/*.o

$(OBJPATH)/%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

clean:
	/bin/rm -rf $(OBJPATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
