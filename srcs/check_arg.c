/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:28:33 by djuja             #+#    #+#             */
/*   Updated: 2026/08/21 21:07:20 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	put_error(t_check_arg *conditions)
{
	ft_putstr_fd("Error\n", 2);
	free(conditions);
	exit (1);
}

int	check_invalid_arg(char *argv, t_check_arg *conditions)
{
	int	i;

	i = 0;
	if (argv == NULL || argv[i] == '\0')
		put_error(conditions);
	while (argv[i] == ' ')
		i++;
	if (argv[i] == '\0')
		return (0);
	i = 0;
	while (argv[i])
	{
		if ((argv[i] >= '0' && argv[i] <= '9') || argv[i] == ' ')
			i++;
		else if ((argv[i] == '-' || argv[i] == '+')
			&& (argv[i + 1] >= '0' && argv[i + 1] <= '9')
			&& (i == 0 || argv[i - 1] == ' '))
			i++;
		else
			return (0);
	}
	return (1);
}

t_check_arg	*make_string_of_numbers(char *argv, t_check_arg *conditions)
{
	char	*sep;
	char	*tmp;

	tmp = NULL;
	sep = ft_strdup(" ");
	if (check_invalid_arg(argv, conditions) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free(conditions);
		exit (1);
	}
	else if (argv[0] == '\0')
		return (conditions);
	else
	{
		tmp = conditions->str;
		tmp = ft_strjoin(tmp, sep);
		conditions->str = ft_strjoin(tmp, argv);
	}
	return (free(sep), conditions);
}

int	check_for_flag(char *argv, t_check_arg *conditions, int *number_of_flags)
{
	if (ft_strncmp(argv, "--simple", 9) == 0)
	{
		conditions->strategy = SIMPLE;
		*number_of_flags += 1;
		return (1);
	}
	else if (ft_strncmp(argv, "--medium", 9) == 0)
	{
		conditions->strategy = MEDIUM;
		*number_of_flags += 1;
		return (1);
	}
	else if (ft_strncmp(argv, "--complex", 10) == 0)
	{
		conditions->strategy = COMPLEX;
		*number_of_flags += 1;
		return (1);
	}
	else if (ft_strncmp(argv, "--bench", 8) == 0)
	{
		conditions->bench = 1;
		return (1);
	}
	return (0);
}

t_check_arg	*check_arg(char **argv, int argc)
{
	t_check_arg	*conditions;
	int			i;
	int			number_of_flags;

	conditions = malloc(sizeof(t_check_arg));
	if (conditions == NULL)
		return (NULL);
	i = 1;
	conditions->bench = 0;
	conditions->strategy = 0;
	number_of_flags = 0;
	conditions->str = NULL;
	while (i < argc)
	{
		if (!check_for_flag(argv[i], conditions, &number_of_flags)
			&& !make_string_of_numbers(argv[i], conditions))
			put_error(conditions);
		i++;
	}
	if (number_of_flags > 1)
		put_error(conditions);
	return (conditions);
}
