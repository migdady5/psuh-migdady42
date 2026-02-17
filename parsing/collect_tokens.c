/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:55:02 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/02/17 13:17:43 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_total_tokens(int ac, char **av)
{
	int		i;
	int		total;

	total = 0;
	i = 1;
	while (i < ac)
	{
		total += count_words(av[i]);
		i++;
	}
	return (total);
}

char	**collect_tokens(int ac, char **av, int *arr)
{
	char	**tokens;
	int		i;
	int		j;
	int		k;

	*arr = count_total_tokens(ac, av);
	if (*arr == 0)
		return (NULL);
	tokens = malloc(sizeof(char *) * (*arr + 1));
	if (!tokens)
		return (NULL);
	i = 1;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (!av[i][j])
				break ;
			tokens[k] = copy_word(av[i], &j);
			if (!tokens[k])
				return (free_tokens_partial(tokens, k), NULL);
			k++;
		}
		i++;
	}
	tokens[k] = NULL;
	return (tokens);
}
