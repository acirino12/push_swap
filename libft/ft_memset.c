/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:54:09 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:15:26 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pntr;

	pntr = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		pntr[i] = (unsigned char) c;
		i = i + 1;
	}
	return (b);
}

/*
#include <stdio.h>

int main(void)
{
	int n;
	char c;

	n = 0;
	c = 1;
	ft_memset(&n, c, sizeof(int));
	printf("%i\n", n);
}	
	// Expected output: 16.843.009, 
	// that is 0001 0001 0001 0001 in binary
*/
