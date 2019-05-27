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

int  search_min_down_b(t_stack *st, int num)
{
    int start;

    start = st->mini_b;
    while (start < st->size)
    {
        if (st->arr_b[start] > num)
            return (start - 1);
        start++;
    }
    return (-1);
}

int  search_top_to_max_b(t_stack *st, int num)
{
    int start;

    start = st->top_b;
    while (start <= st->maxi_b)
    {
        if (st->arr_b[start] > num)
        {
            // if (num == 7 || num == 10 || num == 18)
            //     printf("pos is %d\n", start - 1);
            return (start - 1);
        }
        start++;
    }
    return (-1);
}

int  search_pos_b(t_stack *st, int num)
{
    int index;

    store_stack_info(st);
    if (num >= st->maxv_b || num <= st->minv_b)
        return st->mini_b - 1;
    else
    {
        if ((index = search_min_down_b(st, num)) == -1)
            return (search_top_to_max_b(st, num));
        else
            return (index);
    }
}

t_action    *to_topb(t_stack *st, int index)
{
    t_action    *act;
    int steps;

    steps = index - st->top_b;
    if (steps > (st->num_b / 2))
    {
        steps = st->size - index;
        act = getInstruction(9, steps); //"rrb"
    }
    else
    {
        steps = index - st->top_b;
        act = getInstruction(6, steps);  //"rb"
    }
    return (act);
}