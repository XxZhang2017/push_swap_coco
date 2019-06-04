/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:39:57 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 09:45:36 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	assign(char **arglist, t_stack *st)
{
	int		i;

	i = st->size - 1;
	while (i >= 0)
	{
		st->arr_a[i] = ft_atoi(arglist[i]);
		i--;
	}
	st->top_a = 0;
	st->num_a = st->size;
}

t_stack		*initstack(char **arglist, int size)
{
	t_stack	*reg;

	reg = (t_stack *)malloc(sizeof(t_stack));
	reg->arr_a = (int *)malloc(sizeof(int) * size);
	reg->arr_b = (int *)malloc(sizeof(int) * size);
	reg->size = size;
	reg->num_b = 0;
	assign(arglist, reg);
	reg->top_b = -1;
	reg->op = 0;
	reg->_flag = 1;
	return (reg);
}

void		set_stack_info(t_stack *st, int flag[2])
{
	st->op = flag[0] + (flag[1] << 1);
}

void		free_stack(t_stack *st)
{
	free(st->arr_a);
	free(st->arr_b);
	free(st);
}
