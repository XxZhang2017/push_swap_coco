#include "../push_swap.h"

static void assign(char **arglist, t_stack *st)
{
    int i;
    i = st->size - 1;

    while (i >= 0)
    {
        st->arr_a[i] = ft_atoi(arglist[i]);
        i--;
    }
    st->top_a = 0;
    st->num_a = st->size;
}

t_stack *initstack(char **arglist, int size)
{
    t_stack *reg = (t_stack *)malloc(sizeof(t_stack));

    reg->arr_a = (int *)malloc(sizeof(int) * size);
    reg->arr_b = (int *)malloc(sizeof(int) * size);

    reg->size = size;
    reg->num_b = 0;
    assign(arglist, reg);

    reg->top_b = -1;

    reg->_flag = 1;
    return reg;

}

void    set_stack_info(t_stack *st, int flag[2])
{
    st->_flag = flag[0] + (flag[1] << 1);
}