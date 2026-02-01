/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:06:19 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/01/30 19:06:19 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*last;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = tmp;
	}
}

void	rb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*last;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = tmp;
	}
}

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
