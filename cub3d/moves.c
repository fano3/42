#include "cub3d.h"

int	key_on(int keycode, t_cube3d *cub3d)
{
	if (keycode == W)
		cub3d->w = 1;
	if (keycode == A)
		cub3d->a = 1;
	if (keycode == S)
		cub3d->s = 1;
	if (keycode == D)
		cub3d->d = 1;
	if (keycode == LEFT)
		cub3d->tl = 1;
	if (keycode == RIGHT)
		cub3d->tr = 1;
	return (0);
}

int	key_off(int keycode, t_cube3d *cub3d)
{
	if (keycode == W)
		cub3d->w = 0;
	if (keycode == A)
		cub3d->a = 0;
	if (keycode == S)
		cub3d->s = 0;
	if (keycode == D)
		cub3d->d = 0;
	if (keycode == LEFT)
		cub3d->tl = 0;
	if (keycode == RIGHT)
		cub3d->tr = 0;
	return (0);
}

void	do_movement(t_cube3d *cub3d, float angle)
{
	float	new_x;
	float	new_y;

	new_x = cub3d->player.x + cos(angle) * SPEED;
	if (cub3d->map[(int)cub3d->player.y][(int)new_x] != '1')
		cub3d->player.x = cub3d->player.x + cos(angle) * SPEED;
	new_y = cub3d->player.y + sin(angle) * SPEED;
	if (cub3d->map[(int)new_y][(int)cub3d->player.x] != '1')
		cub3d->player.y = cub3d->player.y + sin(angle) * SPEED;
}

void    movement(t_cube3d *cub3d)
{
	if (cub3d->w == 1)
		do_movement(cub3d, cub3d->player.a * RAD);
	if (cub3d->a == 1)
		do_movement(cub3d, (cub3d->player.a - 90) * RAD);
	if (cub3d->s == 1)
		do_movement(cub3d, (cub3d->player.a - 180) * RAD);
	if (cub3d->d == 1)
		do_movement(cub3d, (cub3d->player.a + 90) * RAD);
	if (cub3d->tl == 1)
		cub3d->player.a -= SENSIBILITY;
	if (cub3d->tr == 1)
		cub3d->player.a += SENSIBILITY;
}