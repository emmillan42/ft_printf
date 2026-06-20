/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:29:37 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/19 19:13:40 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;
	int	ret;

	if (!str)
		str = "(null)";
	len = 0;
	while (*str)
	{
		ret = ft_putchar(*str);
		if (ret == -1)
			return (-1);
		len += ret;
		str++;
	}
	return (len);
}
