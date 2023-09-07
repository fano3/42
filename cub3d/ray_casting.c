#include "cub3d.h"

void    fan_radius(t_cube3d *cub3d)
{
    int i;
    float kurt_angle;

    kurt_angle = cub3d->player.a - 30.0;
    i = 0;
    while(i < SCR_WIDTH)
    {
		find_distance(cub3d, kurt_angle * RAD, i);
        kurt_angle += 60 / SCR_WIDTH; 
        i++;
    }

}

void    find_distance(t_cube3d *cub3d, float kurt_angle, int x)
{
    float s;
    float c;
    float dist;

    s = sin(kurt_angle);
    c = cos(kurt_angle);
	dist = 0.01;
    while(1)
    {
		if (cub3d->map[(int) (cub3d->player.y + s * dist)][(int) (cub3d->player.x + c * dist)] == '1')
			break ;
		dist += 0.01;
    }
	cub3d->radius_lenght[x] = dist;
    draw_walls(cub3d, x);
}

void draw_walls(t_cube3d *cub3d, int x)
{
    int		y;
	float	ceiling_height;

	cub3d->wall_height[x] = (SCR_HEIGHT / cub3d->radius_lenght[x]);
	ceiling_height = (SCR_HEIGHT - cub3d->wall_height[x]) / 2;
	y = 0;
	while (y < SCR_HEIGHT)
	{
		if (y < ceiling_height)
			my_mlx_pixel_put(&cub3d->img, x, y, cub3d->ceiling);
		else if (y < cub3d->wall_height[x] + ceiling_height)
			my_mlx_pixel_put(&cub3d->img, x, y, RED);
		else
			my_mlx_pixel_put(&cub3d->img, x, y, cub3d->floor);
		y++;
	}
}