#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "mlx/mlx.h"

#define SCR_WIDTH 1920
#define SCR_HEIGHT 1080

# define BLACK 0x000000
# define RED 0xff0000
# define GREEN 0x5d9560
# define WHITE 0xfdfbfb
# define PURPLE 0x9b329f

# define RAD 0.0174533

typedef struct  s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		w;
	int		h;

}               t_img;
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

    float   radius_lenght[SCR_WIDTH]
    char **map;
    void *mlx_ptr;
    void *mlx_win;

    t_img       img;
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
void    ft_init_position(t_cube3d *cub3d);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif