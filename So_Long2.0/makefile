NAME = so_long
SRCS = so_long.c check.c check2.c movement.c utils.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
KIT = -l mlx -framework openGL -framework AppKit 

$(NAME): 
		make -C libft
		gcc $(FLAGS) $(SRCS) libft/libft.a $(KIT) -o $(NAME)

all: 		$(NAME)

clean: 	
		make clean -C libft	
		rm -f $(OBJS)

fclean:	clean
		make fclean -C libft
		rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re