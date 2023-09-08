#include "cub3d.h"

int loop_hok(t_cube3d *cub3d)
{
    cub3d->img.img = mlx_new_image(cub3d->mlx_ptr, SCR_WIDTH, SCR_HEIGHT);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, &cub3d->img.bpp,
	                &cub3d->img.ll, &cub3d->img.endian);
    movement(cub3d);
    fan_radius(cub3d);
    draw_walls(cub3d);
    mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->mlx_win, cub3d->img.img, 0, 0);
	mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.img);
    return (0);
}

int main(int ac, char **av)
{
    t_cube3d cub3d;
    if (ac != 2)
        ft_error("Argument error\n");
    ft_init(&cub3d);
    parse(&cub3d, av[1]);
    check_path(&cub3d);
    check_map(&cub3d);
    ft_init_position(&cub3d);
    cub3d.mlx_ptr = mlx_init();
    cub3d.mlx_win = mlx_new_window(cub3d.mlx_ptr, SCR_WIDTH, SCR_HEIGHT, "cub3d");
    open_textures(&cub3d);
    mlx_hook(cub3d.mlx_win, 2, (1L << 0), key_on, &cub3d);
	mlx_hook(cub3d.mlx_win, 3, (1L << 1), key_off, &cub3d);
    mlx_loop_hook(cub3d.mlx_ptr, loop_hok, &cub3d);
    mlx_loop(cub3d.mlx_ptr);
    print_struct(cub3d);
    //free_struct(&cub3d);
    return (0);
}

