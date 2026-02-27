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

void	rra(t_node **a, t_ops *ops)
{
	if (ops)
	{
		ops->rra++;
		ops->total++;
	}
	rev_rotate_core(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b, t_ops *ops)
{
	if (ops)
	{
		ops->rrb++;
		ops->total++;
	}
	rev_rotate_core(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, t_ops *ops)
{
	if (ops)
	{
		ops->rrr++;
		ops->total++;
	}
	rev_rotate_core(a);
	rev_rotate_core(b);
	write(1, "rrr\n", 4);
}