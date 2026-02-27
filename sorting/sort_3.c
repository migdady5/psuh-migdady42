/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:17:25 by amigdadi          #+#    #+#             */
/*   Updated: 2026/02/26 20:55:55 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	max_of_3(t_node *a)
{
	int	x;
	int	y;
	int	z;

	x = a->data;
	y = a->next->data;
	z = a->next->next->data;
	if (x >= y && x >= z)
		return (x);
	if (y >= x && y >= z)
		return (y);
	return (z);
}

void	sort_3(t_node **a, t_ops *ops)
{
	int	mx;

	mx = max_of_3(*a);
	if ((*a)->data == mx)
		ra(a, ops);
	else if ((*a)->next->data == mx)
		rra(a, ops);
	if ((*a)->data > (*a)->next->data)
		sa(a, ops);
}