/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:55:10 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/24 19:55:12 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int  parseconmmand(char *line)
{
    if (ft_strcmp(line, "sa\n") == 0)
        return (0);
    else if (ft_strcmp(line, "sb\n") == 0)
        return (1);
    else if (ft_strcmp(line, "ss\n") == 0)
        return (2);
    else if (ft_strcmp(line, "pa\n") == 0)
        return (3);
    else if (ft_strcmp(line, "pb\n") == 0)
        return (4);
    else if (ft_strcmp(line, "ra\n") == 0)
        return (5);
    else if (ft_strcmp(line, "rb\n") == 0)
        return (6);
    else if (ft_strcmp(line, "rr\n") == 0)
        return (7);
    else if (ft_strcmp(line, "rra\n") == 0)
        return (8);
    else if (ft_strcmp(line, "rrb\n") == 0)
        return (9);
    else if (ft_strcmp(line, "rrr\n") == 0)
        return (10);
    else
        return (-1);
}

static t_action    *buildAction(char *ope)
{
    t_action    *act;
    int     acode;
    
    if ((acode = parseconmmand(ope)) == -1)
    {
        write(1, "COMMAND ERROR\n",14);
        // free(ope);
        exit(1);
    }
    act = getInstruction(acode, 1);
    if (!act)
        exit(1);
    return (act);
}

int     readAction(int fd, t_stack *st)
{
    char    buf[BUFF_SIZE + 1];
    int     reg;
    ssize_t reby;
    t_action    *act;

    while (1)
    {
        if ((reby = read(0, buf, BUFF_SIZE)) == -1)
        {
            write(1, "error\n", 6);
            exit(1);
        }
        else if (reby == 0)
            break;
        else
        {
            buf[reby] = '\0';
            act = buildAction(&buf[0]);
            exeAction(act, st); 
        }     
    }
    return (isfinished(st));
}

int     main(int ac, char **av)
{
    t_stack *st;
    int reg;

    if (ac == 1)
        return (0);
    st = validate(ac, av);
    st->_flag = 0;
    if (!st)
        exit(1);
    reg = readAction(0, st);
    if (reg == 1)
        write(1, "OK\n", 3);
    if (reg == 0)
        write(1, "KO\n", 3);
    return (0);
}