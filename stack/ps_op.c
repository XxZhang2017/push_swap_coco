#include "../push_swap.h"

void    pa(t_stack *st)
{
    //error, b is empty;
    strcpy(st->print, "pa");
    if (st->num_b == 0)
        return ;
    st->buf_a = st->arr_b[st->top_b];
    if (st->num_a == 0)
    {
        st->top_a = st->size - 1;
        st->arr_a[st->top_a] = st->buf_a;
        st->top_b++;
    }
    else
    {
        (st->top_a)--;
        st->arr_a[st->top_a] = st->buf_a; 
        (st->top_b)++;  
    }
    (st->num_b)--;
    (st->num_a)++;
    printf("pa\n");
}

void    pb(t_stack *st)
{
    //error, b is empty;
    strcpy(st->print, "pb");
    if (st->num_a == 0)
        return ;
    
    st->buf_b = st->arr_a[st->top_a];
    if (st->num_b == 0)
    {
        st->top_b = st->size - 1;
        st->arr_b[st->top_b] = st->buf_b;
        st->top_a++;
    }
    else
    {
        (st->top_b)--;
        st->arr_b[st->top_b] = st->buf_b; 
        (st->top_a)++;    
    }
    (st->num_a)--;
    (st->num_b)++;
    printf("pb\n");
}