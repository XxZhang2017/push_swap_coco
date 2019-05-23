/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 00:31:45 by xinzhang          #+#    #+#             */
/*   Updated: 2019/02/05 13:24:22 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
	ft_putstr_fd(&num[++digit], fd);
}
