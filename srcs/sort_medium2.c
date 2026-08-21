/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:59:21 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/07 12:19:46 by wikszymc         ###   ########.fr       */
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
/*
void	sort_medium(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	int	chunk_size;
	int	a_size;
	int	i;
	int	j;
	int	n;

	if (size <= 3)
	{
		sort_little(a, ops, size);
		return ;
	}
	i = 0;
	chunk_size = ft_sqrt(size);
	n = chunk_size;
	a_size = size;
	ft_printf("A before sort:\n");
	print_stack(a);
	ft_printf("---\n");
	while (n < (size + chunk_size))
	{
		j = chunk_size + 2;
		while (j > 0)
		{
			while (!((*a)->index >= i && (*a)->index <= n))
			{
				if (in_first_half(a, i, a_size))
					ft_ra(a, ops, 0);
				else
					ft_rra(a, ops, 0);
				ft_printf("after rotating: \n");
				print_stack(a);
				ft_printf("---\n");
			}
			if ((*a)->index >= i && (*a)->index <= n)
			{
				ft_pb(a, b, ops);
				a_size--;
				j--;
			}
			ft_printf("after push b: \n");
			print_stack(a);
			ft_printf("%d <= index <= %d\n---\n", i, n);
		}
		i += chunk_size;
		n += chunk_size;
	}
	ft_printf("stack B before sort:\n");
	print_stack(b);
	ft_printf("---\n");
	i = size - 1;
	while (i >= 0 && *b != NULL)
	{
		while ((*b)->index != i)
		{
			if (in_first_half(b, i, size))
				ft_rb(b, ops, 0);
			else
				ft_rrb(b, ops, 0);
		}
		ft_pa(a, b, ops);
		size--;
		i--;
		ft_printf("sorting A:\n");
		print_stack(a);
		ft_printf("---\n");
	}
}*/

static int	in_chunk(int index, int start, int end)
{
	if (index >= start && index < end)
		return (1);
	return (0);
}

void	sort_medium(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	int	chunk;
	int	start;
	int	n;

	if (size <= 3)
	{
		sort_little(a, ops, size);
		return ;
	}
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
			else if (!(in_chunk((*a)->index, start, start + chunk)))
				ft_ra(a, ops, 0);
		}
		start += chunk;
	}
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
