#include "../push_swap.h"

void    rra(t_stack *st)
{
    int index;
    int count;
    int buf;

    count = 0;
    ft_strcpy(st->print, "rb");
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

void    rrb(t_stack *st)
{

}

void    rrr(t_stack *st)
{

}