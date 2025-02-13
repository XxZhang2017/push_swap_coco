/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:46:47 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/20 14:33:02 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_get_last(t_list *t)
{
	if (t)
	{
		while (t && t->next)
			t = t->next;
		return (t);
	}
	return (NULL);
}
