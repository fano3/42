#include "cub3d.h"

int main(int ac, char **av)
{
    t_cube3d cub3d;
    if (ac != 2)
        ft_error("Argument error\n");
    ft_init(&cub3d);
    parse(&cub3d, av[1]);
    check_path(&cub3d);
    check_map(&cub3d);
    ft_init_mlx(&cub3d);
    print_struct(cub3d);
    free_struct(&cub3d);
    return (0);
}

