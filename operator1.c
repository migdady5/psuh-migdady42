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
	if (!a || !*a || !(*a)->next)
		return ;
	swap_core(a);
	if (ops)
	{
		ops->sa++;
		ops->total++;
	}
	write(1, "sa\n", 3);
}

void	sb(t_node **b, t_ops *ops)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap_core(b);
	if (ops)
	{
		ops->sb++;
		ops->total++;
	}
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, t_ops *ops)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	swap_core(a);
	swap_core(b);
	if (ops)
	{
		ops->ss++;
		ops->total++;
	}
	write(1, "ss\n", 3);
}

void	pa(t_node **a, t_node **b, t_ops *ops)
{
	if (!a || !b || !*b)
		return ;
	push_core(a, b);
	if (ops)
	{
		ops->pa++;
		ops->total++;
	}
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, t_ops *ops)
{
	if (!b || !a || !*a)
		return ;
	push_core(b, a);
	if (ops)
	{
		ops->pb++;
		ops->total++;
	}
	write(1, "pb\n", 3);
}
