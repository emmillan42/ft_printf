/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:28:45 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/19 21:11:42 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	len;
	int	ret;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = 0;
	ret = ft_putstr("0x");
	if (ret == -1)
		return (-1);
	len += ret;
	ret = ft_putbase((unsigned long)ptr, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}
