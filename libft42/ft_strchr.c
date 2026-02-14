/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:20:09 by tmeqdad           #+#    #+#             */
/*   Updated: 2025/11/28 20:39:05 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*ss;

	ch = (char)c;
	ss = (char *)s;
	i = 0;
	while (ss[i] != '\0')
	{
		if (ss[i] == ch)
			return (ss + i);
		i++;
	}
	if (ch == '\0')
		return (ss + i);
	return (NULL);
}
