#include "cub3d"

void    fan_radius(t_cube3d *cub3d)
{
    int i;
    float kurt_angle;

    kurt_angle = cub3d.player.a - 30.0;
    i = 0;
    while(i < SCR_WIDTH)
    {
		find_distance(cub3d, kurt_angle * RAD, i);
        kurt_angle +=  60/SCR_WIDTH; 
        i++;
    }
}

void    find_distance(t_cube3d *cub3, float kurt_angle, int x)
{
    float s;
    float c;
    float dist;

    s = sin(kurt_angle);
    c = cos(kurt_angle);
	dist = 0.01;
    while(1)
    {
		if (cub3->map[(int) (cub3d->player.y + s * dist)][(int) (cub3->player.x + c * dist)] == '1')
			break ;
		dist += 0.01;
    }
	cub3d.radius_lenght[x] = dist;
}