/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:35:09 by xinzhang          #+#    #+#             */
/*   Updated: 2019/02/05 13:47:17 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*newptr;

	newptr = ft_strnew(n);
	if (newptr == NULL)
		return (NULL);
	ft_strncpy(newptr, s1, n);
	return (newptr);
}
