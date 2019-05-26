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

static void print_push(t_stack *st, int acode)
{
    if (acode == 3)
    {
        store_stack_info(st);
        ft_print_stack_a(st);
        printf("\n\n");
        ft_print_stack_b(st);
        printf("---------\n");
        printf("will push %d to A \n", st->arr_b[st->top_b]);

    }
       
    // else if (acode == 4)
    //     printf("push %d to B \n", st->arr_a[st->top_a]);
}

t_action    *getInstruction(int acode, int num)
{
    int i;
    t_action    *act;

    if (num == 0)
        return (NULL);
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
    if (!act)
        return ;
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
        // print_push(st, helper->a_code);
        instr[helper->a_code](st);

        helper = helper->next;
    }
    // printf("in exe, before free\n");
    free_action(act->head);
}