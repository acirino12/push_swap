/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:45:53 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:14:32 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n);
static void		putnbr_str(int n, char *s, size_t digits);

char	*ft_itoa(int n)
{
	char	*s;
	size_t	digits;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = ft_count_digits(n);
	if (n < 0)
		digits += 1;
	s = ft_calloc(digits + 1, sizeof(char));
	if (!s)
		return (NULL);
	putnbr_str(n, s, digits);
	return (s);
}

static size_t	ft_count_digits(int n)
{
	size_t		i;

	i = 0;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void	putnbr_str(int n, char *s, size_t digits)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -1 * n;
		s[i] = '-';
	}
	while (n)
	{
		s[digits - 1 - i] = '0' + n % 10;
		n = n / 10;
		i += 1;
	}
}
