/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:08:28 by amigdadi          #+#    #+#             */
/*   Updated: 2026/03/07 19:08:32 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;

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
	MODE_ADAPTIVE
}	t_mode;

typedef struct s_config
{
	t_mode	mode;
	int		bench;
}	t_config;

typedef struct s_run
{
	t_ops		ops;
	t_node		*a;
	t_node		*b;
	t_config	cfg;
	int			*arr;
	char		**tokens;
	int			count;
	double		disorder;
}	t_run;

/* parsing */
void	error_exit(void);
char	**collect_tokens(int ac, char **av, int start_i, int *out_count);
int		count_total_tokens(int ac, char **av, int start_i);
int		*validate_and_parse(char **tokens, int *out);
void	free_tokens_partial(char **tokens, int count);
int		atoi_strict(const char *str, int *out);
int		check_duplicates(int *arr, int n);
int		count_words(char *s);
char	*copy_word(char *s, int *i);
int		parse_flags(int ac, char **av, t_config *cfg, int *first_num_i);

/* stacks */
t_node	*build_stack_a(int *arr, int n);
void	free_stack(t_node *stack);
void	index_stack(t_node *a);
int		is_sorted(t_node *stack);
int		stack_size(t_node *stack);
t_node	*stack_last(t_node *stack);
double	compute_disorder(t_node *a);

/* sorting */
void	sort(t_node **a, t_node **b, t_ops *ops, t_mode mode);
void	sort_3(t_node **a, t_ops *ops);
void	sort_5(t_node **a, t_node **b, t_ops *ops);
void	simple_min_extract(t_node **a, t_node **b, t_ops *ops);
void	chunk_sort(t_node **a, t_node **b, t_ops *ops);
void	radix_sort(t_node **a, t_node **b, t_ops *ops);
void	adaptive_sort(t_node **a, t_node **b, t_ops *ops);
void	print_bench(t_ops *ops, double disorder, const char *s, const char *c);

/* operations */
void	ops_init(t_ops *ops);
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
void	rotate_core(t_node **s);
void	rev_rotate_core(t_node **s);

#endif
