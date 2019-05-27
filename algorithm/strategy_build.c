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

static t_optimizer  *copy_opm(t_optimizer *candi)
{
    t_optimizer *opm;

    opm = init_opm(candi->operand, candi->operand_index);
    cal_opm_attr(opm, candi->upa, candi->upb, candi->downa, candi->downb);
    return opm;
}

t_optimizer *getOptimizer(t_stack *st)
{
    int loop_index;
    t_optimizer *opm;
    t_optimizer *helper;
    t_optimizer *candi;

    loop_index = st->top_b;
    opm = NULL;
    while (loop_index <= st->size - 1)
    {
        candi = init_opm(st->arr_b[loop_index], loop_index);
        //finish getting steps;
        cal_opm_attr(helper, s_upa(st, st->arr_b[loop_index]), s_upb(st, st->arr_b[loop_index]), s_downa(st, st->arr_b[loop_index]), s_downb(st, st->arr_b[loop_index]));
        if (!opm)
            opm = candi;
        else
        {
            if (opm->steps < candi->steps)
            {
                helper = opm;
                opm = copy_opm(candi);
                free(helper);
            }
            // if (opm->steps < candi->steps)
            // {
            //     helper = opm;
            //     opm = candi;
            //     free(helper);
            // }
        }
        free(candi);
        loop_index++;
    }
    return (opm);
}
