/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:33:24 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/03/06 00:00:00 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	*stack_to_array(t_node *a, int n)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * n);
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i++] = a->data;
		a = a->next;
	}
	return (arr);
}

static void	sort_array(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_index(t_node *a, int *arr, int n)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < n)
		{
			if (a->data == arr[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	index_stack(t_node *a)
{
	int	n;
	int	*arr;

	n = stack_size(a);
	arr = stack_to_array(a, n);
	if (!arr)
		return ;
	sort_array(arr, n);
	assign_index(a, arr, n);
	free(arr);
}
