/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:43:51 by acirino           #+#    #+#             */
/*   Updated: 2026/05/30 22:02:01 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;
	size_t	size_max;

	size_max = (size_t)-1;
	if (nmemb != 0 && size > size_max / nmemb)
		return (NULL);
	out = malloc(nmemb * size);
	if (out != NULL)
		ft_bzero(out, nmemb * size);
	return (out);
}

// If the multiplication of nmemb and size would result in integer overflow,
//  then calloc() returns an error.
// (size_t)-1 is SIZE_MAX from <stdint.h>
