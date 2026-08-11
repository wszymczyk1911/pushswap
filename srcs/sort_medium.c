/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 10:03:15 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/07 13:45:21 by wikszymc         ###   ########.fr       */
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
		if ((n * n) == size)
			return (n);
		n++;
	}
	return (n);
}

static int	find_push_idx(t_stack **a, int i, int chunk, int size)
{
	t_stack	*current;
	int	smallest;
	int	biggest;
	int	max;

	smallest = 0;
	biggest = 0;
	current = *a;
	max = i + chunk;
	while (current != NULL)
	{
		if (current->index >= i && current->index < max)
		{
			if (current->index < smallest || smallest == 0)
				smallest = current->index;
			else if (current->index > biggest)
				biggest = current->index;
		}
		current = current->next;
	}
	if (smallest < -(biggest + 1 - size))
		return (smallest);
	return (biggest);
}

static int	find_dir(t_stack **stack, int push_idx, int size)
{
	t_stack *current;
	int	n;

	current = *stack;
	n = size / 2;
	while (n > 0)
	{
		if (current->index == push_idx)
			return (1);
		current = current->next;
		n--;
	}
	return (0);
	
}

void	sort_medium(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	int	chunk;
	int	i;
	int	push_idx;
	int	dir;
	int	n;
	int	size_a;

	chunk = ft_sqrt(size);
	i = 0;
	size_a = size;
	while (*a != NULL)
	{
		n = 0;
		while (n < chunk && *a != NULL)
		{
			push_idx = find_push_idx(a, i, chunk, size);
			dir = find_dir(a, push_idx, size);
			while ((*a)->index != push_idx)
			{
				if (dir == 1)
					ft_ra(a, ops, 0);
				else
					ft_rra(a, ops, 0);
			}
			ft_pb(a, b, ops);
			n++;
			size_a--;
		}
		i += chunk;
	}
	print_stack(a);
	ft_printf("-------\n");
	print_stack(b);
	i = size - 1;
	while (*b != NULL)
	{
		dir = find_dir(b, i, size);
		while ((*b)->index != i)
		{
			if (dir == 1)
				ft_rb(b, ops, 0);
			else
				ft_rrb(b, ops, 0);
		}
		ft_pa(a, b, ops);
		size--;
		i--;
	}
	print_stack(a);
	ft_printf("------\n");
	print_stack(b);
}
/*
void	sort_medium(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	int	chunk;
	int	push_idx;
	int	size_a;
	int	dir;
	int	n;
	int	i;

	if (size <= 3)
	{
		sort_little(a, ops, size);
		return ;
	}
	chunk = ft_sqrt(size);
	ft_printf("chunk: %d\n", chunk);
	i = 0;
	size_a = size;
	print_stack(a);	
	while (*a != NULL)
	{
		n = chunk;
		while (n > 0 && *a != NULL)
		{
			push_idx = find_push_idx(a, i, size_a, chunk);
			dir = find_dir(a, push_idx, size_a);
			while ((*a)->index != push_idx)
			{
				if (dir == 1)
					ft_ra(a, ops, 0);
				else
					ft_rra(a, ops, 0);
			}
			ft_pb(a, b, ops);
			size_a--;
			n--;
		}
		i += chunk;
	}
	i = size - 1;
	while (*b != NULL)
	{
		dir = find_dir(b, i, size);
		while ((*b)->index != i)
		{
			if (dir == 1)
				ft_rb(b, ops, 0);
			else
				ft_rrb(b, ops, 0);
		}
		ft_pa(a, b, ops);
		size--;
	}
}*/
