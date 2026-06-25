/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:05:39 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:16:27 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	l;

	l = ft_strlen(s) + 1;
	while (l)
	{
		l--;
		if (s[l] == (char)c)
		{
			return ((char *)(s + l));
		}
	}
	return (NULL);
}

// NOTE: The terminating null byte is considered part of the string

/*
#include <stdio.h>

int main(void)
{
    char str[] = "ohello";
    char *result = ft_strrchr(str, 'o');
    if (result)
        printf("Character found at position: %ld\n", result - str);
    else
        printf("Character not found.\n");
    return 0;
}
*/
