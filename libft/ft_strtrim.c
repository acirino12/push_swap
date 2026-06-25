/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:05:54 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 19:20:38 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (in_set(s1[start], set) && start < len)
		start += 1;
	end = len - 1;
	while (in_set(s1[end], set) && end >= start)
		end -= 1;
	if (!(end >= start))
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}

static size_t	in_set(char c, char const *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (c == *set)
			return (1);
		set += 1;
	}
	return (0);
}
