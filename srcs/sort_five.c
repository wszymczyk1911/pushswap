/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 12:10:33 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/22 12:26:32 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **a, t_stack **b, t_counts **ops, int size)
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
		if ((*a)->index == i)
			ft_pb(a, b, ops);
		i++;
		size--;
	}
	sort_little(a, ops, size);
	while (*b != NULL)
		ft_pa(a, b, ops);
}
