#include "../push_swap.h"

int main(int ac, char **av)
{
    char    **arglist;
    int     size;
    int     flag[2];
    t_stack *st;
    
    flag[0] = 0;
    flag[1] = 0;
    if (ac == 1)
        return (0);
    if ((arglist = eval(ac, av, &size, &flag[0])) == NULL)
        return (0);
    else
    {
        st = initstack(arglist, size);
        if (!st)
            return 0;
        set_stack_info(st, flag);
        printf("stack size %d\n", size);
        ft_print_stack_a(st);
        // printf("printf list\n");
        // ft_print_arglist(arglist, 5);
        // printf("end\n");
        return (0);
    }
}