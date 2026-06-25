/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:00:42 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:16:00 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	buffer = (char *)malloc(sizeof(char) * (1 + l1 + l2));
	if (buffer)
	{
		ft_strlcpy (buffer, s1, 1 + l1);
		ft_strlcat (buffer, s2, 1 + l1 + l2);
	}
	return (buffer);
}
