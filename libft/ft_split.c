/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:56:27 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:15:46 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c);
static char		*worddup(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t		n;
	size_t		i;
	char		**buffer;
	char const	*start;

	start = s;
	n = word_count(s, c);
	buffer = (char **)malloc(sizeof(char *) * (n + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*s != c && (s == start || *(s - 1) == c))
		{
			buffer[i] = worddup(s, c);
			i += 1;
		}
		s += 1;
	}
	buffer[i] = NULL;
	return (buffer);
}

static size_t	word_count(char const *s, char c)
{
	size_t		n;
	char const	*start;

	start = s;
	n = 0;
	while (*s)
	{
		if (*s != c && (s == start || *(s - 1) == c))
			n += 1;
		s += 1;
	}
	return (n);
}

static char	*worddup(char const *s, char c)
{
	char	*word;
	size_t	n;

	n = 0;
	while (s[n] && s[n] != c)
		n++;
	word = (char *)malloc(sizeof(char) * (n + 1));
	if (word)
		ft_strlcpy(word, s, (n + 1));
	return (word);
}
