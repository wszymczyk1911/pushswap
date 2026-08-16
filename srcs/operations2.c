/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:16:27 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/16 14:31:56 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	ft_ra(t_stack **a, t_counts **ops, int rr)
{
	t_stack	*node;
	t_stack	*current;

	node = pop_top(a);
	current = *a;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	node->prev = current;	
	if (rr == 0)
	{
		ft_putstr_fd("ra\n", 1);
		(*ops)->ra += 1;
		(*ops)->total += 1;
	}
}

void	ft_rb(t_stack **b, t_counts **ops, int rr)
{
	t_stack	*node;
	t_stack	*current;

	node = pop_top(b);
	current = *b;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	node->prev = current;
	if (rr == 0)
	{
		ft_putstr_fd("rb\n", 1);
		(*ops)->rb += 1;
		(*ops)->total += 1;
	}
}

void	ft_rr(t_stack **a, t_stack **b, t_counts **ops)
{
	ft_ra(a, ops, 1);
	ft_rb(b, ops, 1);
	ft_putstr_fd("rr\n", 1);
	(*ops)->rr += 1;
	(*ops)->total += 1;
}
