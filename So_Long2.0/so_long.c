/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:38:04 by mepifano          #+#    #+#             */
/*   Updated: 2023/02/27 12:26:21 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;
	char	c;

	c = '0';
	if (ac < 2)
		return (0);
	map.count = 0;
	ft_line_count (av[1], &map);
	fd = open(av[1], O_RDONLY);
	map.map = read_map(fd, &map);
	checkargs(ac, av, &map, c);
	map.mlx_ptr = mlx_init();
	map.mlx_winptr = mlx_new_window(map.mlx_ptr, map.wheigth * 64,
			map.heigth * 64, "So_Long");
	init_text(&map);
	mlx_key_hook(map.mlx_winptr, ft_movement, &map);
	mlx_loop_hook(map.mlx_ptr, ft_game, &map);
	mlx_hook(map.mlx_winptr, 17, 0, ft_destroy, &map);
	mlx_loop(map.mlx_ptr);
}

int	ft_game(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->heigth)
	{
		j = 0;
		while (j < map->wheigth)
		{
			ft_put_image(map->map[i][j], i, j, map);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_destroy(t_map *map)
{
	int	i;

	mlx_destroy_window(map->mlx_ptr, map->mlx_winptr);
	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	exit(0);
}

void	ft_put_image(char c, int i, int j, t_map *map)
{
	if (!ft_count_collectibles(map) && c == 'E')
		c = 'e';
	if (c == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_winptr,
			map->text.wall, j * 64, i * 64);
	else if (c == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_winptr,
			map->text.floor, j * 64, i * 64);
	else if (c == 'P')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_winptr,
			map->text.player, j * 64, i * 64);
	else if (c == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_winptr,
			map->text.exitclosed, j * 64, i * 64);
	else if (c == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_winptr,
			map->text.collectible, j * 64, i * 64);
	else if (c == 'e')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_winptr,
			map->text.exitopen, j * 64, i * 64);
}

void	init_text(t_map *map)
{
	int	a;
	int	b;

	map->text.collectible = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/collectible1.xpm", &a, &b);
	map->text.exitclosed = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/exitclosed.xpm", &a, &b);
	map->text.exitopen = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/exitopen.xpm", &a, &b);
	map->text.player = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/player1.xpm", &a, &b);
	map->text.wall = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/Wall.xpm", &a, &b);
	map->text.floor = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/floor.xpm", &a, &b);
}
