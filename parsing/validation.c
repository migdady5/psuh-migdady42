/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:58:02 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/02/11 17:58:02 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	fill_number(char **tokens, int *arr, int n)
{
	int	i;
	int	value;

	i = 0;
	while (i < n)
	{
		if (!atoi_strict(tokens[i], &value))
			return (0);
		arr[i] = value;
		i++;
	}
	return (1);
}

int	check_duplicates(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*validate_and_parse(char **tokens, int *out)
{
	int	n;
	int	*arr;

	n = *out;
	if (n <= 0)
		return (NULL);
	arr = malloc(sizeof(int) * n);
	if (!arr)
		return (NULL);
	if (!fill_number(tokens, arr, n))
	{
		free(arr);
		return (NULL);
	}
	if (check_duplicates(arr, n))
	{
		free (arr);
		return (NULL);
	}
	return (arr);
}
