/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:43:13 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/02/06 16:43:13 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// rra: reverse rotate stack A (last element becomes first)
void	rra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*second_last;

	if (*stack_a && (*stack_a)->next)
	{
		second_last = *stack_a;
		while (second_last->next && second_last->next->next)
		{
			second_last = second_last->next;
		}
		tmp = second_last->next;
		second_last->next = NULL;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

// rrb: reverse rotate stack B (last element becomes first)
void	rrb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*second_last;

	if (*stack_b && (*stack_b)->next)
	{
		second_last = *stack_b;
		while (second_last->next && second_last->next->next)
		{
			second_last = second_last->next;
		}
		tmp = second_last->next;
		second_last->next = NULL;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}

// rrr: perform rra and rrb at the same time
void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
}
