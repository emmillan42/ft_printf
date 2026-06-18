/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:28:45 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/18 12:54:18 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex(unsigned long n)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_putptr_hex(n / 16);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	address;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	len = 0;
	len += ft_putstr("0x");
	len += ft_putptr_hex(address);
	return (len);
}
