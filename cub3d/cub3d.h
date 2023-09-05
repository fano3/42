#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_player
{
    float y;
    float x;
    float a;

} t_player;


typedef struct s_cube3d
{
    char *no;
    char *so;
    char *we;
    char *ea;

    int cieling;
    int floor;

    char **map;

    t_player    player;
} t_cube3d;

void parse(t_cube3d *cub3d, char *av);
void fill(t_cube3d *cub3d, char *str);
int ft_color(char *tmp);
void ft_init(t_cube3d *cub3d);
int check(t_cube3d *cub3d);
int count_raw(int fd, char *str);
void free_struct(t_cube3d *cub3d);
void ft_fill_matrix(char *file_name, t_cube3d *cub3d, int size, int skip);
void    print_struct(t_cube3d cub3d);
void	ft_error_cube(char *str, t_cube3d *cub3d);
void check_path(t_cube3d *cub3d);
int check_element_map(int i, int j, char **map);
void check_map(t_cube3d *cub3d);
int ft_open(char *file_name, t_cube3d *cub3d);
void    ft_init_mlx(t_cube3d *cub3d);

#endif