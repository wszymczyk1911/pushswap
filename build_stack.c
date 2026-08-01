#include "push_swap.h"

void	build_stack(t_stack **a, char **argv, int start)
{
	t_stack	*last;
	char	**arr;
	int	i;

	last = NULL;
	i = 0;
	arr = join_and_split(argv, start);
	while (arr[i])
	{
		last = ft_lstnew_addlast(a, last, ft_atoi(arr[i]));
		i++;
	}
}

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
