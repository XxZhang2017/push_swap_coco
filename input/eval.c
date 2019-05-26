/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 08:50:23 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/23 08:50:26 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

static int  parse_two_op(int ac, char **av, int *f)
{
    if (!ft_strcmp(av[1], "-c") || !ft_strcmp(av[1], "-v"))
    {
        if ((!ft_strcmp(av[1], "-c") && !ft_strcmp(av[0], "-v"))
        || (!ft_strcmp(av[1], "-v") && !ft_strcmp(av[0], "-c")))
        {
            f[0] = 1;
            f[1] = 1;
            return (2);
        }    
    }
    return (-1);
}

static  int     pos_cal(int ac, char **av, int *f)
{
    if (ac >= 2 && parse_two_op(ac, av, f) == 2)
    {
        return (2);
    }
        
    else if (ac >= 1 && (!ft_strcmp(av[0], "-c") || !ft_strcmp(av[0], "-v")))
    {
        if (!ft_strcmp(av[0], "-c"))
            f[1] = 1;
        if (!ft_strcmp(av[0], "-v"))
            f[0] = 1;
        return (1);
    }    
    else
        return (0);    
}

static int  eval_number(char *input)
{
    int i;
    long value;
    
    i = 0;
    value = 0;
    while (input[i])
    {
        if (!ft_isdigit(input[i]))
            return (0);
        else
        {
            value *= 10;
            value += input[i] - '0';
            if (value > 2147483647)
                return (0);
        }
        i++;
    }
    return (1);
}

static  char **get_arglist(int ac, char **av)
{
    char    **arglist;
    int     i;

    // printf("first ele in list is %s\n", av[0]);
    // printf("num of ele %d\n", ac);
    i = 0;
    if (ac == 0)
        return (NULL);
    arglist = (char **)malloc(sizeof(char *) * (ac + 1));
    if (!arglist)
        return (NULL);
    arglist[ac + 1] = NULL;
    while (i < ac)
    {
        if (eval_number(av[i]))
            arglist[i] = ft_strdup(av[i]);
        else
        {
            printf("num input error\n");
            return (NULL);
        }
        i++;
    }
    return (arglist);
}

static int  isdupnum(char   **num, int n)
{
    int i, j;
    char *tmp;

    i = 0;
    while (i < n)
    {
        tmp = num[i];
        j = 0;
        while (j < n)
        {
            // printf("%s, %s\n", num[i], num[j]);
            if (j != i && !ft_strcmp(num[i], num[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

char     **eval(int ac, char **av, int *size, int *flag)
{
    int num_op;
    int num;
    char    **reg;

    num = ac - 1;
    num_op = pos_cal(num, &av[1], flag);

    num -=num_op;
    if (isdupnum(&av[num_op + 1], num))
    {
        printf("duplicate error\n");
        return (NULL);
    }
    *size = num;
    reg = get_arglist(num, &av[num_op + 1]);
    if (!reg)
        return (NULL);
    return (reg);
}

t_stack *validate(int ac, char **av)
{
    char    **arglist;
    int     size;
    int     flag[2];
    t_stack *st;

    flag[0] = 0;
    flag[1] = 0;
    if (ac == 1)
        return (NULL);
    if ((arglist = eval(ac, av, &size, &flag[0])) == NULL)
        return (NULL);
    else
    {
        st = initstack(arglist, size);
        if (!st)
            return (NULL);
        set_stack_info(st, flag);
        free_arglist(arglist, size);
        // printf("stack size %d\n", size);
        // ft_print_stack_a(st);
        // printf("printf list\n");
        // ft_print_arglist(arglist, 5);
        // printf("end\n");
        return (st);
    }
}
