#include "cub3d.h"

int main(int ac, char **av)
{
    t_cube3d cub3d;
    if (ac != 2)
        ft_error("Argument error\n");
    ft_init(&cub3d);
    parse(&cub3d, av[1]);
    
    print_struct(cub3d);
    free_struct(&cub3d);
    return (0);
}

void ft_init(t_cube3d *cub3d)
{
    cub3d->no = NULL;
    cub3d->we = NULL;
    cub3d->so = NULL;
    cub3d->ea = NULL;
    cub3d->floor = -1;
    cub3d->cieling = -1;
    cub3d->map = NULL;
}
