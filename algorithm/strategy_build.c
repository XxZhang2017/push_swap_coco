/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:59:20 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/24 22:59:23 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     exeStrategy(t_stack *st)
{
    t_action    *act_a;
    t_action    *act_b;
    t_action    *candi;
    t_action    *newact;
    int     loop_start;

    if (st->num_b == 0)
        return (0);
    else
    {
        newact = NULL;
        store_stack_info(st);
        loop_start = st->top_b;
        while (loop_start < st->size)
        {
            act_a = moveToA(st, st->arr_b[loop_start]);
            printf("move to a finish\n");
            act_b = to_topb(st, loop_start);
            printf("to top b finished\n");
            candi = comb_action(act_a, act_b);
            printf("comb finished\n");
            if (!newact)
                newact = candi;
            else
            {
                newact = (newact->len > candi->len) ? newact : candi;
                free_action(candi);
            }
            loop_start++;
        }
        exeAction(newact, st);
        printf("finish exe\n");
        return exeStrategy(st);
    }
}
