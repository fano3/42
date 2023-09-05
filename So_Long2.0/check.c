/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:21:00 by marvin            #+#    #+#             */
/*   Updated: 2023/02/03 11:21:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rettangolo(t_map *map)
{
	int				x;
	unsigned int	y;

	x = 1;
	y = ft_strlen(map->map[0]);
	while (map->map[x])
	{
		if (y != ft_strlen(map->map[x]))
			return (0);
		x++;
	}
	return (1);
}

int	ft_check_collectible(t_map *map)
{
	int	c;
	int	x;
	int	y;

	c = 0;
	x = 0;
	y = 0;
	while (map->map[x])
	{
		while (map->map[x][y])
		{
			if (map->map[x][y] == 'C')
				c++;
			y++;
		}
		y = 0;
		x++;
	}
	if (c == 0)
		return (0);
	return (1);
}

int	ft_check_player(t_map *map)
{
	int	p;
	int	x;
	int	y;

	p = 0;
	x = 0;
	y = 0;
	while (map->map[x])
	{
		while (map->map[x][y])
		{
			if (map->map[x][y] == 'P')
				p++;
			y++;
		}
		y = 0;
		x++;
	}
	if (p != 1)
		return (0);
	return (1);
}

int	ft_check_exit(t_map *map)
{
	int	e;
	int	x;
	int	y;

	e = 0;
	x = 0;
	y = 0;
	while (map->map[x])
	{
		while (map->map[x][y])
		{
			if (map->map[x][y] == 'E')
				e++;
			y++;
		}
		y = 0;
		x++;
	}
	if (e != 1)
		return (0);
	return (1);
}

int	ft_check_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[x][y])
	{
		if (map->map[x][y] != '1' && map->map[x][y] != '\n')
			return (0);
		y++;
	}
	y -= 2;
	while (map->map[x])
	{
		if (map->map[x][y] != '1' && map->map[x][y] != '\n')
			return (0);
		x++;
	}
	return (1);
}
