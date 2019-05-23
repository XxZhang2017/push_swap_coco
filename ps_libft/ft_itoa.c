/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 00:27:34 by xinzhang          #+#    #+#             */
/*   Updated: 2019/02/06 20:22:43 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	num[12];
	int		sign;
	int		digit;

	num[11] = '\0';
	sign = (n < 0) ? -1 : 1;
	digit = 10;
	if (n == 0)
		num[digit--] = '0';
	while (n != 0)
	{
		num[digit--] = (char)(((n % 10) * sign) + '0');
		n = (n - (n % 10)) / 10;
	}
	if (sign < 0)
		num[digit--] = '-';
	return (ft_strdup(&num[++digit]));
}
