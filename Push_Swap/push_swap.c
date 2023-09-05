/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:31:18 by mepifano          #+#    #+#             */
/*   Updated: 2023/02/22 15:31:18 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	tstack;

	ft_check_ac(ac);
	ft_check_av(av);
	tstack.a = malloc(sizeof(int) * ac - 1);
	tstack.b = malloc(sizeof(int) * ac - 1);
	tstack.pos = malloc(sizeof(int) * ac - 1);
	tstack.lena = ac - 1;
	tstack.lenb = 0;
	ft_toi(&tstack, av);
	ft_check_doppi(&tstack);
	ft_check_sort(&tstack);
	ft_pos(&tstack);
	if (tstack.pos[0] == 1 || tstack.pos[1] == 2
		|| tstack.pos[2] == 3)
		if ((tstack.pos[2] != 5) && (tstack.pos[0] != 4))
			ft_sa(&tstack, 0);
	ft_lis(&tstack);
	ft_push(&tstack);
	ft_algorithm(&tstack);
	ft_sort(&tstack);
	free(tstack.a);
	free(tstack.b);
	free(tstack.pos);
}

void	ft_afk(t_stack *tstack, int n)
{
	int	c;

	c = tstack->pos[n];
	while (tstack->pos[0] != c)
	{
		if ((tstack->lena / 2) >= n)
			ft_ra(tstack, 0);
		else
			ft_rra(tstack, 0);
	}
	ft_pb(tstack, 0);
}

void	ft_pos(t_stack *tstack)
{
	int	pos;
	int	j;
	int	c;

	j = 0;
	while (j < tstack->lena)
	{
		c = 0;
		pos = 1;
		while (c < tstack->lena)
		{
			if (tstack->a[j] > tstack->a[c])
				pos++;
			c++;
		}
		tstack->pos[j] = pos;
		j++;
	}
}

void	ft_algorithm(t_stack *tstack)
{
	t_best	tmp;

	while (tstack->lenb != 0)
	{
		tmp = ft_count_moves(tstack);
		if (tmp.dir_a == tmp.dir_b)
		{
			while (tstack->pos[0] != tmp.value_a && tstack->b[0] != tmp.value_b)
			{
				if (tmp.dir_a == 0)
					ft_rr(tstack, 0);
				else
					ft_rrr(tstack, 0);
			}
		}
		while (tstack->pos[0] != tmp.value_a && tmp.dir_a == 0)
			ft_ra(tstack, 0);
		while (tstack->pos[0] != tmp.value_a && tmp.dir_a == 1)
			ft_rra(tstack, 0);
		while (tstack->b[0] != tmp.value_b && tmp.dir_b == 0)
			ft_rb(tstack, 0);
		while (tstack->b[0] != tmp.value_b && tmp.dir_b == 1)
			ft_rrb(tstack, 0);
		ft_pa(tstack, 0);
	}
}

void	ft_toi(t_stack *tstack, char **av)
{
	int	i;

	i = 0;
	while (i < tstack->lena)
	{
		tstack->a[i] = ft_atoi(av[i + 1]);
		i++;
	}
}
