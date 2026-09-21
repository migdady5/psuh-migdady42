/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:08:57 by amigdadi          #+#    #+#             */
/*   Updated: 2026/03/07 19:09:02 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	put_long_fd(long n, int fd)
{
	if (n >= 10)
		put_long_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

static void	put_percent_2(double disorder)
{
	long	scaled;

	scaled = (long)(disorder * 10000.0 + 0.5);
	put_long_fd(scaled / 100, 2);
	ft_putchar_fd('.', 2);
	ft_putchar_fd(((scaled / 10) % 10) + '0', 2);
	ft_putchar_fd((scaled % 10) + '0', 2);
}

static void	print_bench_meta(double disorder, const char *s, const char *c)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_percent_2(disorder);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd((char *)s, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd((char *)c, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_bench_ops_a(t_ops *ops)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	put_long_fd(ops->total, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	put_long_fd(ops->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	put_long_fd(ops->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	put_long_fd(ops->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	put_long_fd(ops->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	put_long_fd(ops->pb, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_ops *ops, double disorder, const char *strategy,
		const char *complexity)
{
	if (!ops || !strategy || !complexity)
		return ;
	print_bench_meta(disorder, strategy, complexity);
	print_bench_ops_a(ops);
	ft_putstr_fd("[bench] ra: ", 2);
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
