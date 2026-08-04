/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuja <djuja@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:00:49 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/04 15:14:22 by djuja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int		value;
	int		index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_check_arg
{
	char	**args;
	int		flag;
	double	disorder;
	int 	bench;
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

void    push_swap(t_counts **ops, char **argv, int start, int strategy);

int		build_stack(t_stack **a, char **argv, int start);
char    **join_and_split(char **argv, int start);
t_stack *ft_lstnew_addlast(t_stack **lst, t_stack *last, int value);

void    assign_index(t_stack **stack);
void	free_stack(t_stack **stack);
void    check_stack(t_stack **stack);
double  compute_disorder(t_stack **stack);
void    create_ops(t_counts **ops);

t_stack *pop_top(t_stack **stack);
void    push_ontop(t_stack **stack, t_stack *node);

void	sort_little(t_stack **a, t_counts **ops, int size);
void    sort_simple(t_stack **a, t_stack **b, t_counts **ops, int size);
void    sort_three(t_stack **a, t_counts **ops);

void    ft_sa(t_stack **a, t_counts **ops, int ss);
void    ft_sb(t_stack **b, t_counts **ops, int ss);
void    ft_ss(t_stack **a, t_stack **b, t_counts **ops);
void    ft_pa(t_stack **a, t_stack **b, t_counts **ops);
void    ft_pb(t_stack **a, t_stack **b, t_counts **ops);
void    ft_ra(t_stack **a, t_counts **ops, int rr);
void    ft_rb(t_stack **b, t_counts **ops, int rr);
void    ft_rr(t_stack **a, t_stack **b, t_counts **ops);
void    ft_rra(t_stack **a, t_counts **ops, int rrr);
void    ft_rrb(t_stack **b, t_counts **ops, int rrr);
void    ft_rrr(t_stack **a, t_stack **b, t_counts **ops);

void    print_stack(t_stack **a);
t_check_arg	*check_arg(char **argv, int argc);
#endif
