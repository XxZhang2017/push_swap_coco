/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 00:38:44 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/26 00:38:47 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_action    *opAction(t_optimizer *opm)
{
    t_action   *(*optr[4])(t_optimizer *);
    // t_action   (*optr)(t_optimizer *);
    t_action    *act;
    
    

    optr[0] = &upa_upb;
    optr[1] = &downa_downb;
    optr[2] = &upa_downb;
    optr[3] = &downa_upb;
    act = optr[opm->opm_code](opm);

    return (act);
}

