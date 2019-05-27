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
  

        t_stack *t;
        
        t_action    *act;


        t = validate(ac, av);
        if (!t)
            return (0);
        printf("stack a info --------------\n");
        ft_print_stack_a(t);
        printf("stack b info --------------\n");
        ft_print_stack_b(t);
        printf("\n");

        sort_five(t, 7);
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
        
    return (0);
}