/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:00:00 by amigdadi          #+#    #+#             */
/*   Updated: 2026/02/26 23:05:48 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_core(t_node **s)
{
	t_node	*first;
	t_node	*second;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	push_core(t_node **dst, t_node **src)
{
	t_node	*tmp;

	if (!dst || !src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}
void	rotate_core(t_node **s)
{
	t_node	*first;
	t_node	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	first->next = NULL;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rev_rotate_core(t_node **s)
{
	t_node	*prev;
	t_node	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	prev = NULL;
	last = *s;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *s;
	*s = last;
}