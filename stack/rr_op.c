#include "../push_swap.h"

void    rra(t_stack *st)
{
    int index;
    int count;
    int buf;

    count = 0;
    if (st->num_a > 0)
    {
        ft_strcpy(st->print, "rra");
        index = st->size - 1;
     // store button ele;
        buf = st->arr_a[(st->size) - 1];
        while(count < st->num_a - 1)
        {
            st->arr_a[index] = st->arr_a[index - 1];
            index--;
            count++;
        }
        st->arr_a[st->top_a] = buf;
        if (st->_flag)
            printf("rra\n");
    }
    
}

void    rrb(t_stack *st)
{
    int index;
    int count;
    int buf;

    count = 0;
    if (st->num_b > 0)
    {
        ft_strcpy(st->print, "rrb");
        index = st->size - 1;
     // store button ele;
        buf = st->arr_b[(st->size) - 1];
        while(count < st->num_b - 1)
        {
            st->arr_b[index] = st->arr_b[index - 1];
            index--;
            count++;
        }
        st->arr_b[st->top_b] = buf;
        if (st->_flag)
            printf("rrb\n");
    }
    
}

void    rrr(t_stack *st)
{
    int buf;

    if (st->num_a > 0 && st->num_b > 0)
    {
        ft_strcpy(st->print, "rrr");
        buf = st->_flag;
        st->_flag = 0;
        rra(st);
        rrb(st);
        st->_flag = buf;
    if (st->_flag)
        printf("rrr\n");
    }
}
