/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isfiniesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:27:47 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/24 10:27:48 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     isfinished(t_stack *st)
{
    if (st->size == 0 || st->size == 1)
        return (1);
    return (isordered(st) && (st->num_b == 0));
}

int     isordered(t_stack *st)
{
    int i;

    i = st->top_a;
    if (st->num_a == 0 || st->num_a == 1)
        return (1);
    while (i < st->size - 1)
    {
        if (st->arr_a[i + 1] < st->arr_a[i])
        {
            return (0);
        }
        i++;
    }
    return (1);
}
