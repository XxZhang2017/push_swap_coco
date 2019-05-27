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

int  search_min_down_a(t_stack *st, int num)
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

int  search_top_to_max_a(t_stack *st, int num)
{
    int start;

    start = st->top_a;
    while (start <= st->maxi_a)
    {
        if (st->arr_a[start] > num)
        {
            // if (num == 7 || num == 10 || num == 18)
            //     printf("pos is %d\n", start - 1);
            return (start - 1);
        }
            
        start++;
    }
    return (-1);
}

int  search_pos_a(t_stack *st, int num)
{
    int index;

    store_stack_info(st);
    if (num >= st->maxv_a || num <= st->minv_a)
        return st->mini_a - 1;
    else
    {
        if ((index = search_min_down_a(st, num)) == -1)
            return (search_top_to_max_a(st, num));
        else
            return (index);
    }
}

t_action    *moveToA(t_stack *st, int num)
{
    int pos;
    int adj_pos;
    t_action    *act;
    
    pos = search_pos_a(st, num);
    if (pos == -1)
    {
        write(1, "searching error\n", 16);
        exit(1);
    }
    adj_pos = pos - st->top_a + ((pos < st->top_a)? 0 : 1);
    if (adj_pos < 0)
            adj_pos = 0;
    if (adj_pos > (st->num_a / 2))
    {
        adj_pos = st->size - 1 - pos;
        act = getInstruction(8, adj_pos);
    }
    else
        act = getInstruction(5, adj_pos); //"ra"
    return (act);
}