#include "../push_swap.h"

int main(int ac, char **av)
{
    t_stack *t;
    t = initstack(&av[1], 3);
    // t->arr_b[0] = 3;
    // t->arr_b[1] = 2;
    // ft_print_stack_a(t);
    pb(t);
    pb(t);
    printf("pb, stack a:\n");
    ft_print_stack_a(t);
    printf("pb, stack_b:\n");
    ft_print_stack_b(t);
   
    pa(t);
    pa(t);
    printf(" -------------\n");
    printf("pa, stack a:\n");
    ft_print_stack_a(t);
    printf("pb, stack_b:\n");
    ft_print_stack_b(t);
    return (0);
}
