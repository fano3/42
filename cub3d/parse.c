#include "cub3d.h"

int ft_open(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error("file error\n");
	return fd;
}

void parse(t_cube3d *cub3d, char *file_name)
{
	int fd;
	int i;
	int j;
	char *str;

	fd = ft_open(file_name);
	j = 0;
	str = get_next_line(fd);
	i = 0;
	while (str != NULL && !check(cub3d))
	{
		fill(cub3d, str);
		free(str);
		str = get_next_line(fd);
		j++;
	}
	i = count_raw(fd, str);
	close(fd);
	ft_fill_matrix(file_name, cub3d, i, j);
}

void ft_fill_matrix(char *file_name , t_cube3d *cub3d, int size, int skip)
{
	char *str;
	int i;
	int fd;

	fd = ft_open(file_name);
	cub3d->map = malloc(sizeof(char *) * (size + 1));
	while(skip >= 0)
	{
		skip--;
		str = get_next_line(fd);
		free(str);
	}
	i = 0;
	while(i < size)
	{
		str = get_next_line(fd);
		if (str[0] != '\n')
		{
			cub3d->map[i] = ft_strdup(str);
			i++;
		}
		free(str);
	}
	cub3d->map[i] = NULL;
	close(fd);
}

int check(t_cube3d *cub3d)
{
	if (cub3d->cieling == -1 || cub3d->floor == -1)
		return(0);
	if (cub3d->ea == NULL || cub3d->no == NULL || cub3d->so == NULL || cub3d->we == NULL)
		return(0);
	return(1);
}

void fill(t_cube3d *cub3d, char *str)
{
	char **tmp;
	tmp = ft_split(str, ' ');

	if (tmp[0] == NULL)
		return;
	else if (!ft_strncmp(tmp[0], "NO", 2))
		cub3d->no = ft_strdup(tmp[1]);
	else if (!ft_strncmp(tmp[0], "SO", 2))
		cub3d->so = ft_strdup(tmp[1]);
	else if (!ft_strncmp(tmp[0], "WE", 2))
		cub3d->we = ft_strdup(tmp[1]);
	else if (!ft_strncmp(tmp[0], "EA", 2))
		cub3d->ea = ft_strdup(tmp[1]);
	else if (!ft_strncmp(tmp[0], "C", 1))
		cub3d->cieling = ft_color(tmp[1]);
	else if (!ft_strncmp(tmp[0], "F", 1))
		cub3d->floor = ft_color(tmp[1]);
	ft_free_matrix((void **)tmp);
}

int ft_color(char *tmp)
{
	int r;
	int g;
	int b;
	char **color;

	color = ft_split(tmp, ',');
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	ft_free_matrix((void **) color);
	return (r * 65536 + g * 256 + b);
}

int count_raw(int fd, char *str)
{
	int i;

	i = 0;
	while (str != NULL)
	{
		if (str[0] != '\n')
			i++;
		free(str);
		str = get_next_line(fd);
	}
	return(i);
}