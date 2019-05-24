/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:34:30 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/14 00:00:33 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int		ft_print_empty(t_stack *stks, char ch)
// {
// 	static int	empty_a;
// 	static int	empty_b;

// 	if (ch == 'a')
// 	{
// 		if ((stks->num_a < stks->size) && stks->print_flag_a == 0)
// 			empty_a = stks->size - stks->num_a;
// 		if (empty_a && empty_a-- && (stks->print_flag_a = 1))
// 			return (1);
// 		return (0);
// 	}
// 	if (ch == 'b')
// 	{
// 		if ((stks->num_b < stks->size) && stks->print_flag_b == 0)
// 			empty_b = stks->size - stks->num_b;
// 		if (empty_b && empty_b-- && (stks->print_flag_b = 1))
// 			return (1);
// 		return (0);
// 	}
// 	return (0);
// }

// static void		ft_print_stack_b(int *elem_b, int *top_b, t_stack *stks)
// {
// 	if ((*elem_b))
// 	{
// 		if (ft_print_empty(stks, 'b') == 1)
// 			return ((void)ft_printf("\n"));
// 		ft_printf("%d\n", stks->arr_b[(*top_b)]);
// 		(*top_b)++;
// 		(*elem_b)--;
// 	}
// 	else
// 		ft_printf("\n");
// }

// static void		ft_print_stack_a(int *elem_a, int *top_a, t_stack *stks, int *i)
// {
// 	ft_printf(" %d:   ", (*i)++);
// 	if ((*elem_a))
// 	{
// 		if (ft_print_empty(stks, 'a') == 1)
// 			return ((void)ft_printf("    "));
// 		ft_printf("%d   ", stks->arr_a[(*top_a)]);
// 		(*top_a)++;
// 		(*elem_a)--;
// 	}
// 	else
// 		ft_printf("    ");
// }

// static void		ft_print_info(t_stack *stks, int num, int *index)
// {
// 	if (num == 1)
// 		ft_printf("%s - - - - - - - - - - - - - %d\n\n",
// 	stks->print, (stks->step)++);
// 	else if (num == 2)
// 	{
// 		while (*index < stks->size)
// 			ft_printf("[%d] \n", (*index)++);
// 		ft_printf("(i)    _     _\n       a     b\n");
// 		stks->print_flag_a = 0;
// 		stks->print_flag_b = 0;
// 	}
// }

// void			ft_print_stacks(t_stack *stks)
// {
// 	int			top_a;
// 	int			elem_a;
// 	int			top_b;
// 	int			elem_b;
// 	int			index;

// 	// if (stks->flag >> 1 & 1)
// 	// 	ft_printf(COLOR_RED);
// 	top_a = stks->top_a;
// 	elem_a = stks->num_a;
// 	top_b = stks->top_b;
// 	elem_b = stks->num_b;
// 	index = 0;
// 	ft_print_info(stks, 1, &index);
// 	while (1)
// 	{
// 		ft_print_stack_a(&elem_a, &top_a, stks, &index);
// 		ft_print_stack_b(&elem_b, &top_b, stks);
// 		if (elem_a == 0 && elem_b == 0)
// 			break ;
// 	}
// 	ft_print_info(stks, 2, &index);
// 	// ft_printf(COLOR_END);
// }

void		ft_print_stack_a(t_stack *st)
{
	int elem;
	int top;

	top = st->top_a;
	elem = st->num_a;

	if (!elem)
	{
		printf("empty\n");
		return;
	}	
	while (elem)
	{
		printf("%d\n", st->arr_a[top]);
		top++;
		elem--;
	}
}

void		ft_print_stack_b(t_stack *st)
{
	int elem;
	int top;

	top = st->top_b;
	elem = st->num_b;

	if (!elem)
	{
		printf("empty\n");
		return;
	}	
	while (elem)
	{
		printf("%d\n", st->arr_b[top]);
		top++;
		elem--;
	}
}

void    ft_print_stack_info(t_stack *st)
{
    printf("stack info ------------------ \n");
	printf("stack a: top:  %d,   top index:  %d\n", st->arr_a[st->top_a], st->top_a);
    printf("stack a: min:  %d,   min index:  %d\n", st->minv_a, st->mini_a);
    printf("stack a: max:  %d,   max index:  %d\n", st->maxv_a, st->maxi_a);
    printf("----------------------------- \n");
	printf("stack b: top:  %d,   top index:  %d\n", st->arr_b[st->top_b], st->top_b);
    printf("stack b: min:  %d,   min index:  %d\n", st->minv_b, st->mini_b);
    printf("stack b: max:  %d,   max index:  %d\n", st->maxv_b, st->maxi_b);
}

// static void		print_stack_a(int *elem_a, int *top_a, t_stack *stks, int *i)
// {
// 	ft_printf(" %d:   ", (*i)++);
// 	if ((*elem_a))
// 	{
// 		if (ft_print_empty(stks, 'a') == 1)
// 			return ((void)ft_printf("    "));
// 		ft_printf("%d   ", stks->arr_a[(*top_a)]);
// 		(*top_a)++;
// 		(*elem_a)--;
// 	}
// 	else
// 		ft_printf("    ");
// }