/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 08:49:36 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/24 08:49:40 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char **str_split(char *sq, char *deli)
{
    char    *ptr =strtok(sq, deli);
    char    **reg;
    int     i;

    i = 0;
    reg = (char **)malloc(sizeof(char *) * 5);
    
    while (ptr != NULL)
    {
        reg[i] = strdup(ptr);
        ptr = strtok(NULL, deli);
        i++;
    }
    return (reg);
}

static int  exetest(int ac, char **av)
{
    t_stack *st;
    int reg;

    st = validate(ac, av);
    if (!st)
        return (0);
    if (st->size > 3)
    {
        pb(st);
        pb(st);
    }
    reg = sort_three(st);

    printf("after exe:\n");
    printf("stack a   --------\n");
    ft_print_stack_a(st);
    printf("stack b   --------\n");
    ft_print_stack_b(st);


    free_stack(st);
    return (reg);
}
static void testcombine3()
{
    char    p[][8] = {"n 1 2 3",
                    "n 2 1 3",
                    "n 3 2 1",
                    "n 3 1 2",
                    "n 1 3 2",
                    "n 2 3 1"};
    int     i;
    char    **input;
    int     reg;

    i = 0;
    while (i < 6)
    {  
        input = str_split(p[i], " ");
        printf("the arguments are :\n");
        ft_print_arglist(input, 4);
        reg = exetest(4, input);

       
        if (i == 2 && reg == 2)
            printf("%d passed\n", i);
        if (i != 2 && reg == 0)
            printf("case %d passed\n", i);
        free_arglist(input, 4);
        i++;
    }
}

static void testcombine5()
{
    char    p[][12] = {"n 6 4 1 2 3",
                    "n 6 4 2 1 3",
                    "n 6 4 3 2 1",
                    "n 6 4 3 1 2",
                    "n 6 4 1 3 2",
                    "n 6 4 2 3 1"};
    int     i;
    char    **input;
    int     reg;

    i = 0;
    while (i < 6)
    {  
        input = str_split(p[i], " ");
        printf("the arguments are :\n");
        ft_print_arglist(input, 5);
        reg = exetest(6, input);

       
        if (i == 2 && reg == 3)
            printf("%d passed\n", i);
        if (i != 2 && reg == 1)
            printf("case %d passed\n", i);
        free_arglist(input, 6);
        i++;
    }
}

int main(int ac, char **av)
{

    // testcombine3();
    testcombine5();
    return (0);
}
