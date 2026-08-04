/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 22:25:08 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/02 10:38:13 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*extract_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

void	free_words(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		nwords;
	int		i;

	nwords = count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (words == NULL)
		return (NULL);
	i = 0;
	while (i < nwords)
	{
		while (*s == c)
			s++;
		words[i] = extract_word(s, c);
		if (words[i] == NULL)
		{
			free_words(words, i);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	words[i] = NULL;
	return (words);
}
