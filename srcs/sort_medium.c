/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:59:21 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/21 21:10:10 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	ft_sqrt(int size)
{
	int	n;

	n = 0;
	while ((n * n) <= size)
	{
		if (n * n == size)
			return (n);
		n++;
	}
	return (n);
}

static int	in_chunk(int index, int start, int end)
{
	if (index >= start && index < end)
		return (1);
	return (0);
}

void	push_chunks_to_b(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	int	chunk;
	int	start;
	int	n;

	chunk = ft_sqrt(size);
	start = 0;
	while (*a != NULL)
	{
		n = 0;
		while (n < chunk && *a != NULL)
		{
			if (in_chunk((*a)->index, start, start + chunk))
			{
				ft_pb(a, b, ops);
				n++;
			}
			else
				ft_ra(a, ops, 0);
		}
		start += chunk;
	}
}

void	sort_medium(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	int	n;

	if (size <= 3)
	{
		sort_little(a, ops, size);
		return ;
	}
	push_chunks_to_b(a, b, ops, size);
	n = size - 1;
	while (*b != NULL)
	{
		if ((*b)->index == n)
		{
			ft_pa(a, b, ops);
			n--;
			size--;
		}
		else
		{
			if (in_first_half(b, n, size))
				ft_rb(b, ops, 0);
			else
				ft_rrb(b, ops, 0);
		}
	}
}
