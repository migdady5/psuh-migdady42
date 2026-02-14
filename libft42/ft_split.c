/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <tmeqdad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:50:45 by tmeqdad           #+#    #+#             */
/*   Updated: 2025/12/03 12:49:20 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}

void	ft_free_split(char **res, size_t k)
{
	while (k > 0)
		free(res[--k]);
	free(res);
}

static int	fill_split(char **split, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			split[k] = ft_substr(s, j, i - j);
			if (!split[k])
				return (-1);
			k++;
		}
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		k;

	if (!s)
		return (NULL);
	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	k = fill_split(split, s, c);
	if (k < 0)
		return (ft_free_split(split, k), NULL);
	split[k] = NULL;
	return (split);
}
