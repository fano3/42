NAME = push_swap
SRC = *.c
FLG = -Wall -Wextra -Werror

$(NAME):
		make -C libft
		gcc $(SRC) -o $(NAME) libft/libft.a

clean:
		make clean -C libft

fclean:	clean
		rm -rf $(NAME)
		make fclean -C libft

all:	$(NAME)

re:		fclean all