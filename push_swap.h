/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:00:49 by wikszymc          #+#    #+#             */
/*   Updated: 2026/07/31 17:23:49 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		value;
	struct s_stack	*next;
}	t_stack;

void    build_stack(t_stack **a, char **argv, int start);
int     ft_atoi(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char    **ft_split(char const *s, char c);
char    **join_and_split(char **argv, int start);
t_stack *ft_lstnew_addlast(t_stack **lst, t_stack *last, int value);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *s);

#endif
