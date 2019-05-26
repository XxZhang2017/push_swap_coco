#include "../push_swap.h"


void    pa(t_stack *st)
{
    //error, b is empty;
    if (st->num_b == 0)
        return ;
    ft_strcpy(st->print, "pa");
    st->buf_a = st->arr_b[st->top_b];
    if (st->num_a == 0)
    {
        st->top_a = st->size - 1;
        st->arr_a[st->top_a] = st->buf_a;
        st->top_b++;
        if (st->top_b == st->size)
            st->top_b = -1;
    }
    else
    {
        (st->top_a)--;
        st->arr_a[st->top_a] = st->buf_a; 
        (st->top_b)++;
        if (st->top_b == st->size)
            st->top_b = -1;
    }
    (st->num_b)--;
    (st->num_a)++;

    if (st->_flag)
        printf("pa\n");
}

void    pb(t_stack *st)
{
    //error, b is empty;
    if (st->num_a == 0)
        return ;
    ft_strcpy(st->print, "pb");
    st->buf_b = st->arr_a[st->top_a];
    if (st->num_b == 0)
    {
        st->top_b = st->size - 1;
        st->arr_b[st->top_b] = st->buf_b;
        st->top_a++;
        if (st->top_a == st->size)
            st->top_a = -1;
    }
    else
    {
        (st->top_b)--;
        st->arr_b[st->top_b] = st->buf_b; 
        (st->top_a)++;
        if (st->top_a == st->size)
            st->top_a = -1;  
    }
    (st->num_a)--;
    (st->num_b)++;

    if (st->_flag)
        printf("pb\n");
}

