/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:17:34 by amigdadi          #+#    #+#             */
/*   Updated: 2026/02/26 20:56:18 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	pos_min(t_node *a)
{
	int	pos;
	int	i;
	int	min;

	pos = 0;
	i = 0;
	min = a->data;
	while (a)
	{
		if (a->data < min)
		{
			min = a->data;
			pos = i;
		}
		i++;
		a = a->next;
	}
	return (pos);
}

static void	bring_min_to_top(t_node **a, t_ops *ops)
{
	int	pos;
	int	n;

	n = stack_size(*a);
	pos = pos_min(*a);
	if (pos <= n / 2)
	{
		while (pos-- > 0)
			ra(a, ops);
	}
	else
	{
		while (pos++ < n)
			rra(a, ops);
	}
}

void	sort_5(t_node **a, t_node **b, t_ops *ops)
{
	int	n;

	n = stack_size(*a);
	while (n > 3)
	{
		bring_min_to_top(a, ops);
		pb(a, b, ops);
		n--;
	}
	sort_3(a, ops);
	while (*b)
		pa(a, b, ops);
	if ((*a)->data > (*a)->next->data)
		sa(a, ops);
}