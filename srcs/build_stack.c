/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 14:24:23 by djuja             #+#    #+#             */
/*   Updated: 2026/08/22 14:18:10 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

char	**join_and_split(t_check_arg **input)
{
	char	**arr;

	arr = NULL;
	arr = ft_split((*input)->str, ' ');
	if (!arr)
		return (free((*input)->str), NULL);
	free((*input)->str);
	(*input)->str = NULL;
	return (arr);
}

t_stack	*ft_lstnew_addlast(t_stack **lst, t_stack *last, long long value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->prev = last;
	new_node->next = NULL;
	if (last == NULL)
		*lst = new_node;
	else
		last->next = new_node;
	return (new_node);
}

int	build_stack(t_stack **a, t_check_arg **input)
{
	t_stack	*last;
	char	**arr;
	int		i;
	int		size;

	size = 0;
	last = NULL;
	i = 0;
	arr = join_and_split(input);
	if (!arr)
		return (0);
	while (arr[i])
	{
		last = ft_lstnew_addlast(a, last, ft_atoi(arr[i]));
		if (!last)
		{
			free_words(arr, i);
			free_stack(a);
			return (0);
		}
		size++;
		i++;
	}
	free_words(arr, i);
	return (size);
}
/*
int	main()
{
	char	*argv[] = {"hello", "42", "1 2 3 4", NULL};
	int start = 1;
	t_stack *a;
	
	build_stack(&a, argv, start);
	t_stack *current;
	current = a;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
*/
