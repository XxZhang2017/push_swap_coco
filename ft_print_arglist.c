#include "push_swap.h"

void    ft_print_arglist(char **av, int num)
{
    int i;
    i = 0;
    while (i < num)
    {
        printf("%s\n", av[i]);
        i++;
    }
}