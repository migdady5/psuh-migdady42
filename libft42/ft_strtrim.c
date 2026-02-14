/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <tmeqdad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:05:26 by tmeqdad           #+#    #+#             */
/*   Updated: 2025/12/03 12:44:55 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (start == end)
		return (ft_strdup(""));
	end--;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	res = (char *)malloc(sizeof(char) *(len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1 + start, len);
	res[len] = '\0';
	return (res);
}
