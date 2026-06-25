/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:04:44 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:16:35 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!len || start > s_len)
		return (ft_strdup(""));
	if (len + start > s_len)
		buffer = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (buffer)
		ft_strlcpy(buffer, s + start, len + 1);
	return (buffer);
}

// Edge cases: start > str_len -> nothing to copy
//         AND len + start > str_len -> the risk is to allocate more memory
