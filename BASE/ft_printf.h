/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:29:03 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/16 14:36:19 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* Main Function*/
int	ft_printf(const char *format, ...);

/*Format Dispatcher*/
int	ft_print_format(char specifier, va_list args);

/*Printing Functions*/
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int ft_putunsigned(unsigned int n);
int	puthex(unsigned int n, char format);
int	putptr(void *ptr);

#endif
