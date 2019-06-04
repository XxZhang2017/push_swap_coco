/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:05:15 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 09:08:25 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_action		*newaction(int acode)
{
	t_action	*reg;

	reg = (t_action *)malloc(sizeof(t_action));
	reg->a_code = acode;
	reg->head = reg;
	reg->next = NULL;
	reg->head->len = 1;
	return (reg);
}

t_action		*appendaction(t_action *act, int acode)
{
	t_action	*newnode;

	if (!act)
		act = newaction(acode);
	else
	{
		newnode = newaction(acode);
		newnode->head = act->head;
		act->head->len++;
		act->next = newnode;
		act = newnode;
	}
	return (act);
}

void			free_action(t_action *act)
{
	t_action	*help;

	while (act)
	{
		help = act->next;
		free(act);
		act = help;
	}
}
