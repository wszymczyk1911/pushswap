/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:25:57 by djuja             #+#    #+#             */
/*   Updated: 2026/08/14 19:41:42 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	push_b_to_a(t_stack **a, t_stack **b, int size, t_counts **ops)
{
	int count = 0;
	t_stack *tmp;
	tmp = *b;
	while (tmp != NULL)
	{
	if (tmp->index == size -1)
		{
			if (count <= size / 2)
			{
			while (count != 0)
			{
				ft_rb(b, ops, 0);
				count--;
			}
			}
			else 
			{
				while (size - count != 0)
				{
					ft_rrb(b, ops, 0);
					size--;
				}
			}
			ft_pa(a, b, ops);
			return ;
		}
		tmp = tmp->next;
		count++;
	}
}

void	test_sort_simple(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	print_stack(a);
	int i = 0;
	while (size - i)
	{
		ft_pb(a, b, ops);
		print_stack(b);
		i++;
	}
	while(size)
	{
		push_b_to_a(a, b, size, ops);	
		print_stack(a);
		size--;
	}
}