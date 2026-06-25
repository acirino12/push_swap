/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:00:57 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:16:04 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (size > 0)
	{
		while (dst[i] && i < size)
			i++;
		if (i == size)
			return (i + ft_strlen(src));
		j = 0;
		while (src[j] && i + j < size - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}

/*
#include <stdio.h>

int main (void)
{
    char buffer[10] = "Hello"; 
    // Length: 5 + 1 = 6. I can concatenate: 4 characters.
    const char *update = " mate!"; 
    // Length: 6.

    printf("Space needed: %ld \n", ft_strlcat(buffer, update, sizeof(buffer))); 
    // Returns 5 + 6 = 11. 
	// Buffer's dimension should be > than the returned value
    printf("String copied: %s\n", buffer);
    return (0);
}
*/
