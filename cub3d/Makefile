NAME = cub3d
SRC = *.c
FLG = -Wall -Wextra -Werror -lXext -lX11 -lm -lGL

$(NAME):
# make -C mlx/
# make -C libft/
		gcc $(SRC) -o $(NAME) libft/libft.a mlx/libmlx.a $(FLG)
clean:
		rm -rf *.o

fclean:
		rm -rf $(NAME)
# make clean -C mlx
# make fclean -C libft

all:	$(NAME)

re:		fclean all