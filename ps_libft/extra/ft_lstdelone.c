/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 00:28:26 by xinzhang          #+#    #+#             */
/*   Updated: 2019/02/05 18:54:35 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && (*alst) != NULL)
	{
		if ((*alst)->content != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			(*alst)->next = NULL;
			free(*alst);
			(*alst) = NULL;
		}
	}
}
