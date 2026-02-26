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

static void	swap_op(t_node **s)
{
	t_node	*tmp;

	if (!s || !*s || !(*s)->next)
		return ;
	tmp = (*s)->next;
	(*s)->next = tmp->next;
	tmp->next = *s;
	*s = tmp;
}

void	sa(t_node **a)
{
	swap_op(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap_op(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap_op(a);
	swap_op(b);
	write(1, "ss\n", 3);
}

static void	push_op(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_node **a, t_node **b)
{
	push_op(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push_op(a, b);
	write(1, "pb\n", 3);
}