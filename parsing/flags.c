/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:00:00 by amigdadi          #+#    #+#             */
/*   Updated: 2026/02/26 23:38:29 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_flag(const char *s)
{
	if (!s)
		return (0);
	return (!ft_strncmp(s, "--simple", 9)
		|| !ft_strncmp(s, "--medium", 9)
		|| !ft_strncmp(s, "--complex", 10)
		|| !ft_strncmp(s, "--adaptive", 11)
		|| !ft_strncmp(s, "--bench", 8));
}

static int	set_mode(const char *s, t_mode *mode)
{
	if (!ft_strncmp(s, "--simple", 9))
		*mode = MODE_SIMPLE;
	else if (!ft_strncmp(s, "--medium", 9))
		*mode = MODE_MEDIUM;
	else if (!ft_strncmp(s, "--complex", 10))
		*mode = MODE_COMPLEX;
	else if (!ft_strncmp(s, "--adaptive", 11))
		*mode = MODE_ADAPTIVE;
	else if (!ft_strncmp(s, "--bench", 8))
		*mode = MODE_BENCH;
	else
		return (0);
	return (1);
}

int	parse_flags(int ac, char **av, t_mode *mode, int *first_num_i)
{
	int	i;

	if (!mode || !first_num_i)
		return (0);
	*mode = MODE_COMPLEX;
	i = 1;
	while (i < ac && is_flag(av[i]))
	{
		if (!set_mode(av[i], mode))
			return (0);
		i++;
	}
	*first_num_i = i;
	return (1);
}