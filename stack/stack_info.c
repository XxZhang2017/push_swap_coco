/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:56:34 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/23 15:56:35 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

static void store_info_a(t_stack *st)
{
    int index_bound, i;

    index_bound = st->size;
    
    st->mini_a = -1;
    st->minv_a = 2147483647;
    st->maxi_a = -1;
    st->maxv_a = -2147483648;  
    i = st->top_a;
    if (i == -1)
        return ;
    while (i < index_bound)
    {
        if (st->arr_a[i] < st->minv_a)
        {
            st->minv_a = st->arr_a[i];
            st->mini_a = i;     
        }
        if (st->arr_a[i] > st->maxv_a)
        {
            st->maxv_a = st->arr_a[i];
            st->maxi_a = i;
        }
        i++;
    }  
    
}

static void store_info_b(t_stack *st)
{
    int index_bound, i;

    index_bound = st->size;
    st->mini_b = -1;
    st->minv_b = 2147483647;
    st->maxi_b = -1;
    st->maxv_b = -2147483648;
    i = st->top_b;
    if (i == -1)
        return ;
    while (i < index_bound)
    {
        if (st->arr_b[i] < st->minv_b)
        {
            st->minv_b = st->arr_b[i];
            st->mini_b = i;
        }
        if (st->arr_b[i] > st->maxv_b)
        {
            st->maxv_b = st->arr_b[i];
            st->maxi_b = i;
        }
        i++;
    }
}

void    store_stack_info(t_stack *st)
{
    store_info_a(st);
    store_info_b(st);
}