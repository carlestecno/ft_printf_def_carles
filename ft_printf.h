/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasadem <ccasadem@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:50:48 by ccasadem          #+#    #+#             */
/*   Updated: 2023/01/17 08:51:00 by ccasadem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int	ft_putchar(char ch);
int	ft_putstring(char *s);
int	ft_putinteger(int number, int count);
int	ft_puthexa(unsigned int number, char c, int count);
int	ft_putaddress(unsigned long int number, int count);
int	ft_selector(char s, va_list args);
int	ft_printf(char const *s, ...);

#endif
