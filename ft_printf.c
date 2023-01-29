/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasadem <ccasadem@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:02:19 by ccasadem          #+#    #+#             */
/*   Updated: 2023/01/17 12:52:13 by ccasadem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_selector(char s, va_list args)
{
	if (s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s == '%')
		return (ft_putchar('%'));
	else if (s == 's')
		return (ft_putstring(va_arg(args, char *)));
	else if (s == 'd' || s == 'i')
		return (ft_putinteger(va_arg(args, int), 0));
	else if (s == 'x' || s == 'X' || s == 'u')
		return (ft_puthexa(va_arg(args, unsigned int), s, 0));
	else if (s == 'p')
		return (ft_putaddress(va_arg(args, unsigned long int), 0));
	return (1);
}

int	ft_printf(char const *s, ...)
{
	int		count;
	va_list	args;
	int		j;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s != '%')
		{
			if (ft_putchar(*s) == -1)
				return (-1);
			count++;
		}
		if (*s == '%')
		{
			s++;
			j = ft_selector(*s, args);
			if (j == -1)
				return (-1);
			count += j;
		}
	s++;
	}
	va_end(args);
	return (count);
}
