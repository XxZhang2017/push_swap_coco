/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:23:54 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 10:46:10 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_optimizer	*getcandi(t_stack *st, int index)
{
	t_optimizer		*opm;

	opm = init_opm(st->arr_b[index], index);
	cal_opm_attr_a(opm, s_upa(st, st->arr_b[index]),
					s_downa(st, st->arr_b[index]));
	cal_opm_attr_b(opm, s_upb(st, st->arr_b[index]),
					s_downb(st, st->arr_b[index]));
	set_opm_attr_code_step(opm);
	return (opm);
}

t_optimizer		*getoptimizer(t_stack *st)
{
	int			loop_index;
	t_optimizer	*opm;
	t_optimizer	*candi;

	loop_index = st->top_b - 1;
	opm = NULL;
	candi = NULL;
	while (++loop_index <= st->size - 1)
	{
		candi = getcandi(st, loop_index);
		if (!opm)
			opm = candi;
		else
		{
			if (candi->steps < opm->steps)
			{
				free(opm);
				opm = candi;
			}
			else
				free(candi);
		}
	}
	return (opm);
}
