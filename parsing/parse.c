/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:30:24 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/03/05 00:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	atoi_strict(const char *str, int *out)
{
	long	res;
	int		sign;
	int		i;

	if (!str || !str[0])
		return (0);
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	res = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = (res * 10) + (str[i] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && (-res) < INT_MIN))
			return (0);
		i++;
	}
	*out = (int)(res * sign);
	return (1);
}
