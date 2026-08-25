/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 07:36:25 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/25 13:18:51 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"
#include "libft.h"

void	push_swap(t_check_arg **input)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	size = build_stack(&a, input);
	if (!a)
		return ;
	b = NULL;
	check_stack(&a, input);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return ;
}

int	main(int argc, char **argv)
{
	t_check_arg	*input;

	if (argc == 1)
		return (0);
	input = check_arg(argv, argc);
	if (input->str == NULL)
		return (free(input), -1);
	push_swap(&input);
	free(input->str);
	free(input);
	return (0);
}
