/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genoptimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:49:30 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 10:40:36 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_optimizer		*init_opm(int operand, int index)
{
	t_optimizer *opm;

	opm = (t_optimizer *)malloc(sizeof(t_optimizer));
	opm->operand = operand;
	opm->operand_index = index;
	opm->upa = -1;
	opm->upb = -1;
	opm->downa = -1;
	opm->downb = 1;
	opm->opm_code = -1;
	return (opm);
}

int			get_steps(t_optimizer *opm)
{
	if (opm->opm_code == 0)
		return (opm->upa > opm->upb ? opm->upa : opm->upb);
	else if (opm->opm_code == 1)
		return (opm->upa + opm->downb);
	else if (opm->opm_code == 2)
		return (opm->downa > opm->downb ? opm->downa : opm->downb);
	else if (opm->opm_code == 3)
		return (opm->downa + opm->upb);
	return (0);
}

void		cal_opm_attr_a(t_optimizer *opm, int ua, int da)
{
	opm->upa = ua;
	opm->downa = da;
	// opm->opm_code = get_opmcode(ua, ub, da, db);
	// opm->steps = get_steps(opm);
}

void		cal_opm_attr_b(t_optimizer *opm, int ub, int db)
{
	opm->upb = ub;
	opm->downb = db;
	// opm->opm_code = get_opmcode(ua, ub, da, db);
	// opm->steps = get_steps(opm);
}

void		set_opm_attr_code_step(t_optimizer *opm)
{
	opm->opm_code = get_opmcode(opm->upa, opm->upb, opm->downa, opm->downb);
	opm->steps = get_steps(opm);
}
