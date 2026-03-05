/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:28:04 by amigdadi          #+#    #+#             */
/*   Updated: 2026/03/05 00:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	put_long_fd(long n, int fd)
{
	if (n >= 10)
		put_long_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

static void	put_percent_2(double val)
{
	long	scaled;

	scaled = (long)(val * 100.0 + 0.5);
	put_long_fd(scaled / 100, 2);
	ft_putchar_fd('.', 2);
	ft_putchar_fd(((scaled / 10) % 10) + '0', 2);
	ft_putchar_fd((scaled % 10) + '0', 2);
}

static void	bench_strategy(t_config cfg, double disorder)
{
	if (cfg.mode == MODE_SIMPLE)
		ft_putstr_fd("[bench] strategy: Simple / O(n^2)\n", 2);
	else if (cfg.mode == MODE_MEDIUM)
		ft_putstr_fd("[bench] strategy: Medium / O(n*sqrt(n))\n", 2);
	else if (cfg.mode == MODE_COMPLEX)
		ft_putstr_fd("[bench] strategy: Complex / O(n log n)\n", 2);
	else if (disorder < 0.2)
		ft_putstr_fd("[bench] strategy: Adaptive / O(n)\n", 2);
	else if (disorder < 0.5)
		ft_putstr_fd("[bench] strategy: Adaptive / O(n*sqrt(n))\n", 2);
	else
		ft_putstr_fd("[bench] strategy: Adaptive / O(n log n)\n", 2);
}

static void	print_bench(t_config cfg, t_ops *ops, double disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_percent_2(disorder * 100.0);
	ft_putstr_fd("%\n", 2);
	bench_strategy(cfg, disorder);
	ft_putstr_fd("[bench] total_ops: ", 2);
	put_long_fd(ops->total, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] sa: ", 2);
	put_long_fd(ops->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	put_long_fd(ops->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	put_long_fd(ops->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	put_long_fd(ops->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	put_long_fd(ops->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	put_long_fd(ops->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	put_long_fd(ops->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	put_long_fd(ops->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	put_long_fd(ops->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	put_long_fd(ops->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	put_long_fd(ops->rrr, 2);
	ft_putstr_fd("\n", 2);
}

int	main(int ac, char **av)
{
	t_ops		ops;
	t_node		*a;
	t_node		*b;
	t_config	cfg;
	int			*arr;
	char		**tokens;
	int			count;
	double		disorder;

	if (ac < 2)
		return (0);
	ops_init(&ops);
	a = NULL;
	b = NULL;
	if (!parse_flags(ac, av, &cfg, &count))
		error_exit();
	tokens = collect_tokens(ac, av, count, &count);
	if (!tokens)
		error_exit();
	arr = validate_and_parse(tokens, &count);
	free_tokens_partial(tokens, count);
	if (!arr)
		error_exit();
	a = build_stack_a(arr, count);
	free(arr);
	if (!a)
		error_exit();
	index_stack(a);
	disorder = compute_disorder(a);
	if (!is_sorted(a))
		sort(&a, &b, &ops, cfg.mode);
	if (cfg.bench)
		print_bench(cfg, &ops, disorder);
	free_stack(a);
	free_stack(b);
	return (0);
}
