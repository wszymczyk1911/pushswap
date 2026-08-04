/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikszymc <wikszymc@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:16:04 by wikszymc          #+#    #+#             */
/*   Updated: 2026/08/02 12:50:16 by wikszymc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(char format, va_list ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		count += ft_putnbr(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_putnbr_hex(va_arg(ap, int), format);
	else if (format == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			count += ft_check_format(str[++i], ap);
		else if (str[i] != '%')
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
/*
#include <stdio.h>
#include <string.h>


int	main(void)
{
	int	count = 0;
	int	og_count = 0;
	char	str[] = "Standard C library (libc, -lc)";
	char	str2[] = "hello!";
	int	c = 'z';

	ft_printf("\nFT_PRINTF: \n");
	count = ft_printf("%s\n", str);
	ft_printf("count is: [ %d ]\n", count);
	ft_printf("ft_strlen: %d\n", ft_strlen(str));
	int	i = 0;
	int	len = ft_strlen(str2);
	count = 0;
	ft_printf("len: %d\n", len);
	while (i < len)
	{
		count += ft_printf("[%d]: %c\n", count, str2[i]);
		i++;
	}
	count = 0;
	count = ft_printf("single char: %c\n", c);
	ft_printf("count = %d\n", count);
	printf("\nORIGINAL PRINTF: \n");
	og_count = printf("%s\n", str);
	printf("og_count is: [ %d ]\n", og_count);
	printf("strlen: %lu\n", strlen(str));
	i = 0;
	len = (int)strlen(str2);
	og_count = 0;
	printf("len: %d\n", len);
	while (i < len)
	{
		og_count += printf("[%d]: %c\n", og_count, str2[i]);
		i++;
	}
	og_count = 0;
	og_count = printf("single char: %c\n", c);
	printf("og_count = %d\n", og_count);
	printf("\n");
	return (0);
}*/
