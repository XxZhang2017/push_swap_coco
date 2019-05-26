/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 00:33:13 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/26 00:33:14 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//opm_code: 0
t_action    *upa_upb(t_optimizer *opm)
{
    t_action    *act;
    int diff;

    if (!opm)
        return (NULL);
    printf("action : %d\n", opm->opm_code);
    act = NULL;
    diff = (opm->upa > opm->upb) ? 
    (opm->upa - opm->upb) : (opm->upb - opm->upa);
    act = getInstruction(7, diff);
    if (opm->upa > opm->upb)
        act = moreAction(act, 5, opm->upa - diff);
    else
        act = moreAction(act, 6, opm->upb - diff);
    act = moreAction(act, 3, 1);
    return (act);
}

//opm_code: 1
t_action    *downa_downb(t_optimizer *opm)
{
    t_action    *act;
    int diff;

    if (!opm)
        return (NULL);
    printf("action : %d\n", opm->opm_code);
    act = NULL;
    diff = (opm->downa > opm->downb) ? 
    (opm->downa - opm->downb) : (opm->downb - opm->downa);
    act = getInstruction(10, diff);
    if (opm->downa > opm->downb)
        act = moreAction(act, 8, opm->downa - diff);
    else
        act = moreAction(act, 9, opm->downb - diff);
    act = moreAction(act, 3, 1);
    return (act);
}

//opm_code: 2
t_action    *upa_downb(t_optimizer *opm)
{
    t_action    *act;

    if (!opm)
        return (NULL);
    printf("action : %d\n", opm->opm_code);
    act = NULL;
    //ra, rrb
    act = getInstruction(5, opm->upa);
    act = moreAction(act, 9, opm->downb);
    act = moreAction(act, 3, 1);
    return (act);
}

//opm_code: 3
t_action    *downa_upb(t_optimizer *opm)
{
    t_action    *act;

    if (!opm)
        return (NULL);
    printf("action : %d\n", opm->opm_code);
    act = NULL;
    //rb, rra
    act = getInstruction(8, opm->downa);
    act = moreAction(act, 6, opm->upb);
    act = moreAction(act, 3, 1);
    return (act);
}

int     get_opmcode(int ua, int ub, int da, int db)
{
    int s[4];
    int reg;
    int i;

    s[0] = ua > ub ? ua : ub;
    s[1] = ua + db;
    s[2] = da > db ? da : db;
    s[3] = ub + da;
    reg = s[0];
    i = 0;
    while (i < 4)
    {
        if (reg < s[i])
            reg = s[i];
        i++;
    }
    return (reg);
}