#include "cub3d.h"

void free_struct(t_cube3d *cub3d)
{
    if (cub3d->ea)
        free(cub3d->ea);
    if(cub3d->no)
        free(cub3d->no);
    if(cub3d->so)
        free(cub3d->so);
    if(cub3d->we)
        free(cub3d->we);
    if(cub3d->map != NULL)
        ft_free_matrix((void **)cub3d->map);
}

void    print_struct(t_cube3d cub3d)
{
    int i = 0;

    printf("%s\n", cub3d.no);
    printf("%s\n", cub3d.so);
    printf("%s\n", cub3d.ea);
    printf("%s\n", cub3d.we);
    printf("%d\n", cub3d.cieling);
    printf("%d\n", cub3d.floor);
    while (cub3d.map[i] != NULL)
    {
        printf("%s\n", cub3d.map[i]);
        i++;
    }
    return;
}

void	ft_error_cube(char *str, t_cube3d *cub3d)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	
	exit(1);
}

int ft_open(char *file_name, t_cube3d *cub3d)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error_cube("file error\n", cub3d);
	return fd;
}
