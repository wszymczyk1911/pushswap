/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 12:22:18 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/07 13:45:14 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf.h"

static int      ft_sqrt(int size)
{
        int     n;

        n = 0;
        while ((n * n) <= size)
        {
                if ((n * n) == size)
                        return (n);
                n++;
        }
        return (n);
}

static int      find_push_idx(t_stack **a, int i, int chunk, int size)
{
        t_stack *current;
        int     smallest;
        int     biggest;
        int     max;

        smallest = 0;
        biggest = 0;
        current = *a;
        max = i + chunk;
        while (current != NULL)
        {
                if (current->index >= i && current->index < max)
                {
                        if (current->index < smallest || smallest == 0)
                                smallest = current->index;
                        else if (current->index > biggest)
                                biggest = current->index;
                }
                current = current->next;
        }
        if (smallest < -(biggest + 1 - size))
                return (smallest);
        return (biggest);
}

static int      find_dir(t_stack **stack, int push_idx, int size)
{
        t_stack *current;
        int     n;

        current = *stack;
        n = size / 2;
        while (n > 0)
        {
                if (current->index == push_idx)
                        return (1);
                current = current->next;
                n--;
        }
        return (0);

}

static int	find_target_idx(t_stack **b, int i)
{
	t_stack	*current;
	int	target_idx;

	current = *b;
	target_idx = -1;
	while (current != NULL)
	{
		if (i > current->index)
		{
			if (i < target_idx)
				target_idx = current_index;
		}
		current = current->next;
	}
	current = *b;
	if (target_idx == -1)
	{
		target_idx = INT_MAX;
		while (current != NULL)
		{
			if (current->index < target_idx)
				target_idx = current->index;
			current = current->index;
		}
	}
	return (target_idx);
}

void    sort_medium(t_stack **a, t_stack **b, t_counts **ops, int size)
{
        int     chunk;
        int     i;
        int     push_idx;
        int     dir;
        int     n;
        int     size_a;

        chunk = ft_sqrt(size);
        i = 0; 
        size_a = size;
        while (*a != NULL)
        {
                n = 0;
                while (n < chunk && *a != NULL)
                {
                        push_idx = find_push_idx(a, i, chunk, size);
                        dir = find_dir(a, push_idx, size);
                        while ((*a)->index != push_idx)
                        {
                                if (dir == 1)
                                        ft_ra(a, ops, 0);
                                else
                                        ft_rra(a, ops, 0);
                        }
			target_idx = find_target_idx(b, push_idx);
                        ft_pb(a, b, ops);
                        n++;
                        size_a--;
                } 
                i += chunk;
        }
        print_stack(a);
        ft_printf("-------\n");
        print_stack(b);
        i = size - 1;
        while (*b != NULL)
        {
                dir = find_dir(b, i, size);
                while ((*b)->index != i)
                {
                        if (dir == 1)
                                ft_rb(b, ops, 0);
                        else
                                ft_rrb(b, ops, 0);
                }
                ft_pa(a, b, ops);
                size--;
                i--;
        }
        print_stack(a);
        ft_printf("------\n");
        print_stack(b);
}
