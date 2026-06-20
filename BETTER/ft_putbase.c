/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:52:30 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/19 19:12:08 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned long n, const char *base)
{
	int	base_len;
	int	len;
	int	ret;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	if (n >= (unsigned long)base_len)
	{
		ret = ft_putbase(n / base_len, base);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = ft_putchar(base[n % base_len]);
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}
