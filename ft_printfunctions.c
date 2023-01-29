/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasadem <ccasadem@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:08:23 by ccasadem          #+#    #+#             */
/*   Updated: 2023/01/17 12:50:56 by ccasadem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char ch)
{
	return (write(1, &ch, 1));
}

int	ft_putstring(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		return (write (1, "(null)", 6));
	}
	while (*s)
	{
		if (ft_putchar(*s) == -1)
			return (-1);
		count++;
		s++;
	}
	return (count);
}

int	ft_putaddress(unsigned long int number, int count)
{
	if (count == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		if (ft_putchar('x') == -1)
			return (-1);
		count += 2;
	}
	if (number >= 16)
		count = ft_putaddress(number / 16, count);
	number %= 16;
	if (number >= 10 && number <= 15)
			number += 39;
	number += 48;
	if (ft_putchar(number) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putinteger(int number, int count)
{
	if (number == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	else
	{
		if (number < 0)
		{
			if (ft_putchar('-') == -1)
				return (-1);
			number *= -1;
			count++;
		}
		if (number > 9)
			count = ft_putinteger(number / 10, count);
		if (count == -1)
			return (-1);
		count++;
		number = number % 10 + 48;
		if (ft_putchar(number) == -1)
			return (-1);
	}
	return (count);
}

int	ft_puthexa(unsigned int number, char c, int count)
{
	unsigned int	var;

	var = 16;
	if (c == 'u')
		var = 10;
	if (number >= var)
		count = ft_puthexa(number / var, c, count);
	if (count == -1)
		return (-1);
	number %= var;
	if (number >= 10 && number <= 15)
	{
		if (c == 'x' || c == 'p')
			number += 39;
		else
			number += 7;
	}
	number += 48;
	count++;
	if (ft_putchar(number) == -1)
		return (-1);
	return (count);
}
