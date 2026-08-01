/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:59:56 by wikszymc          #+#    #+#             */
/*   Updated: 2026/07/31 12:41:11 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	start;
	int	size;
	int	disorder;
	//plus strategy and bench 
	
	if (argc == 1)
		return (0);
	start = check_flags(argv, &strategy, &bench); //checks for strategy/bench flags
			       //returns idx where the numbers begin
	a = build_stack(argv, &size); //splits argv into numbers and puts them into stack a
				      //counts size (or lstsize)
	b = NULL;
	disorder = compute_disorder();
	
}
