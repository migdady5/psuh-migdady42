/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:08:40 by amigdadi          #+#    #+#             */
/*   Updated: 2026/03/07 19:12:06 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	bench_meta(t_config cfg, double disorder, const char **strategy,
	const char **complexity)
{
	if (cfg.mode == MODE_SIMPLE)
		*strategy = "Simple";
	else if (cfg.mode == MODE_MEDIUM)
		*strategy = "Medium";
	else if (cfg.mode == MODE_COMPLEX)
		*strategy = "Complex";
	else
		*strategy = "Adaptive";
	if (cfg.mode == MODE_SIMPLE)
		*complexity = "O(n^2)";
	else if (cfg.mode == MODE_MEDIUM || (cfg.mode == MODE_ADAPTIVE
			&& disorder < 0.5 && disorder >= 0.2))
		*complexity = "O(n*sqrt(n))";
	else if (cfg.mode == MODE_ADAPTIVE && disorder < 0.2)
		*complexity = "O(n)";
	else
		*complexity = "O(n log n)";
}

static int	parse_input(int ac, char **av, t_run *r)
{
	if (!parse_flags(ac, av, &r->cfg, &r->count))
		return (0);
	r->tokens = collect_tokens(ac, av, r->count, &r->count);
	if (!r->tokens)
		return (0);
	r->arr = validate_and_parse(r->tokens, &r->count);
	free_tokens_partial(r->tokens, r->count);
	if (!r->arr)
		return (0);
	r->a = build_stack_a(r->arr, r->count);
	free(r->arr);
	if (!r->a)
		return (0);
	return (1);
}

static void	run_sort(t_run *r)
{
	const char	*strategy;
	const char	*complexity;

	index_stack(r->a);
	r->disorder = compute_disorder(r->a);
	if (!is_sorted(r->a))
		sort(&r->a, &r->b, &r->ops, r->cfg.mode);
	if (r->cfg.bench)
	{
		bench_meta(r->cfg, r->disorder, &strategy, &complexity);
		print_bench(&r->ops, r->disorder, strategy, complexity);
	}
}

int	main(int ac, char **av)
{
	t_run	r;

	if (ac < 2)
		return (0);
	ops_init(&r.ops);
	r.a = NULL;
	r.b = NULL;
	r.arr = NULL;
	r.tokens = NULL;
	if (!parse_input(ac, av, &r))
		error_exit();
	run_sort(&r);
	free_stack(r.a);
	free_stack(r.b);
	return (0);
}
