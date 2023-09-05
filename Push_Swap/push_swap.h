/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:52:43 by mepifano          #+#    #+#             */
/*   Updated: 2023/03/08 12:52:43 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	*pos;
	int	lena;
	int	lenb;
	int	*copy;
	int	*lis;
	int	size_lis;
}t_stack;

typedef struct s_best
{
	int	value_b;
	int	value_a;
	int	k_a;
	int	k_b;
	int	k;
	int	dir_a;
	int	dir_b;
}t_best;

void	ft_pos(t_stack *tstack);
void	ft_sa(t_stack *tstack, int flag);
void	ft_sb(t_stack *tstack, int flag);
void	ft_ra(t_stack *tstack, int flag);
void	ft_rb(t_stack *tstack, int flag);
void	ft_rra(t_stack *tstack, int flag);
void	ft_rrb(t_stack *tstack, int flag);
void	ft_rrr(t_stack *tstack, int flag);
void	ft_pb(t_stack *tstack, int flag);
void	ft_pa(t_stack *tstack, int flag);
void	ft_rr(t_stack *tstack, int flag);
int		ft_find_index(int *arr, int nb, int size);
void	ft_lis(t_stack *tstack);
void	ft_increment(int *index, int len);
int		*ft_new_row(int *arr, int size, int nb);
void	ft_overload(int **matrix, int head, int nb);
void	ft_arr_copy(int *arr1, int *arr2, int size);
void	ft_push(t_stack *tstack);
t_best	ft_count_moves(t_stack *tstack);
void	ft_search_value_a(t_stack *tstack, t_best *tbest);
void	ft_search_dir_a(t_best *tbest, t_stack *tstack);
void	ft_search_dir_b(t_best *tbest, t_stack *tstack);
t_best	ft_find_best(t_best *tbest, int lenb);
void	ft_algorithm(t_stack *tstack);
void	ft_sort(t_stack *tstack);
int		ft_max(int *ar, int size, int nb);
void	ft_check_ac(int ac);
void	ft_check_av(char **av);
void	ft_check_doppi(t_stack *tstack);
void	ft_check_sort(t_stack *tstack);
void	ft_afk(t_stack *tstack, int n);
void	ft_toi(t_stack *tstack, char **av);

#endif