/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:44:59 by xinzhang          #+#    #+#             */
/*   Updated: 2019/02/05 13:16:05 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdest;
	int		i;

	csrc = (char *)src;
	cdest = (char *)dst;
	if (cdest - csrc > 0)
	{
		i = (int)len;
		while (i >= 1)
		{
			i--;
			cdest[i] = csrc[i];
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}
