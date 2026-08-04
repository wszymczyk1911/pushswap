/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:03:01 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/04 12:56:43 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

static int	find_biggest(t_stack **stack)
{
	int	target_idx;
	t_stack	*current;

	target_idx = 0;
	current = *stack;
	while (current != NULL)
	{
		if (current->index > target_idx)
			target_idx = current->index;
		current = current->next;
	}
	return (target_idx);
}

void	sort_three(t_stack **a, t_counts **ops)
{
	t_stack	*current;
	int	idx;

	current = *a;
	idx = find_biggest(a);
	if (current->index == idx)
		ft_ra(a, ops, 0);
	else if (current->next->index == idx)
		ft_rra(a, ops, 0);
	current = *a;
	if (current->index > current->next->index)
		ft_sa(a, ops, 0);
}

void	sort_little(t_stack **a, t_counts **ops, int size)
{
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			ft_sa(a, ops, 0);
		return ;
	}
	else if (size == 3)
		sort_three(a, ops);
}
