# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uhand <uhand@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 12:42:26 by uhand             #+#    #+#              #
#    Updated: 2019/04/19 10:44:26 by uhand            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

HEAD = ft_printf.h
SRC = main.c ft_printf.c lib_printf.c add_fnctns.c set_format.c set_type.c \
apply_flags.c formats_c_s.c other_formats.c
OBJ = $(addprefix $(OBJPATH)/,$(SRC:.c=.o))
FLAGS = -Wall -Wextra -Werror -g
LIB = -L libft -lft
LIBPATH = ./libft

OBJPATH = ./objects

all:
	mkdir -p $(OBJPATH)
	@make $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(LIB)

$(OBJPATH)/%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

clean:
	/bin/rm -rf $(OBJPATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
