/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:10:45 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/03 13:49:43 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_rra(t_stack **a, t_counts **ops, int rrr)
{
	t_stack	*current;

	current = *a;
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	push_ontop(a, current);
	if (rrr == 0)
	{
		ft_printf("rra\n");
		(*ops)->rra += 1;
		(*ops)->total += 1;
	}
}

void	ft_rrb(t_stack **b, t_counts **ops, int rrr)
{
	t_stack	*current;

	current = *b;
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	push_ontop(b, current);
	if (rrr == 0)
	{
		ft_printf("rrb\n");
		(*ops)->rrb += 1;
		(*ops)->total += 1;
	}
}

void 	ft_rrr(t_stack **a, t_stack **b, t_counts **ops)
{
	ft_rra(a, ops, 1);
	ft_rrb(b, ops, 1);
	ft_printf("rrr\n");
	(*ops)->rrr += 1;
	(*ops)->total += 1;
}
