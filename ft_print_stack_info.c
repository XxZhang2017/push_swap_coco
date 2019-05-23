#include "push_swap.h"

void    ft_print_stack_info(t_stack *st)
{
    printf("stack info ------------------ \n");
    printf("stack a: min:  %d,   min index:  %d\n", st->minv_a, st->mini_a);
    printf("stack a: min:  %d,   min index:  %d\n", st->minv_a, st->mini_a);
    printf("----------------------------- \n");
    printf("stack b: min:  %d,   min index:  %d\n", st->minv_b, st->mini_b);
    printf("stack b: min:  %d,   min index:  %d\n", st->minv_b, st->mini_b);
}