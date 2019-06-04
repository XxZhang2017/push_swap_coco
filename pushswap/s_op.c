/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:17:18 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 10:19:10 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *st)
{
	if (st->num_a < 2)
		return ;
	ft_strcpy(st->print, "sa");
	st->buf_a = st->arr_a[st->top_a];
	st->arr_a[st->top_a] = st->arr_a[st->top_a + 1];
	st->arr_a[st->top_a + 1] = st->buf_a;
	if (st->_flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *st)
{
	if (st->num_b < 2)
		return ;
	ft_strcpy(st->print, "sb");
	st->buf_b = st->arr_b[st->top_b];
	st->arr_b[st->top_b] = st->arr_b[st->top_b + 1];
	st->arr_b[st->top_b + 1] = st->buf_b;
	if (st->_flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack *st)
{
	int	buf;

	if (st->num_b < 2 || st->num_a < 2)
		return ;
	buf = st->_flag;
	st->_flag = 0;
	ft_strcpy(st->print, "ss");
	sa(st);
	sb(st);
	st->_flag = buf;
	if (st->_flag)
		write(1, "ss\n", 3);
}
