#ifndef PUSHSWAP_H
#define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

/* prototypes */
double	compute_disorder(t_node *a);
void	error_exit(void);
char	**collect_tokens(int ac, char **av, int start_i, int *out_count);
int	count_total_tokens(int ac, char **av, int start_i);
int		*validate_and_parse(char **tokens, int *out);
void	free_tokens_partial(char **tokens, int count);
int		atoi_strict(const char *str, int *out);
int		check_duplicates(int *arr, int n);
int		count_words(char *s);
char	*copy_word(char *s, int *i);

t_node	*build_stack_a(int *arr, int n);
void	free_stack(t_node *stack);
int		is_sorted(t_node *stack);
int		stack_size(t_node *stack);
t_node	*stack_last(t_node *stack);
typedef struct s_ops
{
	long	total;
	long	sa;
	long	sb;
	long	ss;
	long	pa;
	long	pb;
	long	ra;
	long	rb;
	long	rr;
	long	rra;
	long	rrb;
	long	rrr;
}	t_ops;

typedef enum e_mode
{
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
	MODE_ADAPTIVE,
	MODE_BENCH
}   t_mode;

int	parse_flags(int ac, char **av, t_mode *mode, int *first_num_i);

void	ops_init(t_ops *ops);

/* strategy prototypes (stubs implemented while algorithms are developed) */
void	simple_min_extract(t_node **a, t_node **b, t_ops *ops);
void	chunk_sort(t_node **a, t_node **b, t_ops *ops);
void	radix_sort(t_node **a, t_node **b, t_ops *ops);
void	adaptive_sort(t_node **a, t_node **b, t_ops *ops);

/* operations */
void	sa(t_node **a, t_ops *ops);
void	sb(t_node **b, t_ops *ops);
void	ss(t_node **a, t_node **b, t_ops *ops);
void	pa(t_node **a, t_node **b, t_ops *ops);
void	pb(t_node **a, t_node **b, t_ops *ops);
void	ra(t_node **a, t_ops *ops);
void	rb(t_node **b, t_ops *ops);
void	rr(t_node **a, t_node **b, t_ops *ops);
void	rra(t_node **a, t_ops *ops);
void	rrb(t_node **b, t_ops *ops);
void	rrr(t_node **a, t_node **b, t_ops *ops);
void	swap_core(t_node **s);
void	push_core(t_node **dst, t_node **src);

void	sort(t_node **a, t_node **b, t_ops *ops, int mode);
void	sort_3(t_node **a, t_ops *ops);
void	sort_5(t_node **a, t_node **b, t_ops *ops);
void	swap_core(t_node **s);
void	push_core(t_node **from, t_node **to);
void	rotate_core(t_node **s);
void	rev_rotate_core(t_node **s);
#endif