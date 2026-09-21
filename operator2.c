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

void	ra(t_node **a, t_ops *ops)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate_core(a);
	if (ops)
	{
		ops->ra++;
		ops->total++;
	}
	write(1, "ra\n", 3);
}

void	rb(t_node **b, t_ops *ops)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate_core(b);
	if (ops)
	{
		ops->rb++;
		ops->total++;
	}
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, t_ops *ops)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	rotate_core(a);
	rotate_core(b);
	if (ops)
	{
		ops->rr++;
		ops->total++;
	}
	write(1, "rr\n", 3);
}
