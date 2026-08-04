/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:04:29 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/02 07:35:41 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	check_stack2(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current != NULL)
	{
		if (!(current->value >= 48 && current->value <= 57))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack);
			exit(1);
		}
		if (current->value > INT_MAX || current->value < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack);
			exit(1);
		}
		current = current->next;
	}
}

void	check_stack(t_stack **stack)
{
	t_stack	*i;
	t_stack	*current;

	current = *stack;
	while (current != NULL)
	{
		i = *stack;
		while (i != NULL)
		{
			if (i->value == current->value)
			{
				ft_putstr_fd("Error\n", 2);
				free_stack(stack);
				exit(1);
			}
			i = i->next;
		}
		current = current->next;
	}
	check_stack2(stack);
}
