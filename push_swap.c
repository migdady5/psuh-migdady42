/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:28:04 by amigdadi          #+#    #+#             */
/*   Updated: 2026/03/07 00:00:00 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

typedef struct s_state
{
	t_ops	ops;
	t_node	*a;
	t_node	*b;
	int		count;
}t_state;

static void	mode_meta(t_mode mode, const char **strategy, const char **complexity)
{
	if (mode == MODE_SIMPLE)
	{
		*strategy = "Simple";
		*complexity = "O(n^2)";
	}
	else if (mode == MODE_MEDIUM)
	{
		*strategy = "Medium";
		*complexity = "O(n*sqrt(n))";
	}
	else
	{
		*strategy = "Complex";
		*complexity = "O(n log n)";
	}
}

static void	bench_meta(t_config cfg, double disorder, const char **strategy,
		const char **complexity)
{
	if (cfg.mode != MODE_ADAPTIVE)
	{
		mode_meta(cfg.mode, strategy, complexity);
		return ;
	}
	*strategy = "Adaptive";
	if (disorder < 0.2)
		*complexity = "O(n)";
	else if (disorder < 0.5)
		*complexity = "O(n*sqrt(n))";
	else
		*complexity = "O(n log n)";
}

static void	build_input(int ac, char **av, t_config *cfg, t_state *st)
{
	char	**tokens;
	int		*arr;

	if (!parse_flags(ac, av, cfg, &st->count))
		error_exit();
	tokens = collect_tokens(ac, av, st->count, &st->count);
	if (!tokens)
		error_exit();
	arr = validate_and_parse(tokens, &st->count);
	free_tokens_partial(tokens, st->count);
	if (!arr)
		error_exit();
	st->a = build_stack_a(arr, st->count);
	free(arr);
	if (!st->a)
		error_exit();
}

static void	run_sorting(t_state *st, t_config cfg)
{
	index_stack(st->a);
	if (!is_sorted(st->a))
		sort(&st->a, &st->b, &st->ops, cfg.mode);
}

int	main(int ac, char **av)
{
	t_state		st;
	t_config	cfg;
	double		disorder;
	const char	*strategy;
	const char	*complexity;

	if (ac < 2)
		return (0);
	ops_init(&st.ops);
	st.a = NULL;
	st.b = NULL;
	build_input(ac, av, &cfg, &st);
	disorder = compute_disorder(st.a);
	run_sorting(&st, cfg);
	if (cfg.bench)
	{
		bench_meta(cfg, disorder, &strategy, &complexity);
		print_bench(&st.ops, disorder, strategy, complexity);
	}
	free_stack(st.a);
	free_stack(st.b);
	return (0);
}
