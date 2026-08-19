/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 07:36:25 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/19 16:39:51 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"
#include "libft.h"

void	print_stack(t_stack **a)
{
	t_stack	*current = *a;

	while (current != NULL)
	{
		ft_printf("[%d]: %l\n", current->index, current->value);
		current = current->next;
	}
//	ft_printf("disorder: %d", disorder);
}

void	push_swap(t_check_arg **input)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	size = build_stack(&a, input);
	if (!a)
		return ;
	b = NULL;
	check_stack(&a);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return ;
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_check_arg	*input;

	if (argc == 1)
		return (0);
	input = check_arg(argv, argc);
	push_swap(&input);
	return (0);
}
