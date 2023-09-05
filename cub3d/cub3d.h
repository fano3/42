#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


typedef struct s_cube3d
{
    char *no;
    char *so;
    char *we;
    char *ea;

    int cieling;
    int floor;

    char **map;
} t_cube3d;

void parse(t_cube3d *cub3d, char *av);
void fill(t_cube3d *cub3d, char *str);
int ft_color(char *tmp);
void ft_init(t_cube3d *cub3d);
int check(t_cube3d *cub3d);
int count_raw(int fd, char *str);
void free_struct(t_cube3d *cub3d);
void ft_fill_matrix(char *file_name, t_cube3d *cub3d, int size, int skip);
int ft_open(char *file_name);
void    print_struct(t_cube3d cub3d);

#endif