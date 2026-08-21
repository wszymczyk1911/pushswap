/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:38:11 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/04 15:02:03 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdouble(double nb)
{
	int	count;
	int	number1;
	int	number2;

	count = 0;
	number1 = nb * 10;
	number2 = nb * 100;
	count = ft_putnbr((long long)nb);
	count = ft_putchar('.');
	count = ft_putnbr((long long)number1 % 10);
	count = ft_putnbr((long long)number2 % 10);
	return (count);
}
