/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:19:35 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 10:21:32 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *st)
{
	if (st->num_b == 0)
		return ;
	ft_strcpy(st->print, "pa");
	st->buf_a = st->arr_b[st->top_b];
	if (st->num_a == 0)
	{
		st->top_a = st->size - 1;
		st->arr_a[st->top_a] = st->buf_a;
		st->top_b++;
		if (st->top_b == st->size)
			st->top_b = -1;
	}
	else
	{
		(st->top_a)--;
		st->arr_a[st->top_a] = st->buf_a;
		(st->top_b)++;
		if (st->top_b == st->size)
			st->top_b = -1;
	}
	(st->num_b)--;
	(st->num_a)++;
	if (st->_flag)
		write(1, "pa\n", 3);
}

void	pb(t_stack *st)
{
	if (st->num_a == 0)
		return ;
	ft_strcpy(st->print, "pb");
	st->buf_b = st->arr_a[st->top_a];
	if (st->num_b == 0)
	{
		st->top_b = st->size - 1;
		st->arr_b[st->top_b] = st->buf_b;
		st->top_a++;
		if (st->top_a == st->size)
			st->top_a = -1;
	}
	else
	{
		(st->top_b)--;
		st->arr_b[st->top_b] = st->buf_b;
		(st->top_a)++;
		if (st->top_a == st->size)
			st->top_a = -1;
	}
	(st->num_a)--;
	(st->num_b)++;
	if (st->_flag)
		write(1, "pb\n", 3);
}
