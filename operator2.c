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
	if (ops)
	{
		ops->ra++;
		ops->total++;
	}
	rotate_core(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b, t_ops *ops)
{
	if (ops)
	{
		ops->rb++;
		ops->total++;
	}
	rotate_core(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, t_ops *ops)
{
	if (ops)
	{
		ops->rr++;
		ops->total++;
	}
	rotate_core(a);
	rotate_core(b);
	write(1, "rr\n", 3);
}