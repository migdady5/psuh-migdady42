/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:30:24 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/02/12 17:30:24 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_sign(const char *str, int *i)
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

static int	parse_num(const char *str, int *i, long *num, int sign)
{
	while (str[*i])
	{
		if (!ft_isdigit(str[*i]))
			return (0);
		if (*num > (INT_MAX - (str[*i] - '0')) / 10
			|| *num < (INT_MIN + (str[*i] - '0')) / 10)
			return (0);
		*num = *num * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (1);
}

int	atoi_strict(const char *str, int *out)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	num = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	sign = get_sign(str, &i);
	if (!parse_num(str, &i, &num, sign))
		return (0);
	if (str[i] != '\0')
		return (0);
	*out = (int)(num * sign);
	return (1);
}
