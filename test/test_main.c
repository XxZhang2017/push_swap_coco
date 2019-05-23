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
    // rra(t);
    // ft_print_stack_a(t);
    // printf("\n\n");
    // ft_print_stack_b(t);
    // printf("---------\n");
    // rra(t);
    // ft_print_stack_a(t);
    // printf("\n\n");
    // ft_print_stack_b(t);
    // printf("---------\n");
    // rra(t);
    // ft_print_stack_a(t);
    // printf("\n\n");
    // ft_print_stack_b(t);
    // printf("---------\n");
    rr(t);
    ft_print_stack_a(t);
    printf("\n\n");
    ft_print_stack_b(t);





    //sa, sb, ss:
    // printf("-------\n");
    // ft_print_stack_a(t);
    // printf("\n\n");
    // ft_print_stack_b(t);
    // pb(t);
    // pb(t);

    // printf("-------\n");
    // ft_print_stack_a(t);
    // printf("\n\n");
    // ft_print_stack_b(t);
    ss(t);
    printf("-------\n");
    ft_print_stack_a(t);
    printf("\n\n");
    ft_print_stack_b(t);

    ft_print_stack_a(t);
    printf("-------");
    sa(t);
    ft_print_stack_a(t);
    printf("-------");
    sa(t);
    ft_print_stack_a(t);


    //push a, push b;
    // pb(t);
    // pb(t);
    // printf("pb, stack a:\n");
    // ft_print_stack_a(t);
    // printf("pb, stack_b:\n");
    // ft_print_stack_b(t);
   
    // pa(t);
    // pa(t);
    // printf(" -------------\n");
    // printf("pa, stack a:\n");
    // ft_print_stack_a(t);
    // printf("pb, stack_b:\n");
    // ft_print_stack_b(t);
    return (0);
}
