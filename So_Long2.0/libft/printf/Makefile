# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 16:08:45 by mabasset          #+#    #+#              #
#    Updated: 2022/02/17 12:42:41 by mabasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
SRCS = ft_char.c ft_number.c ft_printf.c ft_utility.c
OBJ = $(SRCS:.c=.o)
FLAGS =	-Wall -Wextra -Werror

$(NAME):
		gcc $(FLAGS) -c $(SRCS)

clean:
		rm -f $(OBJ)

fclean:	clean

re:		fclean
		$(NAME)

.PHONY: clean fclean re