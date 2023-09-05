/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:36:49 by mepifano          #+#    #+#             */
/*   Updated: 2023/02/27 12:05:57 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_text
{
	void	*collectible;
	void	*exitclosed;
	void	*exitopen;
	void	*wall;
	void	*player;
	void	*floor;
}	t_text;

typedef struct s_map
{
	char	**map;
	int		heigth;
	int		wheigth;
	int		count;
	void	*mlx_ptr;
	void	*mlx_winptr;
	t_text	text;
}	t_map;

char	**read_map(int fd, t_map *map);
void	ft_line_count(char *path, t_map *map);
void	init_text(t_map *map);
int		ft_destroy(t_map *map);
void	ft_put_image(char c, int i, int j, t_map *map);
int		ft_game(t_map *map);
int		ft_movement(int key, t_map *map);
void	ft_find_player(t_map *map, int *x, int *y);
void	ft_sx(t_map *map);
void	ft_dx(t_map *map);
void	ft_up(t_map *map);
void	ft_down(t_map *map);
int		ft_count_collectibles(t_map *map);
int		ft_check_wall2(t_map *map);
int		ft_check_rettangolo(t_map *map);
int		ft_check_collectible(t_map *map);
int		ft_check_player(t_map *map);
int		ft_check_exit(t_map *map);
int		ft_check_wall(t_map *map);
void	free_all(t_map *map);
void	checkargs(int ac, char **av, t_map *map, char c);
int		ft_check_map(t_map *map);

#endif