/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:50:36 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/03/07 19:10:30 by amigdadi         ###   ########.fr       */
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

static void	rotate_max_to_top(t_node **b, t_ops *ops, int max)
{
	int		pos;
	int		size;
	t_node	*tmp;

	pos = 0;
	size = stack_size(*b);
	tmp = *b;
	while (tmp->index != max)
	{
		pos++;
		tmp = tmp->next;
	}
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
		rotate_max_to_top(b, ops, max);
		pa(a, b, ops);
	}
}

static void	push_chunk_to_b(t_node **a, t_node **b, t_ops *ops, int *p)
{
	if ((*a)->index < p[0])
	{
		pb(a, b, ops);
		if ((*b)->index < p[0] - (p[1] / 2))
			rb(b, ops);
	}
	else
		ra(a, ops);
	if (stack_size(*b) == p[0])
		p[0] += p[1];
}

void	chunk_sort(t_node **a, t_node **b, t_ops *ops)
{
	int	n;
	int	chunks;
	int	chunk_size;
	int	p[2];

	if (is_sorted(*a))
		return ;
	index_stack(*a);
	n = stack_size(*a);
	chunks = 11;
	if (n <= 100)
		chunks = 5;
	chunk_size = n / chunks;
	p[0] = chunk_size;
	p[1] = chunk_size;
	while (*a)
		push_chunk_to_b(a, b, ops, p);
	push_back_to_a(a, b, ops);
}
