/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:23:20 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/24 22:23:21 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_action    *to_topb(t_stack *st, int index)
{
    t_action    *act;
    int steps;

    if ((index - st->top_b) > (st->num_b / 2))
    {
        steps = st->num_b - (index - st->top_b);
        act = getInstruction(9, steps); //"rrb"
    }
    else
    {
        steps = index - st->top_b;
        act = getInstruction(6, steps);  //"rb"
    }
    return (act);
}