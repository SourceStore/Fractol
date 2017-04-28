# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 15:10:05 by rishchen          #+#    #+#              #
#    Updated: 2017/04/28 17:38:20 by rishchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = auxiliary_functions.c brains.c colors.c fractals.c init_fracts.c main.c\
	  mouse.c put_pixel.c set_functions.c

INC = -I ft_fract.h

OBJ = $(SRC:.c=.o)

LIBOBJ = make -C libft/

CFLAGS = -c -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBINC = -L./libft -lft

all: $(NAME)

obj: $(OBJ)

$(NAME) : liball obj
	gcc $(OBJ) $(LIBINC) $(MLXFLAGS) -o $(NAME)

%.o: %.c 
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

liball:
	@make -C libft/ all

libclean:
	@make -C libft/ clean

libfclean:
	@make -C libft/ fclean

libre: libfclean liball
