/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:33:07 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/19 15:19:53 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"
#include "libft.h"

void	ft_sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	first = pop_top(a);
	second = pop_top(a);
	push_ontop(a, first);
	push_ontop(a, second);
}

void	ft_sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	first = pop_top(b);
	second = pop_top(b);
	push_ontop(b, first);
	push_ontop(b, second);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (*b == NULL)
		return ;
	node = pop_top(b);
	push_ontop(a, node);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (*a == NULL)
		return ;
	node = pop_top(a);
	push_ontop(b, node);
}
