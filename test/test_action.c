#include "../push_swap.h"

int main(int ac, char **av)
{
    t_stack *st;
    int i;
    t_action    *act;
    
    act = NULL;
    st = validate(ac, av);
    if (!st)
        return (0);
    printf("stack a   --------\n");
    ft_print_stack_a(st);
    printf("stack b   --------\n");
    ft_print_stack_b(st);
    printf("\n\n");
    act = getInstruction(4, 3);
    act = moreAction(act, 5, 2);
    exeAction(act, st);
    printf("stack a   --------\n");
    ft_print_stack_a(st);
    printf("stack b   --------\n");
    ft_print_stack_b(st);
    return (0);
}