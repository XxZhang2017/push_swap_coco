/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:38:03 by xinzhang          #+#    #+#             */
/*   Updated: 2019/02/05 18:46:36 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;

	if (!substr && !ft_strlen(substr))
		return ((char *)str);
	while (*str && len)
	{
		i = 0;
		while (i < len && str[i] && substr[i] && str[i] == substr[i])
			i++;
		if (!substr[i])
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
