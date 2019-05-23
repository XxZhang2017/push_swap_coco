#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
// typedef struct stack
// {
//     int top_a;
//     int *arr_a;
//     int num_a;
//     int buf_a;
// } 
typedef struct s_stack
{
    //stack a:
    int top_a;
    int *arr_a;
    int num_a;
    int buf_a;

    //stack b:
    int top_b;
    int *arr_b;
    int num_b;
    int buf_b;

    //comm:
    int size;
    char    print[4];
    int  _flag;
    //debug:
    int print_flag_a;
    int print_flag_b;
    int step;

}      t_stack;


void    pa(t_stack *st);
void    pb(t_stack *st);
void    ra(t_stack *st);
void    rb(t_stack *st);
void    sa(t_stack *st);
void    sb(t_stack *st);
void    ss(t_stack *st);
void    rr(t_stack *st);
void    rrr(t_stack *st);
void    rra(t_stack *st);
void    rrb(t_stack *st);


t_stack    *initstack(char  **arglist, int size);
void        ft_print_stack_a(t_stack *t);
void		ft_print_stack_b(t_stack *st);
#endif