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

static void	rev_rotate_op(t_node **s)
{
	t_node	*tmp;
	t_node	*second_last;

	if (!s || !*s || !(*s)->next)
		return ;
	second_last = *s;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	tmp = second_last->next;
	second_last->next = NULL;
	tmp->next = *s;
	*s = tmp;
}

void	rra(t_node **a)
{
	rev_rotate_op(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rev_rotate_op(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate_op(a);
	rev_rotate_op(b);
	write(1, "rrr\n", 4);
}
