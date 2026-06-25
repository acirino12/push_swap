/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:53:26 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:15:20 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_pntr;
	unsigned char	*src_pntr;
	size_t			i;

	dst_pntr = (unsigned char *)dst;
	src_pntr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_pntr[i] = src_pntr[i];
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>

int main()
{
	char str[20] = "Hello, World!";
	ft_memcpy(str + 7, str, 14);
	printf("%s\n", str); // Output: "Hello, Hello, Hello,"
	return 0;
}
	// We'll solve this problem in memmove.
*/
