# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uhand <uhand@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 12:42:26 by uhand             #+#    #+#              #
#    Updated: 2019/04/15 18:04:10 by uhand            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

HEAD = ft_printf.h
SRC = main.c ft_printf.c lib_printf.c add_fnctns.c
OBJ = $(addprefix $(OBJPATH)/,$(SRC:.c=.o))
FLAGS = -Wall -Wextra -Werror -g

OBJPATH = ./objects

all:
	mkdir -p $(OBJPATH)
	@make $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJPATH)/%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

clean:
	/bin/rm -rf $(OBJPATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
