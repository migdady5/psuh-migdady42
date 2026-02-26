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
char	**collect_tokens(int ac, char **av, int *out_count);
int		count_total_tokens(int ac, char **av);
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

/* operations */
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif