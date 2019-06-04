#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include "ps_libft/libft.h"
# define BUFF_SIZE 4096
typedef struct s_stack
{
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
	char	print[4];
	int  _flag;
	int op;
	//debug:
	int print_flag_a;
	int print_flag_b;
	int step;

}	   t_stack;

typedef struct	s_action
{
	int a_code;
	int len;
	struct s_action *head;
	struct s_action *next;
}				t_action;

typedef struct	s_optimizer
{
	int opm_code;
	int upa;
	int upb;
	int downa;
	int downb;
	int steps;

	int operand;
	int operand_index; 
}				t_optimizer;


void	pa(t_stack *st);
void	pb(t_stack *st);
void	ra(t_stack *st);
void	rb(t_stack *st);
void	sa(t_stack *st);
void	sb(t_stack *st);
void	ss(t_stack *st);
void	rr(t_stack *st);
void	rrr(t_stack *st);
void	rra(t_stack *st);
void	rrb(t_stack *st);

//stack state:
t_stack    *initstack(char	**arglist, int size);
void	set_stack_info(t_stack *st, int flag[2]);
void	store_stack_info(t_stack *st);


//debug:
void		ft_print_stack_a(t_stack *t);
void		ft_print_stack_b(t_stack *st);
void		ft_print_arglist(char **av, int i);
void		ft_print_stack_info(t_stack *st);

//validation:
char		**eval(int ac, char **av, int *size, int *flag);
t_stack		*validate(int ac, char **av);
char	**get_arglist(int ac, char **av);

//action:
t_action	*newaction(int acode);
t_action	*appendaction(t_action *act, int acode);
t_action	*moreaction(t_action *act, int acode, int num);
t_action	*getinstruction(int acode, int num);
void		exeaction(t_action *act, t_stack *st);

//sort:
int    sort_three(t_stack *st);
int		isfinished(t_stack *st);
int		isordered(t_stack *st);
t_action	*to_topb(t_stack *st, int index);
t_action	*comb_action(t_action *aa, t_action *ab);
int			sort_five(t_stack *st, int pb);
int			sort_two(t_stack *st);
//optimize:

t_optimizer *init_opm(int operand, int index);
// void	cal_opm_attr(t_optimizer *opm, int ua, int ub, int da, int db);
void		cal_opm_attr_a(t_optimizer *opm, int ua, int da);
void		cal_opm_attr_b(t_optimizer *opm, int ub, int db);
void		set_opm_attr_code_step(t_optimizer *opm);
int		get_opmcode(int ua, int ub, int da, int db);
int		get_steps(t_optimizer *opm);
t_optimizer *getoptimizer(t_stack *st);

int		s_upa(t_stack *st, int num);
int		s_downa(t_stack *st, int num);
int		s_upb(t_stack *st, int num);
int		s_downb(t_stack *st, int num);
t_action	*upa_upb(t_optimizer *opm);
t_action	*downa_downb(t_optimizer *opm);
t_action	*upa_downb(t_optimizer *opm);
t_action	*downa_upb(t_optimizer *opm);
t_action	*opaction(t_optimizer *opm);
//searching:
int  search_pos_a(t_stack *st, int num);
int  search_min_down_a(t_stack *st, int num);
int  search_top_to_max_a(t_stack *st, int num);
int  search_min_down_b(t_stack *st, int num);
int  search_top_to_max_b(t_stack *st, int num);
int  search_pos_b(t_stack *st, int num);

//free:
void	free_arglist(char **al, int len);
void	free_stack(t_stack *st);
void	free_action(t_action *act);
#endif
