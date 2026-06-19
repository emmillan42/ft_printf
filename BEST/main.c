/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:51:48 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/19 23:52:37 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int				ret_printf;
	int				ret_ft_printf;
	char			c;
	char			*str;
	char			*null_str;
	int				n;
	unsigned int	u;
	void			*ptr;

	c = 'A';
	str = "Hello 42!";
	null_str = NULL;
	n = 42;
	u = 4294967295U;
	ptr = &n;

	printf("========================================\n");
	printf("CHARACTER\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%c]\n", c);
	ret_ft_printf = ft_printf("ft_printf : [%c]\n", c);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("STRING\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%s]\n", str);
	ret_ft_printf = ft_printf("ft_printf : [%s]\n", str);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("NULL STRING\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%s]\n", null_str);
	ret_ft_printf = ft_printf("ft_printf : [%s]\n", null_str);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("SIGNED INT\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%d]\n", n);
	ret_ft_printf = ft_printf("ft_printf : [%d]\n", n);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("INT_MIN\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%d]\n", INT_MIN);
	ret_ft_printf = ft_printf("ft_printf : [%d]\n", INT_MIN);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("INT_MAX\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%d]\n", INT_MAX);
	ret_ft_printf = ft_printf("ft_printf : [%d]\n", INT_MAX);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("UNSIGNED INT\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%u]\n", u);
	ret_ft_printf = ft_printf("ft_printf : [%u]\n", u);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("HEX LOWERCASE\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%x]\n", 42);
	ret_ft_printf = ft_printf("ft_printf : [%x]\n", 42);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("HEX UPPERCASE\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%X]\n", 42);
	ret_ft_printf = ft_printf("ft_printf : [%X]\n", 42);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("POINTER\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%p]\n", ptr);
	ret_ft_printf = ft_printf("ft_printf : [%p]\n", ptr);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("NULL POINTER\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%p]\n", NULL);
	ret_ft_printf = ft_printf("ft_printf : [%p]\n", NULL);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("PERCENT\n");
	printf("========================================\n");

	ret_printf = printf("printf    : [%%]\n");
	ret_ft_printf = ft_printf("ft_printf : [%%]\n");

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("MIXED TEST\n");
	printf("========================================\n");

	ret_printf = printf(
			"printf    : c=%c s=%s d=%d u=%u x=%x X=%X p=%p %%\n",
			'A',
			"hello",
			-42,
			42U,
			42U,
			42U,
			ptr);

	ret_ft_printf = ft_printf(
			"ft_printf : c=%c s=%s d=%d u=%u x=%x X=%X p=%p %%\n",
			'A',
			"hello",
			-42,
			42U,
			42U,
			42U,
			ptr);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("NULL\n");
	printf("========================================\n");
	// printf(NULL);				//Compile without flags  -Wall -Wextra -Werror
	// printf("\n");
	// printf("%d", printf(NULL));	//Compile without flags  -Wall -Wextra -Werror
	// printf("\n");
	ft_printf(NULL);
	printf("\n");
	ft_printf("%d", ft_printf(NULL));
	printf("\n\n");
	printf("========================================\n");
	printf("END %%\n");
	printf("========================================\n");

	// ret_printf = printf("printf: Hello, World\n%");	//Compile without flags
	ret_ft_printf = ft_printf("ft_printf : Hello, World\n%");

	// printf("return printf    = %d\n", ret_printf);	//Compile without flags
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	// ret_printf = printf("printf    : [%%]\n%");		//Compile without flags
	ret_ft_printf = ft_printf("ft_printf : [%%]\n%");

	// printf("return printf    = %d\n", ret_printf);	//Compile without flags
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("ONLY %%\n");
	printf("========================================\n");

	// ret_printf = printf("%"); //Compile without flags  -Wall -Wextra -Werror
	ret_ft_printf = ft_printf("%");
	// printf("return printf    = %d\n", ret_printf);	//Compile without flags
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	printf("========================================\n");
	printf("MISC %%\n");
	printf("========================================\n");

	ret_printf = printf("printf    = %d\n", 76);
	ret_ft_printf = ft_printf("ft_printf = %d\n", 76);

	printf("return printf    = %d\n", ret_printf);
	printf("return ft_printf = %d\n\n", ret_ft_printf);

	return (0);
}
