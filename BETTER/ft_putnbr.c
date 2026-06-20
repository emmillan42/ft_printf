/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:33:43 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/19 20:07:21 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nbr;
	int		len;
	int		ret;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		len += ret;
		nbr = -nbr;
	}
	ret = ft_putbase(nbr, "0123456789");
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}
