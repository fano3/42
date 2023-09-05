/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:48:19 by mepifano          #+#    #+#             */
/*   Updated: 2023/02/08 17:37:09 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_map *map, int *x, int *y)
{
	*y = 0;
	while (*y < map->heigth)
	{
		*x = 0;
		while (*x < map->wheigth)
		{
			if (map->map[*y][*x] == 'P')
				return ;
			*x += 1;
		}
		*y += 1;
	}
}

int	ft_count_collectibles(t_map *map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < map->heigth)
	{
		j = 0;
		while (j < map->wheigth)
		{
			if (map->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

char	**read_map(int fd, t_map *map)
{
	int		i;
	char	**maps;

	i = 0;
	maps = ft_calloc(map->heigth + 1, sizeof(char *));
	while (i < map->heigth)
	{
		maps[i] = get_next_line(fd);
		map->wheigth = ft_strlen(maps[i]);
		i++;
	}
	close (fd);
	return (maps);
}

void	ft_line_count(char *path, t_map *map)
{
	char	*str;
	int		fd;

	fd = open(path, O_RDONLY);
	map->heigth = 0;
	str = get_next_line(fd);
	while (str)
	{
		map->heigth++;
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
}

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->heigth)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}