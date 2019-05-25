#include "../push_swap.h"

int main(int ac, char **av)
{
    t_stack *t;
    t = initstack(&av[1], 5);
    // t->arr_b[0] = 3;
    // t->arr_b[1] = 2;
    // ft_print_stack_a(t)\\

    //rr:
    pb(t);
    pb(t);
    ft_print_stack_a(t);
    printf("\n\n");
    ft_print_stack_b(t);
    printf("---------\n");

    exeStrategy(t);

    ft_print_stack_a(t);
    printf("\n\n");
    ft_print_stack_b(t);
    printf("---------\n");
    return (0);
}