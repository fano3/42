#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "mlx/mlx.h"

#define SCR_WIDTH 1280.0
#define SCR_HEIGHT 720.0

#define BLACK 0x000000
#define RED 0xff0000
#define GREEN 0x5d9560
#define WHITE 0xfdfbfb
#define PURPLE 0x9b329f

#define RAD 0.0174533

#define SENSIBILITY 6
#define SPEED 0.2

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363

typedef struct s_img
{
	void *img;
	char *addr;
	int bpp;
	int ll;
	int endian;
	int w;
	int h;

}			t_img;

typedef struct s_player
{
	float y;
	float x;
	float a;

} t_player;

typedef struct	s_cube3d
{
	char *no;
	char *so;
	char *we;
	char *ea;

	int ceiling;
	int floor;
	int w;
	int s;
	int a;
	int d;
	int	tl;
	int	tr;

    float		wall_height[(int) SCR_WIDTH];
	float		radius_lenght[(int) SCR_WIDTH];
	char		**map;
	void		*mlx_ptr;
	void		*mlx_win;

	t_img		img;
	t_player	player;
}				t_cube3d;

void parse(t_cube3d *cub3d, char *av);
void fill(t_cube3d *cub3d, char *str);
int ft_color(char *tmp);
void ft_init(t_cube3d *cub3d);
int check(t_cube3d *cub3d);
int count_raw(int fd, char *str);
void free_struct(t_cube3d *cub3d);
void ft_fill_matrix(char *file_name, t_cube3d *cub3d, int size, int skip);
void print_struct(t_cube3d cub3d);
void ft_error_cube(char *str, t_cube3d *cub3d);
void check_path(t_cube3d *cub3d);
int check_element_map(int i, int j, char **map);
void check_map(t_cube3d *cub3d);
int ft_open(char *file_name, t_cube3d *cub3d);
void ft_init_position(t_cube3d *cub3d);
void my_mlx_pixel_put(t_img *img, int x, int y, int color);
void    find_distance(t_cube3d *cub3d, float kurt_angle, int x);
void    fan_radius(t_cube3d *cub3d);
void    draw_walls(t_cube3d *cub3d, int x);
void    movement (t_cube3d *cub3d);
int	key_on(int keycode, t_cube3d *cub3d);
int	key_off(int keycode, t_cube3d *cub3d);
void	do_movement(t_cube3d *cub3d, float angle);
void    movement(t_cube3d *cub3d);

#endif