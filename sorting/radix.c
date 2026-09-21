/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:56:00 by amigdadi          #+#    #+#             */
/*   Updated: 2026/03/07 19:10:02 by amigdadi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_node **a, t_node **b, t_ops *ops)
{
	int	n;
	int	bits;
	int	i;
	int	j;

	n = stack_size(*a);
	bits = max_bits(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < n)
		{
			if (((*a)->index >> i) & 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			j++;
		}
		while (*b)
			pa(a, b, ops);
		i++;
	}
}
