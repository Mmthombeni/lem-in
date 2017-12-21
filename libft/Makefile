# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/10 10:59:46 by mmthombe          #+#    #+#              #
#    Updated: 2017/12/20 14:09:15 by mmthombe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libft.a

SRC =  ft_atoi.c ft_memcpy.c ft_memcmp.c ft_putchar.c ft_strdel.c ft_putstr.c \
	  ft_putnbr.c ft_strnew.c ft_strjoin.c ft_strnequ.c ft_strcpy.c \
	  ft_strsub.c ft_strsplit.c ft_strlen.c  ft_strcmp.c ft_isalpha.c \
	  ft_isdigit.c ft_strcat.c ft_strchr.c ft_strjoin.c ft_strncmp.c \
	  ft_strdel.c ft_strdup.c ft_create_node.c ft_list_push.c ft_putendl.c \
	  ft_list_pop.c get_next_line.c ft_memset.c ft_bzero.c ft_strcat.c \
	  ft_memalloc.c ft_strstr.c ft_wordlen.c \

FLAGS = gcc -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		$(FLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re: fclean all clean
