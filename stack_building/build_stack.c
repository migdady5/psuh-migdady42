/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:40:23 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/02/15 20:40:23 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*build_stack_a(int *arr, int n)
{
	t_node	*head;
	t_node	*new_node;
	int		i;

	head = NULL;
	i = n - 1;
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		new_node->data = arr[i];
		new_node->next = head;
		head = new_node;
		i--;
	}
	return (head);
}
