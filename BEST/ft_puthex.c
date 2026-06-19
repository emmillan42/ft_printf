/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:04:33 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/19 20:08:12 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_putbase(n, "0123456789abcdef"));
	if (format == 'X')
		return (ft_putbase(n, "0123456789ABCDEF"));
	return (0);
}
