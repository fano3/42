/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:37:40 by mepifano          #+#    #+#             */
/*   Updated: 2023/03/08 12:47:09 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(int *arr, int nb, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_max(int *ar, int size, int nb)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ar[i] > nb)
			return (0);
		i++;
	}
	return (1);
}

void	ft_arr_copy(int *arr1, int *arr2, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr2[i] = arr1[i];
		i++;
	}
}

void	ft_push(t_stack *tstack)
{
	int	i;
	int	j;

	while (tstack->size_lis < tstack->lena)
	{
		i = 0;
		while (i < tstack->lena)
		{
			j = 0;
			while (j < tstack->size_lis)
			{
				if (tstack->pos[i] == tstack->lis[j])
					break ;
				j++;
			}
			if (j == tstack->size_lis)
			{
				ft_afk(tstack, i);
				i = -1;
			}
			i++;
		}		
	}
}

void	ft_sort(t_stack *tstack)
{
	int	i;

	i = 0;
	while (tstack->pos[i] != 1)
		i++;
	if ((tstack->lena / 2) >= i)
	{
		while (tstack->pos[0] != 1)
		{
			ft_ra(tstack, 0);
		}
	}
	if ((tstack->lena / 2) < i)
	{
		while (tstack->pos[0] != 1)
		{
			ft_rra(tstack, 0);
		}
	}
}
