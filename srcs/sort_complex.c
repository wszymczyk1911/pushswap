/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 10:48:09 by djuja             #+#    #+#             */
/*   Updated: 2026/08/20 10:35:28 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	number_of_bits(int size)
{
	int	nb_bits;

	nb_bits = 0;
	size = size - 1;
	while (size)
	{
		nb_bits++;
		size = size / 2;
	}
	return (nb_bits);
}

static void	split_radix(t_stack **a, t_stack **b, t_counts **ops, int bit)
{
	if (((*a)->index >> bit) & 1)
		ft_ra(a, ops, 0);
	else
		ft_pb(a, b, ops);
	return ;
}

void	sort_complex(t_stack **a, t_stack **b, t_counts **ops, int size)
{
	int	nb_bits;
	int	bit;
	int	n;

	if (size <= 3)
	{
		sort_little(a, ops, size);
		return ;
	}
	nb_bits = number_of_bits(size);
	bit = 0;
	while (bit < nb_bits)
	{
		n = size;
		while (n > 0)
		{
			split_radix(a, b, ops, bit);
			n--;
		}
		while (*b != NULL)
			ft_pa(a, b, ops);
		bit++;
	}
	return ;
}
