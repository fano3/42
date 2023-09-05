# include "push_swap.h"

void ft_rra(t_stack *tstack, int flag)
{
    int tmp;
    int tmp2;
	int i;

    i = 0;
    tmp = tstack->position[i];
    i++;

    
    while (i < tstack->lena)
    {
     tmp2 = tstack->position[i];
     tstack->position[i] = tmp;
     tmp = tmp2;
     i++;
    }
    tstack->position[0] = tmp;
	if (flag == 0)
		ft_printf("rra\n");
}

void ft_rrb(t_stack *tstack, int flag)
{
    int tmp;
    int tmp2;
	int i;

    i = 0;
    tmp = tstack->b[i];
    i++;

    
    while (i < tstack->lenb)
    {
     tmp2 = tstack->b[i];
     tstack->b[i] = tmp;
     tmp = tmp2;
     i++;
    }
    tstack->b[0] = tmp;
	if (flag == 0)
		ft_printf("rrb\n");
}

void ft_pa(t_stack *tstack, int flag)
{
	int c;
	int i;

	i = 0;
	c = tstack->b[0];
	ft_rb(tstack, 1);
	tstack->lenb -= 1;
	tstack->lena += 1;
	ft_rra(tstack, 1);
	tstack->position[0] = c;
	if (flag == 0)
		ft_printf("pa\n");


}

void ft_rr(t_stack *tstack, int flag)
{
	ft_ra(tstack, 1);
	ft_rb(tstack, 1);
	if (flag == 0)
		ft_printf("rr\n");
}

void ft_pb(t_stack *tstack, int flag)
{
	int c;
	int i;

	i = 0;
	c = tstack->position[0];
	ft_ra(tstack, 1);
	tstack->lena -= 1;
	tstack->lenb += 1;
	ft_rrb(tstack, 1);
	tstack->b[0] = c;
	if (flag == 0)
		ft_printf("pb\n");



}
void ft_rrr(t_stack *tstack, int flag)
{
	ft_rra(tstack, 1);
	ft_rrb(tstack, 1);
	if (flag == 0)
		ft_printf("rrr\n");

}