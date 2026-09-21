/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:30:24 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/03/07 19:10:45 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	parse_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	acc_digit(long *res, int sign, char c)
{
	*res = (*res * 10) + (c - '0');
	if ((sign == 1 && *res > INT_MAX) || (sign == -1 && (-*res) < INT_MIN))
		return (0);
	return (1);
}

int	atoi_strict(const char *str, int *out)
{
	long	res;
	int		sign;
	int		i;

	if (!str || !str[0])
		return (0);
	i = 0;
	sign = parse_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	res = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if (!acc_digit(&res, sign, str[i]))
			return (0);
		i++;
	}
	*out = (int)(res * sign);
	return (1);
}
