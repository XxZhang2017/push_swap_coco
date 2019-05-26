#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include <stdio.h>
// # include <stdlib.h>
// # include <string.h>
# include <time.h>
# include <string.h>
# include "ps_libft/libft.h"

typedef struct s_stack
{
    //stack a:
    int top_a;
    int *arr_a;
    int num_a;
    int buf_a;

    int mini_a;
    int maxi_a;
    int minv_a;
    int maxv_a;

    //stack b:
    int top_b;
    int *arr_b;
    int num_b;
    int buf_b;

    int mini_b;
    int maxi_b;
    int minv_b;
    int maxv_b;

    //comm:
    int size;
    char    print[4];
    int  _flag;
    int op;
    //debug:
    int print_flag_a;
    int print_flag_b;
    int step;

}      t_stack;

typedef struct s_action
{
    int a_code;
    int len;
    struct s_action *head;
    struct s_action *next;
}               t_action;

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

//stack state:
t_stack    *initstack(char  **arglist, int size);
void    set_stack_info(t_stack *st, int flag[2]);
void    store_stack_info(t_stack *st);


//debug:
void        ft_print_stack_a(t_stack *t);
void		ft_print_stack_b(t_stack *st);
void        ft_print_arglist(char **av, int i);
void        ft_print_stack_info(t_stack *st);

//validation:
char        **eval(int ac, char **av, int *size, int *flag);
t_stack     *validate(int ac, char **av);

//action:
t_action    *newAction(int acode);
t_action    *appendAction(t_action *act, int acode);
t_action    *moreAction(t_action *act, int acode, int num);
t_action    *getInstruction(int acode, int num);
void        exeAction(t_action *act, t_stack *st);

//sort:
int    sort_three(t_stack *st);
int     isfinished(t_stack *st);
int     isordered(t_stack *st);
int     exeStrategy(t_stack *st);
t_action    *to_topb(t_stack *st, int index);
t_action    *moveToA(t_stack *st, int num);
t_action    *comb_action(t_action *aa, t_action *ab);


//free:
void    free_arglist(char **al, int len);
void    free_stack(t_stack *st);
void    free_action(t_action *act);
#endif