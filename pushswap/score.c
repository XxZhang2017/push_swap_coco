/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:02:15 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 10:02:43 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		s_upa(t_stack *st, int num)
{
	int	pos;
	int	steps;

	pos = search_pos_a(st, num);
	if (pos == -1)
	{
		write(1, "searching a pos error\n", 16);
		exit(1);
	}
	if (pos == st->top_a - 1)
		steps = 0;
	else
		steps = pos - st->top_a + 1;
	if (steps < 0)
		steps = 0;
	return (steps);
}

int		s_downa(t_stack *st, int num)
{
	int	pos;
	int	steps;

	pos = search_pos_a(st, num);
	if (pos == -1)
	{
		write(1, "searching a down error\n", 16);
		exit(1);
	}
	if (pos == st->top_a - 1)
		return (0);
	steps = st->size - 1 - pos;
	return (steps);
}

int		s_upb(t_stack *st, int num)
{
	int	pos;
	int	steps;

	pos = search_pos_b(st, num);
	if (pos == -1)
	{
		write(1, "searching b up error\n", 16);
		exit(1);
	}
	if (pos == st->top_b)
		steps = 0;
	else
		steps = pos - st->top_b;
	if (steps < 0)
		steps = 0;
	return (steps);
}

int		s_downb(t_stack *st, int num)
{
	int	pos;
	int	steps;

	pos = search_pos_b(st, num);
	if (pos == -1)
	{
		write(1, "searching b down error\n", 16);
		exit(1);
	}
	if (pos == st->top_b - 1)
		return (0);
	steps = st->size - 1 - pos + 1;
	return (steps);
}
