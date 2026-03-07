/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:50:36 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/03/07 00:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_max_index(t_node *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

static int	find_pos(t_node *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack && stack->index != target)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static void	bring_max_to_top(t_node **b, t_ops *ops, int max)
{
	int	pos;
	int	size;

	pos = find_pos(*b, max);
	size = stack_size(*b);
	if (pos <= size / 2)
		while ((*b)->index != max)
			rb(b, ops);
	else
		while ((*b)->index != max)
			rrb(b, ops);
}

static void	push_back_to_a(t_node **a, t_node **b, t_ops *ops)
{
	int	max;

	while (*b)
	{
		max = find_max_index(*b);
		bring_max_to_top(b, ops, max);
		pa(a, b, ops);
	}
}

static int	choose_chunks(int n)
{
	if (n <= 100)
		return (5);
	return (11);
}

static void	push_in_chunks(t_node **a, t_node **b, t_ops *ops, int n)
{
	int	chunks;
	int	chunk_size;
	int	range_max;

	chunks = choose_chunks(n);
	chunk_size = n / chunks;
	range_max = chunk_size;
	while (*a)
	{
		if ((*a)->index < range_max)
		{
			pb(a, b, ops);
			if ((*b)->index < range_max - (chunk_size / 2))
				rb(b, ops);
		}
		else
			ra(a, ops);
		if (stack_size(*b) == range_max)
			range_max += chunk_size;
	}
}

void	chunk_sort(t_node **a, t_node **b, t_ops *ops)
{
	int	n;

	if (is_sorted(*a))
		return ;
	index_stack(*a);
	n = stack_size(*a);
	push_in_chunks(a, b, ops, n);
	push_back_to_a(a, b, ops);
}
