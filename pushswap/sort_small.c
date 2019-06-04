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
    else if (st->mini_a == st->size - 1 && st->maxi_a == st->top_a) //reverse order
    {
        act = getinstruction(5, 1);
        return moreaction(act, 0, 1);
    }
    else if (st->mini_a == st->top_a && st->maxi_a == st->size - 2)
    {
        act = getinstruction(0, 1);
        return moreaction(act, 5, 1);//correct order;
    }
    else if (st->mini_a == st->size - 1 && st->maxi_a == st->size - 2)
        return getinstruction(8, 1);//correct order;

    else if (st->mini_a == st->size - 2 && st->maxi_a == st->top_a)
        return getinstruction(5, 1); //correct order;
    else if (st->mini_a == st->size - 2 && st->maxi_a == st->size - 1)
        return getinstruction(0, 1);//correct order;
    else
        return (NULL);
}

//a is sorted(correct order), b is not empty 1;
//a is sorted(correct order), b is empty 0;
int sort_two(t_stack *st)
{
    t_action    *act;
    int reg;

    store_stack_info(st);
    if (st->mini_a == st->top_a)
        act = NULL;
    else
        act = getinstruction(0, 1);
    if (act)
        exeaction(act, st);
    reg = (st->num_b == 0) ? 0 : 1;
    return reg;
}

//finish: 0;
//a is sorted, b is not empty: 1;
                //delete this case: a is reverse order, b is empty: 2;
                //delete this case: a is reverse order, b is not empty: 3;
//error:
int    sort_three(t_stack *st)
{
    t_action    *act;
    int     reg;

    act = action_three(st);
    if (act)
        exeaction(act, st);
    store_stack_info(st);
    // printf("after exe: \n");
    // ft_print_stack_info(st);
    // printf("\n");
    if (st->mini_a == st->top_a && st->top_b == -1)
        reg = 0;
    else if (st->mini_a == st->top_a && st->top_b != -1)
        reg = 1;
    // else if (st->mini_a == st->size - 1 && st->top_b == -1)
    //     reg = 2;
    // else if (st->mini_a == st->size - 1 && st->top_b != -1)
    //     reg = 3;
    else
        reg = -1;
    return (reg);
}

static int sort_remain(t_stack *st)
{
    int loop_time;
    t_action    *act;
    t_optimizer *opm;

    loop_time = st->num_b;
    
    while (loop_time)
    {
        // printf("\n-------\n");
        // printf("stack a info --------------\n");
        // ft_print_stack_a(st);
        // printf("stack b info --------------\n");
        // ft_print_stack_b(st);
        // printf("\n");
        opm = getoptimizer(st);
        
        act = opaction(opm);    //opm has been free;
        exeaction(act, st);
        loop_time--;
    }
    return (0);
}

static  int rotate_a(t_stack *st)
{
    int rotate_times;
    t_action    *act;

    store_stack_info(st);
    rotate_times = st->mini_a - st->top_a;
    if (rotate_times > st->num_a / 2)
    {
        rotate_times = st->size - 1 - st->mini_a + 1;
        act = getinstruction(8, rotate_times);
    }
    else
        act = getinstruction(5, rotate_times);
    exeaction(act, st);
    return (0);
}
//b is empty but not in order;
int     sort_five(t_stack *st, int pb)
{
    int reg;
    t_action    *act;

    act = getinstruction(4, pb);
    exeaction(act, st);
    reg = sort_three(st);
    // printf("stack a info --------------\n");
    //     ft_print_stack_a(st);
    //     printf("stack b info --------------\n");
    //     ft_print_stack_b(st);
    //     printf("\n");

    //b is not empty:
    if (reg)
        reg = sort_remain(st);
    reg = rotate_a(st);
    return (reg);
}