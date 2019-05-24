#include "../push_swap.h"

int main(int ac, char **av)
{
    t_stack *st;
    int i;
    
    st = validate(ac, av);
    if (!st)
        return (0);

    i = 0;
    while (i < st->size)
    {
        rra(st);
        pb(st);
        rrr(st);
        store_stack_info(st);
        printf("stack a   --------\n");
        ft_print_stack_a(st);
        printf("stack b   --------\n");
        ft_print_stack_b(st);
        ft_print_stack_info(st);
        i++;
    }
   
    free_stack(st);
    sleep(10);
    // i = 0;
    // while (i < st->size)
    // {
    //     rrb(st);
    //     // pb(st);
    //     store_stack_info(st);
    //     printf("stack a   --------\n");
    //     ft_print_stack_a(st);
    //     printf("stack b   --------\n");
    //     ft_print_stack_b(st);
    //     ft_print_stack_info(st);
    //     i++;
    // }


    // i = 0;
    // while (i < st->size)
    // {
    //     ra(st);
  
    //     printf("stack a   --------\n");
    //     ft_print_stack_a(st);
    //     store_stack_info(st);
    //     ft_print_stack_info(st);
    //     i++;
    // }
    // i = 0;
    // while (i < st->size)
    // {
    //     pb(st);
    //     sa(st);
    //     printf("stack a   --------\n");
    //     ft_print_stack_a(st);
    //     printf("stack b   --------\n");
    //     ft_print_stack_b(st);
    //     printf("\n");
    //     store_stack_info(st);
    //     ft_print_stack_info(st);
    //     i++;
    // }
    // i = 0;
    // while (i < st->size)
    // {
    //     ra(st);
  
    //     printf("stack a   --------\n");
    //     ft_print_stack_a(st);
    //     store_stack_info(st);
    //     ft_print_stack_info(st);
   
    //     i++;
    // }

    // i = 0;
    // while (i < st->size)
    // {
    //     pa(st);
    //     sb(st);
    //     printf("stack a   --------\n");
    //     ft_print_stack_a(st);
    //     printf("stack b   --------\n");
    //     ft_print_stack_b(st);
    //     printf("\n");
    //     store_stack_info(st);
    //     ft_print_stack_info(st);
    //     i++;
    // }
    
    return (0);
}