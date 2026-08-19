/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:18:53 by djuja             #+#    #+#             */
/*   Updated: 2026/08/14 12:20:36 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	read_loop(char **tmp, int *index, int fd)
{
	int		ret_read;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	ret_read = 0;
	while (check_for_line(*tmp, (*index - ret_read)) == 0)
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		if (ret_read <= 0)
			break ;
		buf[ret_read] = '\0';
		*tmp = join_strings(*tmp, buf, index, ret_read);
	}
	free(buf);
	if (ret_read < 0 || (ret_read == 0 && (*tmp)[0] == '\0'))
	{
		free(*tmp);
		*tmp = NULL;
		return (-1);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*tmp;
	static int	index;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (tmp == NULL)
	{
		tmp = malloc(1);
		if (tmp == NULL)
			return (NULL);
		tmp[0] = '\0';
		index = 0;
	}
	if (read_loop(&tmp, &index, fd) == -1)
		return (NULL);
	new_line = ft_new_line(tmp);
	tmp = cut_rest(tmp, str_len(new_line), &index);
	return (new_line);
}
// #include <stdio.h>
// int main(void)
// {
// 	char *bufer;
// 	int fd = open("test.txt", O_RDONLY);

// 		bufer = get_next_line(fd);
// 		printf("%s", bufer);
// 		free (bufer);
// 		bufer = get_next_line(fd);
// 		printf("%s", bufer);
// 		free (bufer);
// 		bufer = get_next_line(fd);
// 		printf("%s", bufer);
// 		free (bufer);
// 		bufer = NULL;

// }
