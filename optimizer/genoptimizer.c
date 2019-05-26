/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genoptimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 00:33:38 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/26 00:33:41 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_optimizer *init_opm(int ua, int ub, int da, int db)
{
    t_optimizer *opm;

    opm = (t_optimizer *)malloc(sizeof(t_optimizer));
    opm->upa = ua;
    opm->upb = ub;
    opm->downa = da;
    opm->downb = da;
    opm->opm_code = -1;
    
    return (opm);
}
