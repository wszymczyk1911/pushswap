/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:16:27 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/19 15:20:44 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"
#include "libft.h"

void	ft_ra(t_stack **a)
{
	t_stack	*node;
	t_stack	*current;

	node = pop_top(a);
	current = *a;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	node->prev = current;	
}

void	ft_rb(t_stack **b)
{
	t_stack	*node;
	t_stack	*current;

	node = pop_top(b);
	current = *b;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	node->prev = current;
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_rb(b);
}
