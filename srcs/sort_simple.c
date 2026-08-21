/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:13:45 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/07 12:15:58 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	find_bigger(t_stack *a, t_stack *b)
{
	int	target_idx;

	target_idx = -1;
	while (a != NULL)
	{
		if (a->index > b->index)
		{
			if (a->index < target_idx || target_idx == -1)
				target_idx = a->index;
		}
		a = a->next;
	}
	return (target_idx);
}

static int	find_smallest(t_stack *a)
{
	int	smallest_idx;

	smallest_idx = INT_MAX;
	while (a != NULL)
	{
		if (a->index < smallest_idx)
			smallest_idx = a->index;
		a = a->next;
	}
	return (smallest_idx);
}

int	in_first_half(t_stack **a, int idx, int size)
{
	t_stack	*current;
	int	i;

	i = size / 2;
	current = *a;
	while (current != NULL && size >= 0)
	{
		if (current->index == idx)
			return (1);
		current = current->next;
		size--;
	}
	return (0);
}

void	sort_simple(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	int	i;
	int	idx;

	print_stack(a);
	i = size - 3;
	if (size <= 3)
	{
		sort_little(a, ops, size);
		return ;
	}
	while (i > 0)
	{
		ft_pb(a, b, ops);
		i--;
	}
	sort_three(a, ops);
	print_stack(a);
	while (*b != NULL)
	{
		ft_printf("B -> [%d] %d\n", (*b)->index, (*b)->value);
		idx = find_bigger(*a, *b);
		if (idx == -1)
			idx = find_smallest(*a);
		while ((*a)->index != idx)
		{
			if (in_first_half(a, idx, i))
				ft_ra(a, ops, 0);
			else
				ft_rra(a, ops, 0);
		}
		ft_pa(a, b, ops);
		i++;
		print_stack(a);
	}
	idx = find_smallest(*a);
	while ((*a)->index != idx)
	{
		if (in_first_half(a, idx, i))
			ft_ra(a, ops, 0);
		else
			ft_rra(a, ops, 0);
	}
}
