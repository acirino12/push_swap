/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:55:44 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:15:38 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = (-1) * n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = '0';
	c = c + n % 10;
	if (c == 40)
		write(fd, "2147483648", 10);
	else
		write(fd, &c, 1);
}

// Note:
// (-1) * min_int = min_int
// min_int % 10 = -8 AND '0' = 48
