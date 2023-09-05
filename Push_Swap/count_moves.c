/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:45:05 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 16:45:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_best	ft_count_moves(t_stack *tstack)
{
	t_best	*tbest;
	int		i;

	tbest = malloc(sizeof(t_best) * tstack->lenb);
	i = 0;
	while (i < tstack->lenb)
	{
		tbest[i].value_b = tstack->b[i];
		ft_search_value_a(tstack, &tbest[i]);
		ft_search_dir_a(&tbest[i], tstack);
		ft_search_dir_b(&tbest[i], tstack);
		if (tbest[i].dir_a == tbest[i].dir_b)
		{
			if (tbest[i].k_a > tbest[i].k_b)
				tbest[i].k = tbest[i].k_a;
			else
				tbest[i].k = tbest[i].k_b;
		}
		else
			tbest[i].k = tbest[i].k_a + tbest[i].k_b;
		i++;
	}
	return (ft_find_best(tbest, tstack->lenb));
}

void	ft_search_value_a(t_stack *tstack, t_best *tbest)
{
	int	i;

	i = 1;
	if (ft_max(tstack->pos, tstack->lena, tbest->value_b))
		tbest->value_a = 1;
	if ((tstack->pos[0] > tbest->value_b)
		&& (tstack->pos[tstack->lena - 1] < tbest->value_b))
		tbest->value_a = tstack->pos[0];
	while (i < tstack->lena)
	{
		if ((tstack->pos[i] > tbest->value_b)
			&& (tstack->pos[i - 1] < tbest->value_b))
			tbest->value_a = tstack->pos[i];
		i++;
	}
}

void	ft_search_dir_a(t_best *tbest, t_stack *tstack)
{
	int	i;

	i = 0;
	while (i < tstack->lena)
	{
		if (tstack->pos[i] == tbest->value_a)
		{
			if (i > tstack->lena / 2)
			{
				tbest->dir_a = 1;
				tbest->k_a = tstack->lena - i;
			}
			else
			{
				tbest->dir_a = 0;
				tbest->k_a = i;
			}
		}
		i++;
	}
}

void	ft_search_dir_b(t_best *tbest, t_stack *tstack)
{
	int	i;

	i = 0;
	while (i < tstack->lenb)
	{
		if (tstack->b[i] == tbest->value_b)
		{
			if (i > tstack->lenb / 2)
			{
				tbest->dir_b = 1;
				tbest->k_b = tstack->lenb - i;
			}
			else
			{
				tbest->dir_b = 0;
				tbest->k_b = i;
			}
		}
	i++;
	}
}

t_best	ft_find_best(t_best *tbest, int lenb)
{
	int		i;
	t_best	tmp;

	i = 1;
	tmp = tbest[0];
	while (i < lenb)
	{
		if (tbest[i].k < tmp.k)
			tmp = tbest[i];
		i++;
	}
	return (tmp);
}
