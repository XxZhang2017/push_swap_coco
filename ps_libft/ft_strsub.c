/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:38:57 by xinzhang          #+#    #+#             */
/*   Updated: 2019/02/05 13:01:32 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*reg;

	if (!s)
		return (NULL);
	reg = ft_strnew(len);
	if (!reg)
		return (NULL);
	ft_strncpy(reg, &s[start], len);
	return (reg);
}
