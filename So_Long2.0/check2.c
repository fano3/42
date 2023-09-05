/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:30:32 by mepifano          #+#    #+#             */
/*   Updated: 2023/02/27 12:02:33 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_wall2(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[x])
	{
		if (map->map[x][y] != '1' && map->map[x][y] != '\n')
			return (0);
		x++;
	}
	x--;
	while (map->map[x][y])
	{
		if (map->map[x][y] != '1' && map->map[x][y] != '\n')
			return (0);
		y++;
	}
	return (1);
}

void	checkargs(int ac, char **av, t_map *map, char c)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (ft_error("Error\nNummero di argomenti non valido"));
	if (!av[1] || av[1][0] == 0)
		return (ft_error("Error\nInserisci una mappa"));
	if (fd == -1)
		return (ft_error("Error\nMappa inserita non valida"));
	if (read(fd, &c, 1) == 0)
		return (ft_error("Error\nMappa non trovata"));
	init_text((map));
	if (!ft_check_rettangolo(map))
	{
		free_all(map);
		return (ft_error("la mappa non è un rettangolo"));
	}
	if (!ft_check_collectible(map) || !ft_check_wall(map)
		|| !ft_check_wall2(map) || !ft_check_exit(map)
		|| !ft_check_player(map) || !ft_check_map(map))
	{
		free_all(map);
		return (ft_error("Error\nCaratteri non validi"));
	}
}

int	ft_check_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[x])
	{
		while (map->map[x][y])
		{
			if (map->map[x][y] != '1' && map->map[x][y] != 'P' && map->map[x][y]
				&& map->map[x][y] != '0' && map->map[x][y] != 'E'
				&& map->map[x][y] != 'C' && map->map[x][y] != '\n')
				return (0);
			y++;
		}
		x++;
		y = 0;
	}
	return (1);
}
