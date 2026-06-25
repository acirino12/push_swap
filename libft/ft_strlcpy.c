/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:01:09 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:16:08 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include <stdio.h>

int main(void)
{
    char buffer[5];
    const char *string = "HELLO";

    // If we try to copy "HELLO" into buffer, 
	// we fail because it can only hold 4 characters + 1 null terminator
    // The expected output is "HELL" followed by a null terminator
    printf("Space needed: %ld \n", ft_strlcpy(buffer, string, sizeof(buffer)));
    //
    // Note: sizeof(buffer) is 5 but sizeof(string) is always 8 
	// (This is an exception for array!)
    // 
    printf("String copied: %s\n", buffer);
    return (0);
}
*/
