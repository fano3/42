/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:13:49 by mepifano          #+#    #+#             */
/*   Updated: 2023/03/07 10:58:26 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_ac(int ac)
{
	if (ac < 2)
		ft_error("Error\nInserire numeri\n");
}

void	ft_check_av(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (((av[i][j] > '9' || av[i][j] < '0') && av[i][j] != '-')
				|| (j > 0 && av[i][j] == '-'))
				ft_error("Error\nCaratteri non validi\n");
			j++;
		}
		if (av[i][0] == '-')
		{
			if (ft_strlen(av[i]) >= 11
				&& ft_strncmp(av[i], "-2147483648", 12) > 0)
				ft_error("Error\nNumero troppo piccolo\n");
		}
		if (ft_strlen(av[i]) >= 10 && ft_strncmp(av[i], "2147483647", 11) > 0)
			ft_error("Error\nNumero troppo grande\n");
	i++;
	j = 0;
	}
}

void	ft_check_doppi(t_stack *tstack)
{
	int	i;
	int	j;

	i = 1;
	while (i < tstack->lena - 1)
	{
		j = i + 1;
		while (j < tstack->lena)
		{
			if (tstack->a[i] == tstack->a[j])
			{
				free(tstack->a);
				free(tstack->b);
				ft_error("Error\nCaratteri doppi");
			}
			j++;
		}
		i++;
	}
}

void	ft_check_sort(t_stack *tstack)
{
	int	i;

	i = 0;
	while (i < tstack->lena - 1)
	{
		if (tstack->a[i] < tstack->a[i + 1])
			i++;
		else
			return ;
	}
	if (i == tstack->lena - 1)
	{
		free(tstack->a);
		free(tstack->b);
		exit(0);
	}
}
