/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:50:05 by amigdadi          #+#    #+#             */
/*   Updated: 2026/03/07 17:50:08 by amigdadi         ###   ########.fr       */
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
