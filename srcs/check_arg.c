/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:28:33 by djuja             #+#    #+#             */
/*   Updated: 2026/08/11 17:39:38 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int check_invalid_arg(char *argv)
{
	int i;

	i = 0;
	while(argv[i])
	{
		if ((argv[i] >= '0' && argv[i] <= '9') || argv[i] == '-' || argv[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

t_check_arg *make_string_of_numbers(char *argv, t_check_arg *conditions)
{
	char *sep;
	char *str;

	str = NULL;
	sep = ft_strdup(" ");
	if (check_invalid_arg(argv) == 0)
	{
			ft_putstr_fd("Error\n", 2);
			free(conditions);
			exit (1);
	}
	else
	{	
		conditions->str = ft_strjoin(conditions->str, sep);
		conditions->str = ft_strjoin(conditions->str, argv);
	}
	return(conditions);
}


t_check_arg	*check_arg(char **argv, int argc)
{
	t_check_arg *conditions;
	int i;
	int number_of_flags;

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
		if (ft_strncmp(argv[i], "--simple", ft_strlen(argv[i])) == 0)
		{
			conditions->strategy = SIMPLE;
			number_of_flags++;
		//	printf("conditions: %d\n", conditions->flag);
		}
		else if (ft_strncmp(argv[i], "--medium", ft_strlen(argv[i])) == 0)
		{
			conditions->strategy = MEDIUM;
			number_of_flags++;
		//	printf("conditions: %d\n", conditions->flag);
		}
		else if (ft_strncmp(argv[i], "--complex", ft_strlen(argv[i])) == 0)
		{
			conditions->strategy = COMPLEX;
			number_of_flags++;
		//	printf("conditions: %d\n", conditions->flag);
		}
		else if (ft_strncmp(argv[i], "--bench", ft_strlen(argv[i])) == 0)
		{
			conditions->bench = 1;
		}
		else if (make_string_of_numbers(argv[i], conditions));
		else
		{
			ft_putstr_fd("Error\n", 2);
			free(conditions);
			exit (1);
		}
		i++;
	}
	if (number_of_flags > 1)
		{
			ft_putstr_fd("Error\n", 2);
			free(conditions);
			exit (1);
		}
	return (conditions);
}

