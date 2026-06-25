/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:05:14 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:16:20 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while ((*p1 || *p2) && n)
	{
		if (*p1 == *p2)
		{
			p1 = p1 + 1;
			p2 = p2 + 1;
			n--;
		}
		else
			return (*p1 - *p2);
	}
	return (0);
}

// NOTE: The comparison is done using unsigned characters.
