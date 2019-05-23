#include "../push_swap.h"

void    sa(t_stack *st)
{
    if (st->num_a < 2)
        return;
    strcpy(st->print, "sa");
    st->buf_a = st->arr_a[st->top_a];
    st->arr_a[st->top_a] = st->arr_a[st->top_a + 1];
    st->arr_a[st->top_a + 1] = st->buf_a;
    
    printf("sa\n");
}

void    sb(t_stack *st)
{
    strcpy(st->print, "sb");
    st->buf_b = st->arr_b[st->top_b];
    st->arr_b[st->top_b] = st->arr_b[st->top_b + 1];
    st->arr_b[st->top_b + 1] = st->buf_b;
    printf("sb\n");
}