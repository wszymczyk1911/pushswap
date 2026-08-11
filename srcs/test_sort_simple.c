/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:25:57 by djuja             #+#    #+#             */
/*   Updated: 2026/08/11 18:39:15 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
void	test_sort_simple(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	print_stack(a);
	while (size)
	{
		ft_pb(a, b, ops);
		print_stack(b);
		size--;
	}
}