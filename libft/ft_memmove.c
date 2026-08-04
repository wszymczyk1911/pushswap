/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 21:40:15 by wikszymc          #+#    #+#             */
/*   Updated: 2026/07/08 21:52:24 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy_forward(unsigned char *d, const unsigned char *s,
				size_t len);
static void	ft_copy_backward(unsigned char *d, const unsigned char *s,
				size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d < s)
		ft_copy_forward(d, s, len);
	else
		ft_copy_backward(d, s, len);
	return (dst);
}

static void	ft_copy_forward(unsigned char *d, const unsigned char *s,
		size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
}

static void	ft_copy_backward(unsigned char *d, const unsigned char *s,
		size_t len)
{
	while (len > 0)
	{
		len--;
		d[len] = s[len];
	}
}
