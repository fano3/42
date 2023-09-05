#include "cub3d.h"
void check_path(t_cube3d *cub3d)
{
    int fd;

    fd = ft_open(cub3d->ea, cub3d);
    if (fd < 0)
        close(fd);
    fd = ft_open(cub3d->we, cub3d);
    if (fd < 0)
        close(fd);
    fd = ft_open(cub3d->no, cub3d);
    if (fd < 0)
        close(fd);
    fd = ft_open(cub3d->so, cub3d);
    if (fd < 0)
        close(fd);
}

void check_map(t_cube3d *cub3d)
{
    int i;
    int j;
    int count;
    char c;

    count = 0;
    i = 0;
    while (cub3d->map[i])
    {
        j = 0;
        while (cub3d->map[i][j])
        {
            c = cub3d->map[i][j];
            if (c == 'S' || c == 'N' || c == 'O' || c == 'E')
                count++;
            if(check_element_map(i, j, cub3d->map) == 1)
                ft_error_cube("Error, insert a valid map\n", cub3d);
            j++;
        }
        i++;
    }
    if (count != 1)
        ft_error_cube("Too many players\n", cub3d);
}

int check_element_map(int i, int j, char **map)
{
    char c;

    c = map[i][j];
    if (c != 'S' && c != 'N' && c != 'W' && c != 'E' && c != '1' && c != '0' && c != ' ')
        return(1);
    else if(c == 'S' || c == 'N' || c == 'W' || c == 'E' || c == '0')
    {
        if ((i - 1) < 0 || (j - 1) < 0 || map[i + 1] == NULL)
            return (1);
        if (map[i][j + 1] == '\0')
            return(1);
    }
    return (0);
}