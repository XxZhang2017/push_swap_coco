/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 00:28:42 by xinzhang          #+#    #+#             */
/*   Updated: 2019/02/05 19:09:59 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tl;

	tl = (t_list *)malloc(sizeof(t_list));
	if (tl == NULL)
		return (NULL);
	if (content == NULL)
	{
		tl->content = NULL;
		tl->content_size = 0;
	}
	else
	{
		if ((tl->content = malloc(sizeof(t_list))) == NULL)
		{
			free(tl);
			return (NULL);
		}
		ft_memcpy(tl->content, content, content_size);
		tl->content_size = content_size;
	}
	tl->next = NULL;
	return (tl);
}
