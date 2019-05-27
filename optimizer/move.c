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
    int comm;

    if (!opm)
        return (NULL);
    // printf("action : %d\n", opm->opm_code);
    act = NULL;
    comm = (opm->upa <= opm->upb) ? opm->upa : opm->upb;
    act = getInstruction(7, comm);
    if (opm->upa > opm->upb)
        act = moreAction(act, 5, opm->upa - comm);
    else
        act = moreAction(act, 6, opm->upb - comm);
    act = moreAction(act, 3, 1);
    return (act);
}

//opm_code: 1
t_action    *upa_downb(t_optimizer *opm)
{
    t_action    *act;

    if (!opm)
        return (NULL);
    // printf("action : %d\n", opm->opm_code);
    act = NULL;
    //ra, rrb
    act = getInstruction(5, opm->upa);
    act = moreAction(act, 9, opm->downb);
    act = moreAction(act, 3, 1);
    return (act);
}

//opm_code: 2
t_action    *downa_downb(t_optimizer *opm)
{
    t_action    *act;
    int comm;

    if (!opm)
        return (NULL);
    // printf("action : %d\n", opm->opm_code);
    act = NULL;
    comm = (opm->downa < opm->downb) ? opm->downa : opm->downb;
    act = getInstruction(10, comm);
    if (opm->downa > opm->downb)
        act = moreAction(act, 8, opm->downa - comm);
    else
        act = moreAction(act, 9, opm->downb - comm);
    act = moreAction(act, 3, 1);
    return (act);
}

//opm_code: 3
t_action    *downa_upb(t_optimizer *opm)
{
    t_action    *act;

    if (!opm)
        return (NULL);
    // printf("action : %d\n", opm->opm_code);
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
    int reg, smallest;
    int i;
 
    s[0] = ua > ub ? ua : ub;
    s[1] = ua + db;
    s[2] = da > db ? da : db;
    s[3] = ub + da;
    smallest = s[0];
    reg = 0;
    i = 0;
    while (i < 4)
    {
        if (s[i] < smallest)
        {
            // printf("the scores change from %d to %d\n", reg, i);
            reg = i;
            smallest = s[i];
        }
        i++;
    }
    // printf("scores are:\n");
    // printf("ua: %d, ub: %d, da: %d, db: %d\n", ua, ub, da, db);
    // printf("get opt code %d\n", reg);
    return (reg);
}