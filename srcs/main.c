/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 07:36:25 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/07 17:13:09 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	print_stack(t_stack **a)
{
	t_stack *current = *a;

	while (current != NULL)
	{
		ft_printf("[%d]: %l\n", current->index, current->value);
		current = current->next;
	}
//	ft_printf("disorder: %d", disorder);
}

double	push_swap(char **argv, t_counts **ops, int start, int strategy)
{
	t_stack	*a;
	t_stack	*b;
	double	disorder;
	int		size;

	size = build_stack(&a, argv, start);
	if (!a)
		return (0);
	b = NULL;
	check_stack(&a);
	assign_index(&a);
	disorder = compute_disorder(&a);
	if (size <= 1)
		return (0);
	if (strategy == 1)
		sort_simple(&a, &b, ops, size);
	else if (strategy == 2)
		sort_medium(&a, &b, ops, size);
//	else if (strategy == 3)
//		sort_complex(&a, &b, ops, size);
//	else if (strategy == 0)
//		sort_adaptive();
	free_stack(&a);
	return (disorder);
}

int	main(int argc, char **argv)
{
	t_counts	*ops;
	int		start;
	int		strategy;
	int		bench;
	double	disorder;

	strategy = 2;
	bench = 1;
	if (argc == 1)
		return (0);
	start = 1;
	create_ops(&ops);
//	start = check_flags(argv, &strategy, &bench);
	disorder = push_swap(argv, &ops, start, strategy);
	if (bench == 1)
		print_bench(disorder, strategy, ops);
//	free_counts(&ops);
}
