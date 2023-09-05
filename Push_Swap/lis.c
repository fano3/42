/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:16:59 by mepifano          #+#    #+#             */
/*   Updated: 2023/03/08 12:47:09 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

void	ft_increment(int *index, int len)
{
	*index += 1;
	if (*index == len)
		*index = 0;
}

void	ft_overload(int **matrix, int head, int nb)
{
	int	i;

	i = 0;
	while (i <= head)
	{
		if (matrix[i][i] > nb)
			break ;
		i++;
	}
	ft_arr_copy(matrix[i - 1], matrix[i], i);
	matrix[i][i] = nb;
}

int	*ft_new_row(int *arr, int size, int nb)
{
	int	*arr2;

	arr2 = malloc(sizeof(int) * (size + 1));
	ft_arr_copy(arr, arr2, size);
	arr2[size] = nb;
	return (arr2);
}

void	ft_lis(t_stack *tstack)
{
	int	**matrix;
	int	index;
	int	head;

	head = 0;
	matrix = malloc(sizeof(int *) * tstack->lena);
	matrix[0] = malloc(sizeof(int) * tstack->lena);
	matrix[0][0] = 1;
	index = ft_find_index(tstack->pos, 1, tstack->lena);
	ft_increment(&index, tstack->lena);
	while (tstack->pos[index] != 1)
	{
		if (tstack->pos[index] > matrix[head][head])
		{
			head += 1;
			matrix[head] = ft_new_row(matrix[head - 1],
					head, tstack->pos[index]);
		}
		else
			ft_overload(matrix, head, tstack->pos[index]);
		ft_increment(&index, tstack->lena);
	}
	tstack->lis = matrix[head];
	tstack->size_lis = head + 1;
}
