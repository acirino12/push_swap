/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:52:02 by acirino           #+#    #+#             */
/*   Updated: 2026/05/31 08:04:00 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buffer;
	unsigned char	tofind;

	buffer = (unsigned char *)s;
	tofind = (unsigned char)c;
	while (n)
	{
		if (*buffer == tofind)
			return (buffer);
		buffer++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
    char str[] = "Hello, World!";
    char *result = ft_memchr(str, 'H', 14);
    if (result)
        printf("Character found at position: %ld\n", result - str);
    else
        printf("Character not found.\n");
    return 0;
}
*/
