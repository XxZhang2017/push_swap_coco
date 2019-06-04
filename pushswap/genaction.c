/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:46:22 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 09:47:13 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_action		*opaction(t_optimizer *opm)
{
	t_action	*(*optr[4])(t_optimizer *);
	t_action	*act;

	optr[0] = &upa_upb;
	optr[1] = &upa_downb;
	optr[2] = &downa_downb;
	optr[3] = &downa_upb;
	act = optr[opm->opm_code](opm);
	if (opm)
		free(opm);
	return (act);
}
