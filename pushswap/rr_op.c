/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:10:36 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 10:14:34 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *st)
{
	int	index;
	int	count;
	int	buf;

	count = 0;
	if (st->num_a > 0)
	{
		ft_strcpy(st->print, "rra");
		index = st->size - 1;
		buf = st->arr_a[(st->size) - 1];
		while (count < st->num_a - 1)
		{
			st->arr_a[index] = st->arr_a[index - 1];
			index--;
			count++;
		}
		st->arr_a[st->top_a] = buf;
		if (st->_flag)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *st)
{
	int	index;
	int	count;
	int	buf;

	count = 0;
	if (st->num_b > 0)
	{
		ft_strcpy(st->print, "rrb");
		index = st->size - 1;
		buf = st->arr_b[(st->size) - 1];
		while (count < st->num_b - 1)
		{
			st->arr_b[index] = st->arr_b[index - 1];
			index--;
			count++;
		}
		st->arr_b[st->top_b] = buf;
		if (st->_flag)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *st)
{
	int	buf;

	if (st->num_a > 0 && st->num_b > 0)
	{
		ft_strcpy(st->print, "rrr");
		buf = st->_flag;
		st->_flag = 0;
		rra(st);
		rrb(st);
		st->_flag = buf;
		if (st->_flag)
			write(1, "rrr\n", 4);
	}
}
