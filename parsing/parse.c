/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:30:24 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/03/07 00:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	read_sign(const char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
		{
			(*i)++;
			return (-1);
		}
		(*i)++;
	}
	return (1);
}

static int	overflow(long res, int sign)
{
	if (sign == 1 && res > INT_MAX)
		return (1);
	if (sign == -1 && (-res) < INT_MIN)
		return (1);
	return (0);
}

int	atoi_strict(const char *str, int *out)
{
	long	res;
	int		sign;
	int		i;

	if (!str || !str[0])
		return (0);
	i = 0;
	sign = read_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	res = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = (res * 10) + (str[i] - '0');
		if (overflow(res, sign))
			return (0);
		i++;
	}
	*out = (int)(res * sign);
	return (1);
}
