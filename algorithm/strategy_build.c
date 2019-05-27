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

t_optimizer *getOptimizer(t_stack *st)
{
    int loop_index;
    t_optimizer *opm;
    t_optimizer *candi;

    loop_index = st->top_b;
    opm = NULL;
    candi = NULL;
    while (loop_index <= st->size - 1)
    {
        candi = init_opm(st->arr_b[loop_index], loop_index);
        //finish getting steps;
        cal_opm_attr(candi, s_upa(st, st->arr_b[loop_index]), s_upb(st, st->arr_b[loop_index]), s_downa(st, st->arr_b[loop_index]), s_downb(st, st->arr_b[loop_index]));
        if (!opm)
            opm = candi;
        else
        {
            if (candi->steps < opm->steps)
            {
                free(opm);
                opm = candi;
                // printf("updat candidate:\n");
                // printf("action on operand: %d at index: %d\n", opm->operand, opm->operand_index);
                // printf("action code is: %d\n", opm->opm_code);
            }
            else
                free(candi);
        }
        loop_index++;
    }
    return (opm);
}
