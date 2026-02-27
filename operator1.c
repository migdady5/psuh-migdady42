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

void	sa(t_node **a, t_ops *ops)
{
	if (ops)
	{
		ops->sa++;
		ops->total++;
	}
	swap_core(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b, t_ops *ops)
{
	if (ops)
	{
		ops->sb++;
		ops->total++;
	}
	swap_core(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, t_ops *ops)
{
	if (ops)
	{
		ops->ss++;
		ops->total++;
	}
	swap_core(a);
	swap_core(b);
	write(1, "ss\n", 3);
}

void	pa(t_node **a, t_node **b, t_ops *ops)
{
	if (ops)
	{
		ops->pa++;
		ops->total++;
	}
	push_core(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, t_ops *ops)
{
	if (ops)
	{
		ops->pb++;
		ops->total++;
	}
	push_core(b, a);
	write(1, "pb\n", 3);
}