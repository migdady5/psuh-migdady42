/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <tmeqdad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 09:15:35 by tmeqdad           #+#    #+#             */
/*   Updated: 2025/11/30 09:47:52 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s);
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s, len + 1);
	return (s2);
}
