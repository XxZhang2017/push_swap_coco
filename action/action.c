/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:59:25 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/23 17:59:27 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_action    *newAction(int acode)
{
    t_action    *reg;

    reg = (t_action *)malloc(sizeof(t_action));
    reg->a_code = acode;
    reg->head = reg;
    reg->next = NULL;
    reg->head->len = 1;
    return (reg);
}

t_action    *appendAction(t_action *act, int acode)
{
    t_action    *newnode;

    if (!act)
        act = newAction(acode);
    else
    {
        newnode = newAction(acode);
        newnode->head = act->head;
        act->head->len++;
        act->next = newnode;
        act = newnode;
    }
    return (act);
}

void    free_action(t_action *act)
{
    t_action    *help;
    while (act)
    {
        help = act->next;
        free(act);
        act = help;
    }
}

