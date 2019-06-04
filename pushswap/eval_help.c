/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:26:32 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 09:36:03 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		parse_two_op(char **av, int *f)
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

static	int		pos_cal(int ac, char **av, int *f)
{
	if (ac >= 2 && parse_two_op(av, f) == 2)
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

static int		isdupnum(char **num, int n)
{
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	while (i < n)
	{
		tmp = num[i];
		j = 0;
		while (j < n)
		{
			if (j != i && !ft_strcmp(num[i], num[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	set_len(char **dum)
{
	int	count;

	count = 0;
	while (dum[count])
		count++;
	return (count);
}

char			**eval(int ac, char **av, int *size, int *flag)
{
	int			num_op;
	int			num;
	char		**reg;
	char		**dummy;
	int			f;

	num = ac - 1;
	f = 0;
	if (num == 1)
	{
		dummy = ft_strsplit(av[1], ' ');
		num = set_len(dummy);
		f = 1;
	}	
	else
		dummy = &av[1];
	num_op = pos_cal(num, dummy, flag);
	num -= num_op;
	if (isdupnum(&dummy[num_op], num))
	{
		write(1, "DUPLICATE ERROR\n", 16);
		exit(0);
	}
	*size = num;
	reg = get_arglist(num, &dummy[num_op]);
	if (f)
		free_arglist(dummy, num);
	if (!reg)
		return (NULL);
	return (reg);
}