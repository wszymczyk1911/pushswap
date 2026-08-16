/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 12:51:32 by djuja             #+#    #+#             */
/*   Updated: 2026/08/16 14:36:34 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	sort_adaptive(t_stack **a, t_stack **b, t_counts **ops, int size, double disorder)
{
	if (disorder < 0.2)
		sort_simple(a, b, ops, size);
	else if (disorder >= 0.2 && disorder <= 0.5)
		sort_medium(a, b, ops, size);
	else if (disorder > 0.5)
		sort_complex(a, b, ops, size);
	return ;
}