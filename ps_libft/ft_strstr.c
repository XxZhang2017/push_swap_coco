/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:49:30 by xinzhang          #+#    #+#             */
/*   Updated: 2019/02/05 18:51:09 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	char	*begin;
	char	*pattern;

	if (substr && !ft_strlen(substr))
		return ((char *)str);
	while (*str)
	{
		begin = (char *)str;
		pattern = (char *)substr;
		while (*str && *pattern && *str == *pattern)
		{
			str++;
			pattern++;
		}
		if (!*pattern)
			return (begin);
		str = begin + 1;
	}
	return (NULL);
}
