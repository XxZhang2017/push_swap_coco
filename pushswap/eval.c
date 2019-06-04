/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:10:54 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 09:33:52 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		eval_number(char *input)
{
	int			i;
	long		value;

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

char			**get_arglist(int ac, char **av)
{
	char		**arglist;
	int			i;

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
			write(1, "INPUT ERROR\n", 12);
			exit(0);
		}
		i++;
	}
	return (arglist);
}

t_stack			*validate(int ac, char **av)
{
	char		**arglist;
	int			size;
	int			flag[2];
	t_stack		*st;

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
		return (st);
	}
}
