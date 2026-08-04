/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:28:33 by djuja             #+#    #+#             */
/*   Updated: 2026/08/04 16:11:57 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
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
	number_of_flags = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", ft_strlen(argv[i])) == 0)
		{
			conditions->flag = SIMPLE;
			number_of_flags++;
		//	printf("conditions: %d\n", conditions->flag);
		}
		else if (ft_strncmp(argv[i], "--medium", ft_strlen(argv[i])) == 0)
		{
			conditions->flag = MEDIUM;
			number_of_flags++;
		//	printf("conditions: %d\n", conditions->flag);
		}
		else if (ft_strncmp(argv[i], "--complex", ft_strlen(argv[i])) == 0)
		{
			conditions->flag = COMPLEX;
			number_of_flags++;
		//	printf("conditions: %d\n", conditions->flag);
		}
		else if (ft_strncmp(argv[i], "--bench", ft_strlen(argv[i])) == 0)
		{
			conditions->bench = 1;
			printf("bench: %d\n", conditions->bench);
		}
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

/* 
	char	**args;
	int		flag;
	double	disorder;
	int 	bench; */

/* 


zwroc liste argumentow bez flag i nazwy programu */
