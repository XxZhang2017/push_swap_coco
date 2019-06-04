/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:03:03 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 10:09:46 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** opm_code: 0
*/

t_action		*upa_upb(t_optimizer *opm)
{
	t_action	*act;
	int			comm;

	if (!opm)
		return (NULL);
	act = NULL;
	comm = (opm->upa <= opm->upb) ? opm->upa : opm->upb;
	act = getinstruction(7, comm);
	if (opm->upa > opm->upb)
		act = moreaction(act, 5, opm->upa - comm);
	else
		act = moreaction(act, 6, opm->upb - comm);
	act = moreaction(act, 3, 1);
	return (act);
}

/*
** opm_code: 1
*/

t_action		*upa_downb(t_optimizer *opm)
{
	t_action	*act;

	if (!opm)
		return (NULL);
	act = NULL;
	act = getinstruction(5, opm->upa);
	act = moreaction(act, 9, opm->downb);
	act = moreaction(act, 3, 1);
	return (act);
}

/*
** opm_code: 2
*/

t_action		*downa_downb(t_optimizer *opm)
{
	t_action	*act;
	int			comm;

	if (!opm)
		return (NULL);
	act = NULL;
	comm = (opm->downa < opm->downb) ? opm->downa : opm->downb;
	act = getinstruction(10, comm);
	if (opm->downa > opm->downb)
		act = moreaction(act, 8, opm->downa - comm);
	else
		act = moreaction(act, 9, opm->downb - comm);
	act = moreaction(act, 3, 1);
	return (act);
}

/*
** opm_code: 3
*/

t_action		*downa_upb(t_optimizer *opm)
{
	t_action	*act;

	if (!opm)
		return (NULL);
	act = NULL;
	act = getinstruction(8, opm->downa);
	act = moreaction(act, 6, opm->upb);
	act = moreaction(act, 3, 1);
	return (act);
}

int				get_opmcode(int ua, int ub, int da, int db)
{
	int			s[4];
	int			reg;
	int			smallest;
	int			i;

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
			reg = i;
			smallest = s[i];
		}
		i++;
	}
	return (reg);
}
