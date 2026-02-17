/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:16:33 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/02/17 15:27:45 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//sa: swap the first two elements at the top of stack A
void	sa(t_node **stack_a)
{
	t_node	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

// sb: swap the first two elements at the top of stack B
void	sb(t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = tmp->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}

// ss: perform sa and sb at the same time
void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
}

// pa: push the top element from stack B to the top of stack A
void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

// pb: push the top element from stack A to the top of stack B
void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}
