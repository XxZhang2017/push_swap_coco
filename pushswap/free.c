/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:09:06 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 09:09:11 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_arglist(char **al, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(al[i]);
		i++;
	}
	free(al);
}
