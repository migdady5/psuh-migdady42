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

// ra: rotate stack A up (first element becomes last)
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

// rb: rotate stack B up (first element becomes last)
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

// rr: perform ra and rb at the same time
void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
}
