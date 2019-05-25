/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:31:46 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/24 22:31:47 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int  getMin(int a, int b)
{
    return (a < b) ? a : b;
}

static int  get_acode(t_action *aa, t_action *ab)
{
    int acode;

    if (aa->len > ab->len)
        acode = aa->a_code;
    else 
        acode = ab->a_code;
    return (acode);
}
// static t_action *get_next_action(t_action *aa, t_action *ab)
// {
//     int op_times;
//     int acode;
//     t_action    *act;

//     if(aa->len == ab->len)
//         act = NULL;
//     else
//     {
//         op_times = aa->len - ab->len;
//         if (op_times < 0)
//             op_times = -op_times;
//         if (aa->len > ab->len)
//             acode = aa->a_code;
//         else 
//             acode = ab->a_code;
//         act = getInstruction(acode, op_times);
//     }
//     free_action(aa->head);
//     free_action(ab->head);
//     return (act);
// }

static t_action *original_action(t_action *aa, t_action *ab)
{
    aa = moreAction(aa, ab->a_code, ab->len);
    aa = moreAction(aa, 4, 1);
    free_action(ab);
    return (aa);
}

t_action    *comb_action(t_action *aa, t_action *ab)
{
    int     op_times;
    int     acode;
    t_action    *act;
    if (aa->a_code == 5 && ab->a_code == 6) //ra, rb
    {
        op_times = getMin(aa->len, ab->len); 
        act = getInstruction(7, op_times); //rr;

    }
    else if (aa->a_code == 8 && ab->a_code == 9)
    {
        op_times = getMin(aa->len, ab->len); 
        act = getInstruction(10, op_times); //rrr;
    }
    else
        return original_action(aa, ab);
    op_times = aa->len - ab->len;
    if (op_times == 0)
        return (act);
    op_times = (op_times > 0) ? op_times : -op_times;
    act = moreAction(act, get_acode(aa, ab), op_times);
    act = moreAction(act, 4, 1);
    free_action(aa);
    free_action(ab);
    return (act);
}
