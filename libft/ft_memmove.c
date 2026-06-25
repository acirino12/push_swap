/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:53:46 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:15:23 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_pntr;
	unsigned char	*src_pntr;
	size_t			i;

	dst_pntr = (unsigned char *)dst;
	src_pntr = (unsigned char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			dst_pntr[i] = src_pntr[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = len;
		while (i--)
			dst_pntr[i] = src_pntr[i];
	}
	return (dst);
}

/*
#include <stdio.h>

int main()
{
	char str[20] = "Hello, World!";
	ft_memmove(str + 7, str, 14);
	printf("%s\n", str); // Output: "Hello, Hello, World!"
	ft_memmove(str, str + 7, 14);
	printf("%s\n", str); // Output: "Hello, World!"
	return 0;
}
*/
