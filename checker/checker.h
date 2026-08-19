/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:00:49 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/19 15:23:13 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
typedef struct s_stack
{
	long long		value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_check_arg
{
	char	*str;
	int		strategy;
	double	disorder;
	int		bench;
}	t_check_arg;

typedef struct s_counts
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_counts;
t_check_arg	*check_arg(char **argv, int argc);
void		push_swap(t_check_arg **input);

int			build_stack(t_stack **a, t_check_arg **input);
char		**join_and_split(t_check_arg **input);
t_stack		*ft_lstnew_addlast(t_stack **lst, t_stack *last, long long value);

void		free_stack(t_stack **stack);
void		check_stack(t_stack **stack);
double		compute_disorder(t_stack **stack);
void		create_ops(t_counts **ops);


t_stack		*pop_top(t_stack **stack);
void		push_ontop(t_stack **stack, t_stack *node);


int			in_first_half(t_stack **a, int idx, int size);

void		ft_sa(t_stack **a);
void		ft_sb(t_stack **b);
void		ft_ss(t_stack **a, t_stack **b);
void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **a, t_stack **b);
void		ft_ra(t_stack **a);
void		ft_rb(t_stack **b);
void		ft_rr(t_stack **a, t_stack **b);
void		ft_rra(t_stack **a);
void		ft_rrb(t_stack **b);
void		ft_rrr(t_stack **a, t_stack **b);

void		print_stack(t_stack **a);
void sort_stack(t_stack **a, t_stack **b);
#endif
