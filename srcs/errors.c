/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:04:29 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/22 14:39:24 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	check_stack2(t_stack **stack, t_counts **ops, t_check_arg **input)
{
	t_stack	*current;

	current = *stack;
	while (current != NULL)
	{
		if (current->value > INT_MAX || current->value < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack);
			free((*ops));
			free((*input)->str);
			free((*input));
			exit(1);
		}
		current = current->next;
	}
}

void	check_stack(t_stack **stack, t_counts **ops, t_check_arg **input)
{
	t_stack	*i;
	t_stack	*current;

	current = *stack;
	while (current != NULL)
	{
		i = current->next;
		while (i != NULL)
		{
			if (i->value == current->value)
			{
				ft_putstr_fd("Error\n", 2);
				free_stack(stack);
				free((*ops));
				free((*input)->str);
				free((*input));
				exit(1);
			}
			i = i->next;
		}
		current = current->next;
	}
	check_stack2(stack, ops, input);
}
