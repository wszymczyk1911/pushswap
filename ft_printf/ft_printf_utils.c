/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:33:57 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/03 13:52:41 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%c Prints a single character.
int	ft_putchar(int c)
{
	int	count;

	count = 0;
	count = write(1, &c, 1);
	return (count);
}

//%s Prints a string (as defined by the common C convention).
int	ft_putstr(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

//%p The void * pointer argument has to be printed in hexadecimal format.
int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_hex((unsigned long long)ptr, 'x');
	}
	return (count);
}

//&d Prints a decimal (base 10) number.
//%i Prints an integer in base 10.
//%u Prints an unsigned decimal (base 10) number.
int	ft_putnbr(long long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

//%x Prints a number in hexadecimal (base 16) lowercase format.
//%X Prints a number in hexadecimal (base 16) uppercase format.
int	ft_putnbr_hex(unsigned long long nb, char format)
{
	char	*base_x;
	char	*base_other_x;
	int		count;

	count = 0;
	base_x = "0123456789abcdef";
	base_other_x = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_putnbr_hex(nb / 16, format);
	if (format == 'x')
		count += ft_putchar(base_x[nb % 16]);
	else if (format == 'X')
		count += ft_putchar(base_other_x[nb % 16]);
	return (count);
}
