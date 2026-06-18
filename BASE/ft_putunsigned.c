/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 08:41:05 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/18 11:28:47 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunsigned(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}
