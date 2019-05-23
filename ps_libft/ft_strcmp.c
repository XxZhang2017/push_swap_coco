/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 00:36:57 by xinzhang          #+#    #+#             */
/*   Updated: 2019/02/05 12:57:10 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = -1;
	while (s1[++i] && s2[i] && s1[i] == s2[i])
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
