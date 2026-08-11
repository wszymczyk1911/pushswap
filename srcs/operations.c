/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:33:07 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/04 16:23:39 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	ft_sa(t_stack **a, t_counts **ops, int ss)
{
	t_stack	*first;
	t_stack	*second;

	first = pop_top(a);
	second = pop_top(a);
	push_ontop(a, first);
	push_ontop(a, second);
	if (ss == 0)
	{
		ft_putstr_fd("sa\n", 1);
		(*ops)->sa += 1;
		(*ops)->total += 1;
	}
}

void	ft_sb(t_stack **b, t_counts **ops, int ss)
{
	t_stack *first;
	t_stack *second;

	first = pop_top(b);
	second = pop_top(b);
	push_ontop(b, first);
	push_ontop(b, second);
	if (ss == 0)
	{
		ft_putstr_fd("sb\n", 1);
		(*ops)->sb += 1;
		(*ops)->total += 1;
	}
}

void	ft_ss(t_stack **a, t_stack **b, t_counts **ops)
{
	ft_sa(a, ops, 1);
	ft_sb(b, ops, 1);
	ft_putstr_fd("ss\n", 1);
	(*ops)->ss += 1;
	(*ops)->total += 1;
}

void	ft_pa(t_stack **a, t_stack **b, t_counts **ops)
{
	t_stack	*node;

	if (*b == NULL)
		return ;
	node = pop_top(b);
	push_ontop(a, node);
	ft_putstr_fd("pa\n", 1);
	(*ops)->pa += 1;
	(*ops)->total += 1;
}

void	ft_pb(t_stack **a, t_stack **b, t_counts **ops)
{
	t_stack	*node;

	if (*a == NULL)
		return ;
	node = pop_top(a);
	push_ontop(b, node);
	ft_putstr_fd("pb\n", 1);
	(*ops)->pb += 1;
	(*ops)->total += 1;
}
