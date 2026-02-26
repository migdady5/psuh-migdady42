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

static void	rotate_op(t_node **s)
{
	t_node	*tmp;
	t_node	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	tmp = *s;
	*s = (*s)->next;
	tmp->next = NULL;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	ra(t_node **a)
{
	rotate_op(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate_op(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate_op(a);
	rotate_op(b);
	write(1, "rr\n", 3);
}