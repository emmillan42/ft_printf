/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:58:23 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/20 13:14:20 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret = ft_print_format(*format, args);
		}
		else
			ret = ft_putchar(*format);
		if (ret == -1)
			return (va_end(args), -1);
		count += ret;
		format++;
	}
	va_end(args);
	return (count);
}
