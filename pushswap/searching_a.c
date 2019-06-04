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