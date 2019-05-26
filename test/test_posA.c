#include "../push_swap.h"

int main(int ac, char **av)
{
    int pos;
    int adj_pos;
    int feed[] = {1, 7, 10, 18, 20};
    int i;
    t_action    *act;
    
    for (i = 0; i < 5; i++)
    {
        t_stack *t;
        t = initstack(&av[1], 5);
        t = validate(ac, av);
        if (!t)
            return (0);
        // pb(t);
        pb(t);
        pb(t);
        t->arr_b[t->top_b] = feed[i];
        act = moveToA(t, feed[i]);
        act = moreAction(act, 3, 1);
        exeAction(act, t);
        
        printf("stack a info --------------\n");
        ft_print_stack_a(t);
        printf("stack b info --------------\n");
        ft_print_stack_b(t);
        printf("\n");
        free_stack(t);
    }
    return (0);
}