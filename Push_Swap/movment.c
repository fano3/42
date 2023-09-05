#include "push_swap.h"


void ft_sa (t_stack *tstack, int flag)
{
    int tmp;

	tmp = tstack->position[0];
	tstack->position[0] = tstack->position[1];
	tstack->position[1] = tmp;
	if (flag == 0)
		ft_printf("sa\n");
}

void ft_sb (t_stack *tstack, int flag)
{
    int tmp;
	tmp = tstack->b[0];
	tstack->b[0] = tstack->b[1];
	tstack->b[1] = tmp;
	if (flag == 0)
		ft_printf("sb\n");
}

void ft_ra (t_stack *tstack, int flag)
{
    int tmp;
    int tmp2;
	int i;

    i = tstack->lena - 1;
    tmp = tstack->position[i];
    tstack->position[i] = tstack->position[0];
    i--;

    
    while (i >= 0)
    {
     tmp2 = tstack->position[i];
     tstack->position[i] = tmp;
     tmp = tmp2;
     i--;
    }
	if (flag == 0)
		ft_printf("ra\n");

}
void ft_rb (t_stack *tstack, int flag)
{
    int tmp;
    int tmp2;
	int i;

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

