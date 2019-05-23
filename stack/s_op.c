#include "../push_swap.h"

void    sa(t_stack *st)
{
    if (st->num_a < 2)
        return;
    ft_strcpy(st->print, "sa");
    st->buf_a = st->arr_a[st->top_a];
    st->arr_a[st->top_a] = st->arr_a[st->top_a + 1];
    st->arr_a[st->top_a + 1] = st->buf_a;
    
    if (st->_flag)
        printf("sa\n");
}

void    sb(t_stack *st)
{
    ft_strcpy(st->print, "sb");
    st->buf_b = st->arr_b[st->top_b];
    st->arr_b[st->top_b] = st->arr_b[st->top_b + 1];
    st->arr_b[st->top_b + 1] = st->buf_b;

    if (st->_flag)
        printf("sb\n");
}

void    ss(t_stack *st)
{
    int buf;

    buf = st->_flag;
    st->_flag = 0;
    ft_strcpy(st->print, "ss");
    sa(st);
    sb(st);
    st->_flag = buf;
    if (st->_flag)
        printf("ss\n");
}