/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:03:01 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/20 10:17:30 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

t_stack	*pop_top(t_stack **stack)
{
	t_stack	*current;

	if (stack == NULL || *stack == NULL)
		return (NULL);
	current = *stack;
	if (current->next == NULL)
		*stack = NULL;
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	current->prev = NULL;
	current->next = NULL;
	return (current);
}

void	push_ontop(t_stack **stack, t_stack *node)
{
	if (stack == NULL)
		return ;
	if (*stack != NULL)
	{
		node->next = *stack;
		(*stack)->prev = node;
	}
	*stack = node;
}
