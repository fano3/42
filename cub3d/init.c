#include "cub3d.h"
void ft_init(t_cube3d *cub3d)
{
    cub3d->w = 0;
	cub3d->s = 0;
	cub3d->a = 0;
	cub3d->d = 0;
    cub3d->no = NULL;
    cub3d->we = NULL;
    cub3d->so = NULL;
    cub3d->ea = NULL;
    cub3d->floor = -1;
    cub3d->ceiling = -1;
    cub3d->map = NULL;
    cub3d->tl = 0;   
    cub3d->tr = 0;
}

void    ft_init_position(t_cube3d *cub3d)
{
    int i;
    int j;
    char c;

    i = 0;
    while (cub3d->map[i])
    {
        j = 0;
        while (cub3d->map[i][j])
        {   
            c = cub3d->map[i][j];
            if (c == 'N' || c == 'S' || c == 'O' || c == 'E')
            {
                cub3d->player.y = (float) i + 0.5;
                cub3d->player.x = (float) j + 0.5;
                if (c == 'E')
                    cub3d->player.a = 0.0;
                if (c == 'N')
                    cub3d->player.a = 270.0;
                if (c == 'S')
                    cub3d->player.a = 90.0;
                if (c == 'O')
                    cub3d->player.a = 180.0;   
            }
            j++;
        }
        i++;
    }
    
}