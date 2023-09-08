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
	cub3d->radius_lenght[x] = dist * cos(kurt_angle - (cub3d->player.a * RAD));
	find_orient(cub3d, kurt_angle, dist, x);
}

void	find_orient(t_cube3d *cub3d, float kurt_angle, float dist, int i)
{
	float	c;
	float	s;
	float	p_x;
	float	p_y;

	dist -= 0.01;
	c = cos(kurt_angle);
	s = sin(kurt_angle);
	p_y = cub3d->player.y + s * dist;
	p_x = cub3d->player.x + c * dist;
	if (cub3d->map[(int)(p_y - 0.01)][(int)p_x] == '1')
		cub3d->orien[i] = 0;
	else if (cub3d->map[(int)(p_y + 0.01)][(int)p_x] == '1')
		cub3d->orien[i] = 1;
	else if (cub3d->map[(int)p_y][(int)(p_x - 0.01)] == '1')
		cub3d->orien[i] = 2;
	else
		cub3d->orien[i] = 3;
}

void draw_colums(t_cube3d *cub3d, int x, int color)
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
			my_mlx_pixel_put(&cub3d->img, x, y, color);
		else
			my_mlx_pixel_put(&cub3d->img, x, y, cub3d->floor);
		y++;
	}
}

void draw_walls(t_cube3d *cub3d)
{
	int i;

	i = 0;
	while(i < SCR_WIDTH)
	{
		if (cub3d->orien[i] == 0)
			draw_colums(cub3d, i, WHITE);
		else if (cub3d->orien[i] == 1)
			draw_colums(cub3d, i, PURPLE);
		else if (cub3d->orien[i] == 2)
			draw_colums(cub3d, i, BLACK);
		else
			draw_colums(cub3d, i, GREEN);
		i++;
	}
}

//void	texture_x(t_data *cub3d, int i, float p_x, float p_y)
//{
//	if (cub3d->orien[i] == 0)
//		cub3d->wall_x[i] = floor((p_x - floor(p_x)) * cub3d->tex[0].w);
//	else if (cub3d->orien[i] == 1)
//		cub3d->wall_x[i] = cub3d->tex[1].w
//			- floor((p_x - floor(p_x)) * cub3d->tex[1].w);
//	else if (cub3d->orien[i] == 2)
//		cub3d->wall_x[i] = cub3d->tex[2].w
//			- floor((p_y - floor(p_y)) * cub3d->tex[2].w);
//	else if (cub3d->orien[i] == 3)
//		cub3d->wall_x[i] = floor((p_y - floor(p_y)) * cub3d->tex[3].w);
//	else if (cub3d->orien[i] == 4)
//		cub3d->wall_x[i] = floor((p_x - floor(p_x)) * cub3d->tex[4].w);
//	else if (cub3d->orien[i] == 5)
//		cub3d->wall_x[i] = cub3d->tex[4].w
//			- floor((p_x - floor(p_x)) * cub3d->tex[4].w);
//	else if (cub3d->orien[i] == 6)
//		cub3d->wall_x[i] = cub3d->tex[4].w
//			- floor((p_y - floor(p_y)) * cub3d->tex[4].w);
//	else
//		cub3d->wall_x[i] = floor((p_y - floor(p_y)) * cub3d->tex[4].w);
//}