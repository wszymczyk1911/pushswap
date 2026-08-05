/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 07:36:25 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/05 21:15:29 by djuja            ###   ########.fr       */
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
		ft_printf("[%d]: %d\n", current->index, current->value);
		current = current->next;
	}
//	ft_printf("disorder: %d", disorder);
}

void	push_swap(t_counts **ops, char **argv, int start, int strategy)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	double	disorder;

	size = build_stack(&a, argv, start);
	if (!a)
		return ;
	b = NULL;
//	check_stack(&a);
	assign_index(&a);
	disorder = compute_disorder(&a);
       print_stack(&a);
	if (size <= 1)
		return ;
	if (strategy == 1 || (strategy == 0 && disorder < 0.2))
		sort_simple(&a, &b, ops, size);
//	else if (strategy == 2 || (strategy == 0
//			&& disorder >= 0.2 && disorder <= 0.5))
//		sort_medium();
//	else if (strategy == 3 || (strategy == 0 && disorder > 0.5))
//		sort_complex();
//	print_stack(&a);
	free_stack(&a);
}

int	main(int argc, char **argv)
{
	t_counts	*ops;
	int			start;
	int			strategy;
//	int			bench;
	
	if (argc == 1)
		return (0);
	t_check_arg *test = check_arg(argv, argc);
	printf("nowy string - %s", test->str);
	return (0);
	strategy = 1;
//	bench = 0;
	start = 1;
//	start = check_flags(argv, &strategy, &bench);
	create_ops(&ops);
	if (!ops)
		return (0);
	push_swap(&ops, argv, start, strategy);
//	if (bench == 1)
//		print_bench();
//	free_counts(&ops);
	return (0);
}

//check_flags -> it should return index at which numbers start argv[index]
//sort_simple
//sort_medium
//sort_complex
//free_counts
//print_bench
