/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:57:24 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 18:59:14 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		parseconmmand(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (0);
	else if (ft_strcmp(line, "sb") == 0)
		return (1);
	else if (ft_strcmp(line, "ss") == 0)
		return (2);
	else if (ft_strcmp(line, "pa") == 0)
		return (3);
	else if (ft_strcmp(line, "pb") == 0)
		return (4);
	else if (ft_strcmp(line, "ra") == 0)
		return (5);
	else if (ft_strcmp(line, "rb") == 0)
		return (6);
	else if (ft_strcmp(line, "rr") == 0)
		return (7);
	else if (ft_strcmp(line, "rra") == 0)
		return (8);
	else if (ft_strcmp(line, "rrb") == 0)
		return (9);
	else if (ft_strcmp(line, "rrr") == 0)
		return (10);
	else
		return (-1);
}

static t_action	*buildaction(char *ope)
{
	t_action	*act;
	int			acode;

	if ((acode = parseconmmand(ope)) == -1)
	{
		write(1, "COMMAND ERROR\n", 14);
		exit(0);
	}
	act = getinstruction(acode, 1);
	if (!act)
		exit(1);
	return (act);
}

static t_action *token(char *str, char sep, int *pos)
{
    int index_pos;
    int index_str;
    char    word[10];

    index_pos = *pos;
    index_str = 0;
    while (str[index_pos] && str[index_pos] != sep) 
    {
        word[index_str] = str[index_pos];
        index_str++;
        index_pos++;
    }
    word[index_str] = '\0';
    if (!str[index_pos])
        *pos = index_pos;
    else
        *pos = index_pos + 1;
    if (parseconmmand(&word[0]) == -1)
    {
        
        write(1, "COMMAND ERROR\n", 14);
        exit(0);
    }
    return (buildaction(&word[0]));
}

static void     doaction(char *s, char c, t_stack *st)
{
	t_action    *act;
	int			i;

	i = 0;
	while (s[i])
	{
		act = token(s, c, &i);
        exeaction(act, st);
	}
}

static int		readaction(int fd, t_stack *st)
{
    char        buf[BUFF_SIZE];
    ssize_t		reby;

    reby = -1;
    while (1)
    {
        if ((reby = read(fd, buf, BUFF_SIZE)) != -1)
        {
            if (reby == 0)
                return (isfinished(st));
            else
            {
                buf[reby] = '\0';
                doaction(&buf[0], '\n', st);
            }
        }
        else
        {
            write(1, "READ ERROR\n", 11);
            exit(1);
        }
    }
    
    return (isfinished(st));
}

void		ft_print_stack_b(t_stack *st)
{
	int elem;
	int top;

	top = st->top_b;
	elem = st->num_b;

	if (!elem)
	{
		ft_putstr("empty\n");
		return;
	}	
	while (elem)
	{
		ft_putstr(ft_itoa(st->arr_b[top]));
		write(1, "\n", 1);
		top++;
		elem--;
	}
}

void		ft_print_stack_a(t_stack *st)
{
	int elem;
	int top;

	top = st->top_a;
	elem = st->num_a;

	if (!elem)
	{
		ft_putstr("empty\n");
		return;
	}	
	while (elem)
	{
		ft_putstr(ft_itoa(st->arr_a[top]));
		write(1, "\n", 1);
		top++;
		elem--;
	}
}

int				main(int ac, char **av)
{
	t_stack		*st;
	int			reg;

	if (ac == 1)
		return (0);
	st = validate(ac, av);
	st->_flag = 0;
	if (!st)
		exit(1);
	reg = readaction(0, st);
	if (reg == 1)
		write(1, "OK\n", 3);
	if (reg == 0)
		write(1, "KO\n", 3);
	return (0);
}