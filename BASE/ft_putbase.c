/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:52:30 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/18 13:58:08 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned long n, const char *base)
{
	int	base_len;
	int	len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	if (n >= (unsigned long)base_len)
		len += ft_putbase(n / base_len, base);
	len += ft_putchar(base[n % base_len]);
	return (len);
}
