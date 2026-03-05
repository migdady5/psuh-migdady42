/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@local>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:56:30 by copilot           #+#    #+#             */
/*   Updated: 2026/03/05 00:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	adaptive_sort(t_node **a, t_node **b, t_ops *ops)
{
	double	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		simple_min_extract(a, b, ops);
	else if (disorder < 0.5)
		chunk_sort(a, b, ops);
	else
		radix_sort(a, b, ops);
}
