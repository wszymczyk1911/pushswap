
#include "checker.h"
#include "libft.h"

#include <stdio.h>

void put_err(t_stack **a, t_stack **b)
{
	ft_putstr_fd("3 Error\n", 2);
	free_stack(a);
	free_stack(b);
	exit(1);
}

void compare_paramets(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 10) == 0)
		ft_sa(a);
	else if (ft_strncmp(line, "sb\n", 10) == 0)
		ft_sb(b);
	else if (ft_strncmp(line, "ss\n", 10) == 0)
		ft_ss(a, b);
	else if (ft_strncmp(line, "pa\n", 10) == 0)
		ft_pa(a, b);
	else if (ft_strncmp(line, "pb\n", 10) == 0)
		ft_pb(a, b);
	else if (ft_strncmp(line, "ra\n", 10) == 0)
		ft_ra(a);
	else if (ft_strncmp(line, "rb\n", 10) == 0)
		ft_rb(b);
	else if (ft_strncmp(line, "rr\n", 10) == 0)
		ft_rr(a, b);
	else if (ft_strncmp(line, "rra\n", 10) == 0)
		ft_rra(a);
	else if (ft_strncmp(line, "rrb\n", 10) == 0)
		ft_rrb(b);
	else if (ft_strncmp(line, "rrr\n", 10) == 0)
		ft_rrr(a, b);
	else
		put_err(a, b);
}

void sort_stack(t_stack **a, t_stack **b)
{
	char *line;

	line = get_next_line(0);
	while (line)
	{
		compare_paramets(a, b, line);
		line = get_next_line(0);
	}
	free(line);
	if (compute_disorder(a) == 0 && *b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}