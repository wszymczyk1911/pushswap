/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:13:45 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/03 16:54:57 by wikszymc         ###   ########.fr       */
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

void	sort_simple(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	int	i;
	int	idx;

	i = size - 3;
	if (size <= 3)
	{
		sort_little(a, ops, size);
		return ;
	}
	while (i > 0)//push b dopoki nie zostana tylko 3 nody w stack a
	{
		ft_pb(a, b, ops);
		i--;
	}
//	print_stack(a);
	sort_three(a, ops);
//	print_stack(a);
	while (*b != NULL)
	{
		idx = find_bigger(*a, *b);
		if (idx == -1)
			idx = find_smallest(*a);
		while ((*a)->index != idx)
			ft_ra(a, ops, 0);
		ft_pa(a, b, ops);
//		print_stack(a);
	}
	idx = find_smallest(*a);
	while ((*a)->index != idx)
		ft_ra(a, ops, 0);
//	print_stack(a);
	ft_printf("total operations: %d\n", (*ops)->total);
}
