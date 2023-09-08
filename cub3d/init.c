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

void	open_textures(t_cube3d *cub3d)
{
	cub3d->tex[0].img = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->no,
			&cub3d->tex[0].w, &cub3d->tex[0].h);
	cub3d->tex[0].addr = mlx_get_data_addr(cub3d->tex[0].img,
			&cub3d->tex[0].bpp, &cub3d->tex[0].ll, &cub3d->tex[0].endian);
	cub3d->tex[1].img = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->so,
			&cub3d->tex[1].w, &cub3d->tex[1].h);
	cub3d->tex[1].addr = mlx_get_data_addr(cub3d->tex[1].img,
			&cub3d->tex[1].bpp, &cub3d->tex[1].ll, &cub3d->tex[1].endian);
	cub3d->tex[2].img = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->we,
			&cub3d->tex[2].w, &cub3d->tex[2].h);
	cub3d->tex[2].addr = mlx_get_data_addr(cub3d->tex[2].img,
			&cub3d->tex[2].bpp, &cub3d->tex[2].ll, &cub3d->tex[2].endian);
	cub3d->tex[3].img = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->ea,
			&cub3d->tex[3].w, &cub3d->tex[3].h);
	cub3d->tex[3].addr = mlx_get_data_addr(cub3d->tex[3].img,
			&cub3d->tex[3].bpp, &cub3d->tex[3].ll, &cub3d->tex[3].endian);
}
