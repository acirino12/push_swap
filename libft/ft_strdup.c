/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:57:21 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:15:53 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	l;

	l = ft_strlen(s);
	duplicate = malloc(sizeof(char) * (l + 1));
	if (duplicate != NULL)
		ft_strlcpy(duplicate, s, sizeof(char) * (l + 1));
	return (duplicate);
}
