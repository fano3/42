/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:10:44 by mepifano          #+#    #+#             */
/*   Updated: 2023/03/08 12:10:44 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *tstack, int flag)
{
	int	tmp;

	tmp = tstack->pos[0];
	tstack->pos[0] = tstack->pos[1];
	tstack->pos[1] = tmp;
	if (flag == 0)
		ft_printf("sa\n");
}

void	ft_sb(t_stack *tstack, int flag)
{
	int	tmp;

	tmp = tstack->b[0];
	tstack->b[0] = tstack->b[1];
	tstack->b[1] = tmp;
	if (flag == 0)
		ft_printf("sb\n");
}

void	ft_ra(t_stack *tstack, int flag)
{
	int	tmp;
	int	tmp2;
	int	i;

	i = tstack->lena - 1;
	tmp = tstack->pos[i];
	tstack->pos[i] = tstack->pos[0];
	i--;
	while (i >= 0)
	{
		tmp2 = tstack->pos[i];
		tstack->pos[i] = tmp;
		tmp = tmp2;
		i--;
	}
	if (flag == 0)
		ft_printf("ra\n");
}

void	ft_rb(t_stack *tstack, int flag)
{
	int	tmp;
	int	tmp2;
	int	i;

	i = tstack->lenb - 1;
	tmp = tstack->b[i];
	tstack->b[i] = tstack->b[0];
	i--;
	while (i >= 0)
	{
		tmp2 = tstack->b[i];
		tstack->b[i] = tmp;
		tmp = tmp2;
		i--;
	}
	if (flag == 0)
		ft_printf("rb\n");
}

void	ft_rr(t_stack *tstack, int flag)
{
	ft_ra(tstack, 1);
	ft_rb(tstack, 1);
	if (flag == 0)
		ft_printf("rr\n");
}
