/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 00:27:03 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/26 00:27:04 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//steps not include 'pa';
int     s_upa(t_stack *st, int num)
{
    int pos;
    int steps;

    pos = search_pos_a(st, num);
    // printf("pos a is %d\n", pos);
    if (pos == -1)
    {
        write(1, "searching a pos error\n", 16);
        exit(1);
    }
    if (pos == st->top_a - 1)
        steps = 0;
    else
        steps = pos - st->top_a + 1;
    if (steps < 0)
            steps = 0;
    return (steps);
}

int     s_downa(t_stack *st, int num)
{
    int pos;
    int steps;

    pos = search_pos_a(st, num);
    if (pos == -1)
    {
        write(1, "searching a down error\n", 16);
        exit(1);
    }
    if (pos == st->top_a - 1)
        return (0);
    steps = st->size - 1 - pos;
    return steps;
}

int     s_upb(t_stack *st, int num)
{
    int pos;
    int steps;

    pos = search_pos_b(st, num);
    if (pos == -1)
    {
        write(1, "searching b up error\n", 16);
        exit(1);
    }
    if (pos == st->top_b)
        steps = 0;
    else
        steps = pos - st->top_b;
    if (steps < 0)
            steps = 0;
    return (steps);
}

int     s_downb(t_stack *st, int num)
{
    int pos;
    int steps;

    pos = search_pos_b(st, num);
    if (pos == -1)
    {
        write(1, "searching b down error\n", 16);
        exit(1);
    }
    if (pos == st->top_b - 1)
        return (0);
    steps = st->size - 1 - pos + 1;
    return steps;
}