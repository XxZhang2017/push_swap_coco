/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:59:31 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/23 17:59:32 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_action    *getInstruction(int acode, int num)
{
    int i;
    t_action    *act;

    act = newAction(acode);
    num--;
    i = 0;
    while (i < num)
    {
        act = appendAction(act, acode);
        i++;
    }
    return (act);
}

t_action    *moreAction(t_action *act, int acode, int num)
{
    int i;
    i = 0;
    if (!act)
        act = getInstruction(acode, num);
    else
    {
        while (i < num)
        {
            
            act = appendAction(act, acode);
            i++;
        }
    }
    return (act);
}

void    exeAction(t_action *act, t_stack *st)
{
    void    (*instr[11])(t_stack *);
    t_action    *helper;
    int     i;

    i = act->head->len;
    instr[0] = &sa;
    instr[1] = &sb;
    instr[2] = &ss;
    instr[3] = &pa;
    instr[4] = &pb;
    instr[5] = &ra;
    instr[6] = &rb;
    instr[7] = &rr;
    instr[8] = &rra;
    instr[9] = &rrb;
    instr[10] = &rrr;
    helper = act->head;
    while (helper)
    {
        instr[helper->a_code](st);
        helper = helper->next;
    }
    free_action(act->head);
}