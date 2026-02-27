/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:17:14 by amigdadi          #+#    #+#             */
/*   Updated: 2026/02/26 23:56:03 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort(t_node **a, t_node **b, t_ops *ops, int mode)
{
	int	n;

	n = stack_size(*a);
	if (n <= 1 || is_sorted(*a))
		return ;
	if (n == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a, ops);
		return ;
	}
	if (n == 3)
		sort_3(a, ops);
	else if (n <= 5)
		sort_5(a, b, ops);
	else
	{
		if (mode == MODE_SIMPLE)
			simple_min_extract(a, b, ops);
		else if (mode == MODE_MEDIUM)
			chunk_sort(a, b, ops);
		else if (mode == MODE_COMPLEX)
			radix_sort(a, b, ops);
		else if (mode == MODE_ADAPTIVE)
			adaptive_sort(a, b, ops);
		else if (mode == MODE_BENCH)
			radix_sort(a, b, ops);
		else
			radix_sort(a, b, ops);
	}
}