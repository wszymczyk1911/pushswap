/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:07:03 by djuja             #+#    #+#             */
/*   Updated: 2026/08/10 21:09:24 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	str_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*join_strings(char *tmp, char *buf, int *index, int ret_read)
{
	char			*new_string;
	int				j;
	int				i;

	if (tmp == NULL || buf == NULL)
		return (NULL);
	new_string = malloc(sizeof(char) * (*index + ret_read + 1));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (tmp[i])
		new_string[j++] = tmp[i++];
	i = 0;
	while (buf[i])
		new_string[j++] = buf[i++];
	new_string[j] = '\0';
	*index = j;
	free(tmp);
	return (new_string);
}

char	*ft_new_line(char *str)
{
	int				len;
	char			*new_line;
	int				i;

	if (str == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	new_line = malloc(sizeof(char) * (len + 2));
	if (new_line == NULL)
		return (NULL);
	while (i <= len)
	{
		new_line[i] = str[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*cut_rest(char *str, unsigned int start, int *index)
{
	int				len;
	char			*tmp_rest;
	unsigned int	i;

	i = 0;
	len = 0;
	if (str == NULL)
		return (NULL);
	while (str[len + start])
		len++;
	tmp_rest = malloc (sizeof(char) * (len + 1));
	if (tmp_rest == NULL)
		return (NULL);
	while (str[start])
	{
		tmp_rest[i] = str[start];
		i++;
		start++;
	}
	tmp_rest[i] = '\0';
	*index = len;
	free (str);
	return (tmp_rest);
}

int	check_for_line(char *buf, int to_read)
{
	while (buf[to_read])
	{
		if (buf[to_read] == '\n')
			return (1);
		to_read++;
	}
	return (0);
}
