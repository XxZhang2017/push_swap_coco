/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genoptimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 00:33:38 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/26 00:33:41 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_optimizer *init_opm(int operand, int index)
{
    t_optimizer *opm;

    opm = (t_optimizer *)malloc(sizeof(t_optimizer));
    opm->operand = operand;
    opm->operand_index = index;
    opm->upa = -1;
    opm->upb = -1;
    opm->downa = -1;
    opm->downb = 1;
    opm->opm_code = -1;
    
    return (opm);
}

int  get_steps(t_optimizer *opm)
{
    if (opm->opm_code == 0)
        return (opm->upa > opm->upb ? opm->upa : opm->upb);
    else if (opm->opm_code == 1)
        return (opm->upa + opm->downb);
    else if (opm->opm_code == 2)
        return (opm->downa > opm->downb ? opm->downa : opm->downb);
    else if (opm->opm_code == 3)
        return (opm->downa + opm->upb);
    return (0);
}

void    cal_opm_attr(t_optimizer *opm, int ua, int ub, int da, int db)
{
    opm->upa = ua;
    opm->upb = ub;
    opm->downa = da;
    opm->downb = db;
    opm->opm_code = get_opmcode(ua, ub, da, db);
    opm->steps = get_steps(opm);
    // printf("\n");
    // printf("ua : %d, ub : %d, da : %d, db : %d\n", ua, ub, da, db);
    // printf("\n");
}