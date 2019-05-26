#include "../push_swap.h"

// int main (int ac, char **av)
// {
//     t_action    *act;
    
//     t_optimizer *opm;
//     opm = init_opm(s_upa(NULL, 5), s_downa(NULL, 6), s_upb(NULL, 0), s_downb(NULL, 2));
//     opm->opm_code = 0;
//     act = opAction(opm);
//     opm->opm_code = 1;
//     act = opAction(opm);
//     opm->opm_code = 2;
//     act = opAction(opm);
//     opm->opm_code = 3;
//     act = opAction(opm);


//     return (0);
// }

int main(int ac, char **av)
{
    int pos;
    int adj_pos;
    // int feed[] = {1, 7, 10, 18, 20};
    int feed[] = {4, 6, 7 ,8, 10};
    int i;
    int score;
    // t_action    *act;
    
    for (i = 0; i < 5; i++)
    {
        t_stack *t;
        t_optimizer *opm;
        t_action    *act;

        t = initstack(&av[1], 6);
        t = validate(ac, av);
        if (!t)
            return (0);
        // pb(t);
        // pb(t);
        pb(t);

        t->arr_b[t->top_b] = feed[i];
        opm = init_opm(s_upa(t, feed[i]), s_upb(t, feed[i]), s_downa(t, feed[i]), s_downb(t, feed[i]));
        opm->opm_code =  get_opmcode(s_upa(t, feed[i]), s_upb(t, feed[i]), s_downa(t, feed[i]), s_downb(t, feed[i]));
        
        printf("operation on %d\n", feed[i]);
        printf("stack a info --------------\n");
        ft_print_stack_a(t);
        printf("stack b info --------------\n");
        ft_print_stack_b(t);
        printf("\n");

        act = opAction(opm);
        exeAction(act, t);
        // printf("score upa: %d\n", s_upa(t, feed[i]));
        // printf("score upb: %d\n", s_upb(t, feed[i]));
        // printf("score downa: %d\n", s_downa(t, feed[i]));
        // printf("score downb: %d\n", s_downb(t, feed[i]));

        
        printf("stack a info --------------\n");
        ft_print_stack_a(t);
        printf("stack b info --------------\n");
        ft_print_stack_b(t);
        printf("\n");
        free_stack(t);
        free(opm);
    }
    return (0);
}