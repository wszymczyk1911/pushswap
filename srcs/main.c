/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 07:36:25 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/16 14:31:24 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

double	push_swap(t_counts **ops, t_check_arg **input)
{
	t_stack	*a;
	t_stack	*b;
	double	disorder;
	int		size;

	size = build_stack(&a, input);
	if (!a)
		return (0);
	b = NULL;
	check_stack(&a);
	assign_index(&a);
	disorder = compute_disorder(&a);
	if (size <= 1)
		return (0);
	if ((*input)->strategy == 1)
		sort_simple(&a, &b, ops, size);
	else if ((*input)->strategy == 2)
		sort_medium(&a, &b, ops, size);
	else if ((*input)->strategy == 3)
		sort_complex(&a, &b, ops, size);
	else if ((*input)->strategy == 0)
		sort_adaptive(&a, &b, ops, size, disorder);
	free_stack(&a);
	return (disorder);
}

int	main(int argc, char **argv)
{
	t_counts	*ops;
	t_check_arg	*input;
	double		disorder;

	if (argc == 1)
		return (0);
	input = check_arg(argv, argc);
	create_ops(&ops);
	disorder = push_swap(&ops, &input);
	if (input->bench == 1)
		print_bench(disorder, input->strategy, ops);
//	free_counts(&ops);
}
