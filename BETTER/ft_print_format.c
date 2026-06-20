/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:20:57 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/19 20:21:42 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (specifier == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 'x'));
	if (specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 'X'));
	if (specifier == '%')
		return (ft_putchar('%'));
	return (-1);
}
