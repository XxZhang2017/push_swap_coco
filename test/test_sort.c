/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 23:37:51 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/23 23:37:52 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int ac, char **av)
{
    t_stack *st;
    int     reg;
    
    st = validate(ac, av);
    if (!st)
        return (0);
    pb(st);
    pb(st);
    printf("return val is %d\n", reg);
    printf("stack a   --------\n");
    ft_print_stack_a(st);
    printf("stack b   --------\n");
    ft_print_stack_b(st);
    printf("\n\n");
    reg = sort_three(st);
    printf("return val is %d\n", reg);
    printf("stack a   --------\n");
    ft_print_stack_a(st);
    printf("stack b   --------\n");
    ft_print_stack_b(st);
    
    
    free_stack(st);
    sleep(10);
}
