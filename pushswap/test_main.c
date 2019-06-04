/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:02:37 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 09:02:49 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack *t;

	if (ac == 1)
		return (0);
	t = validate(ac, av);
	if (!t)
		return (0);
	if (t->size == 1)
		return (0);
	else if (t->size == 2)
		sort_two(t);
	else if (t->size == 3)
		sort_three(t);
	else
		sort_five(t, t->size - 3);
	free_stack(t);
	return (0);
}
