/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:45:25 by tmeqdad           #+#    #+#             */
/*   Updated: 2025/11/28 20:39:38 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*ss;
	char	*last;

	ch = (char)c;
	ss = (char *)s;
	last = NULL;
	i = 0;
	while (ss[i] != '\0')
	{
		if (ss[i] == ch)
			last = (ss + i);
		i++;
	}
	if (ch == '\0')
		return (ss + i);
	return (last);
}
