/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 21:58:26 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/25 21:58:29 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_action    *getbestfromB(t_stack *st)
{
    t_action    *act;
    t_action    *candi;
    t_action    *help;
    int start;

    start = st->top_b;
    act = NULL;
    while (start < st->size)
    {
        candi = moveToA(st, start);
        if (!act)
            act = candi;
        else
        {
            if (candi->head->len < act->head->len)
            {
                help = act;
                act = candi;
                free(act);
            }
        }
        start++;
    }
    return (act);
}