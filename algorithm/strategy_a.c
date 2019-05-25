/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:09:54 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/24 21:09:55 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int  search_up(t_stack *st, int num)
{
    int start;

    start = st->top_a;
    while (start <= st->maxi_a)
    {
        if (st->arr_a[start] > num)
            return (start - 1);
        start++;
    }
    return (-1);
}

static int  search_down(t_stack *st, int num)
{
    int start;

    start = st->mini_a;
    while (start < st->size)
    {
        if (st->arr_a[start] > num)
            return (start - 1);
        start++;
    }
    return (-1);
}

static int  search_pos(t_stack *st, int num)
{
    int index;

    // store_stack_info(st);
    if (num >= st->maxv_a || num < st->minv_a)
        return st->mini_a - 1;
    else if (num > st->arr_a[st->size - 1])
        return search_up(st, num);
    else
        return search_down(st, num);
}

t_action    *moveToA(t_stack *st, int num)
{
    int pos;
    int adj_pos;
    t_action    *act;
    
    pos = search_pos(st, num);
    if (pos == -1)
    {
        write(1, "searching error\n", 16);
        exit(1);
    }
    adj_pos = pos - (st->top_a - 1);
    if (adj_pos > (st->num_a + 1 / 2))
    {
        adj_pos = st->num_a + 1 - adj_pos;
        act = getInstruction(8, adj_pos); //"rra"
    }
    else
        act = getInstruction(5, adj_pos); //"ra"
    return (act);
}
