/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 21:03:24 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/21 21:03:26 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	in_first_half(t_stack **stack, int idx, int size)
{
	t_stack	*current;
	int		i;

	i = size / 2;
	current = *stack;
	while (current != NULL && i >= 0)
	{
		if (current->index == idx)
			return (1);
		current = current->next;
		i--;
	}
	return (0);
}

void	sort_simple(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	int	i;

	i = 0;
	while (size > 3)
	{
		while ((*a)->index != i)
		{
			if (in_first_half(a, i, size))
				ft_ra(a, ops, 0);
			else
				ft_rra(a, ops, 0);
		}
		ft_pb(a, b, ops);
		size--;
		i++;
	}
	sort_three(a, ops);
	while (*b != NULL)
		ft_pa(a, b, ops);
}
