# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/16 17:24:33 by mmthombe          #+#    #+#              #
#    Updated: 2017/12/16 17:37:20 by mmthombe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = lemin.c ant_farm.c ant_path.c error_handle.c short_dist.c move_ants.c

FLAGS = gcc -Wall -Wextra -Werror 

LIBFT = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	$(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

clean:
	make -C libft/ clean

fclean:
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all clean
