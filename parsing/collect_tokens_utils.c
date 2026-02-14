/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_tokens_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:31:18 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/02/14 22:31:18 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_tokens_partial(char **tokens, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	count_words(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (count);
}

char	*copy_word(char *s, int *i)
{
	int		start;
	int		len;
	char	*word;

	start = *i;
	len = 0;
	while (s[*i] && s[*i] != ' ')
	{
		len++;
		(*i)++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s + start, len);
	word[len] = '\0';
	return (word);
}
