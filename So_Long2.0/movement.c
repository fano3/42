/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:39:54 by mepifano          #+#    #+#             */
/*   Updated: 2023/02/06 12:16:48 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_movement(int key, t_map *map)
{
	if (key == 53)
		ft_destroy(map);
	if (key == 0)
		ft_sx(map);
	if (key == 1)
		ft_down(map);
	if (key == 2)
		ft_dx(map);
	if (key == 13)
		ft_up(map);
	return (0);
}

void	ft_sx(t_map *map)
{
	int	x;
	int	y;

	ft_find_player(map, &x, &y);
	if (map->map[y][x - 1] == 'E' && !ft_count_collectibles(map))
		ft_destroy(map);
	if (map->map[y][x - 1] == '1' || map->map[y][x - 1] == 'E')
		return ;
	map->map[y][x - 1] = 'P';
	map->map[y][x] = '0';
	map->count++;
	ft_printf("moves:%d\n", map->count);
}

void	ft_dx(t_map *map)
{
	int	x;
	int	y;

	ft_find_player(map, &x, &y);
	if (map->map[y][x + 1] == 'E' && !ft_count_collectibles(map))
		ft_destroy(map);
	if (map->map[y][x + 1] == '1' || map->map[y][x + 1] == 'E')
		return ;
	map->map[y][x + 1] = 'P';
	map->map[y][x] = '0';
	map->count++;
	ft_printf("moves:%d\n", map->count);
}

void	ft_down(t_map *map)
{
	int	x;
	int	y;

	ft_find_player(map, &x, &y);
	if (map->map[y + 1][x] == 'E' && !ft_count_collectibles(map))
		ft_destroy(map);
	if (map->map[y + 1][x] == '1' || map->map[y + 1][x] == 'E')
		return ;
	map->map[y + 1][x] = 'P';
	map->map[y][x] = '0';
	map->count++;
	ft_printf("moves:%d\n", map->count);
}

void	ft_up(t_map *map)
{
	int	x;
	int	y;

	ft_find_player(map, &x, &y);
	if (map->map[y - 1][x] == 'E' && !ft_count_collectibles(map))
		ft_destroy(map);
	if (map->map[y - 1][x] == '1' || map->map[y - 1][x] == 'E')
		return ;
	map->map[y - 1][x] = 'P';
	map->map[y][x] = '0';
	map->count++;
	ft_printf("moves:%d\n", map->count);
}
