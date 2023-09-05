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