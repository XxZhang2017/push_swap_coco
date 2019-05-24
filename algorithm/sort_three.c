/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:57:34 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/23 16:57:35 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//apply to a:

static t_action *action_three(t_stack *st)
{
    t_action    *act;
    store_stack_info(st);
    if (st->mini_a == st->top_a && st->maxi_a == st->size - 1)
        return NULL;//correct order;
    else if (st->mini_a == st->size - 1 && st->maxi_a == st->top_a)
        return NULL; //reverse order;
    else if (st->mini_a == st->top_a && st->maxi_a == st->size - 2)
    {
        act = getInstruction(0, 1);
        return moreAction(act, 5, 1);//correct order;
    }
    else if (st->mini_a == st->size - 1 && st->maxi_a == st->size - 2)
        return getInstruction(8, 1);//correct order;

    else if (st->mini_a == st->size - 2 && st->maxi_a == st->top_a)
        return getInstruction(5, 1); //correct order;
    else if (st->mini_a == st->size - 2 && st->maxi_a == st->size - 1)
        return getInstruction(0, 1);//correct order;
    else
        return (NULL);
}

//finish: 0;
//a is sorted, b is not empty: 1;
//a is reverse order, b is empty: 2;
//a is reverse order, b is not empty: 3;
//error:
int    sort_three(t_stack *st)
{
    t_action    *act;
    int     reg;

    act = action_three(st);
    // store_stack_info(st);
    // ft_print_stack_info(st);
    // printf("\n");
    if (act == NULL && st->mini_a == st->top_a && st->top_b == -1)
        return (0);
    else if (act == NULL && st->mini_a == st->size - 1 && st->top_b == -1)
        return (2);
    else if (act == NULL && st->mini_a == st->size - 1 && st->top_b != -1)
        return (3);
    exeAction(act, st);
    store_stack_info(st);
    printf("after exe: \n");
    ft_print_stack_info(st);
    printf("\n");
    if (st->mini_a == st->top_a && st->top_b == -1)
        return (0);
    else if (st->mini_a == st->top_a && st->top_b != -1)
        return (1);
    // else if (st->mini_a == st->size - 1 && st->top_b != -1)
    //     return (3);
    else
        return (-1);
}