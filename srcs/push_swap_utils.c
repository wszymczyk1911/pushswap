/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 07:19:04 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/03 14:34:17 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

void	assign_index(t_stack **stack)
{
	t_stack	*i;
	t_stack	*j;
	int	idx;

	i = *stack;
	while (i != NULL)
	{
		idx = 0;
		j = *stack;
		while (j != NULL)
		{
			if (j->value < i->value)
				idx++;
			j = j->next;
		}
		i->index = idx;
		i = i->next;
	}
}

void	create_ops(t_counts **ops)
{
	t_counts	*node;

	node = malloc(sizeof(t_counts));
	if (!node)
		return ;
	node->sa = 0;
        node->sb = 0;
        node->ss = 0;
        node->pa = 0;
        node->pb = 0;
        node->ra = 0;
        node->rb = 0;
        node->rr = 0;
        node->rra = 0;
        node->rrb = 0;
        node->rrr = 0;
        node->total = 0;
	*ops = node;
}

double	compute_disorder(t_stack **stack)
{
	t_stack	*i;
	t_stack	*j;
	double	mistakes;
	double	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = *stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs++;
			if (j->value < i->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total_pairs);
}
