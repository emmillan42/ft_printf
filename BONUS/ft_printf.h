/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:08:12 by emmmilla          #+#    #+#             */
/*   Updated: 2026/06/16 13:58:21 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fmt
{
	int		left;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		precision;
	char	type;
}			t_fmt;
typedef struct s_print
{
	int	count;
}	t_print;

int		ft_printf(const char *format, ...);

void	ft_init_format(t_fmt *fmt);

void	ft_parse_flags(const char **str, t_fmt *fmt);
void	ft_parse_width(const char **str, t_fmt *fmt);
void	ft_parse_precision(const char **str, t_fmt *fmt);
void	ft_parse_type(const char **str, t_fmt *fmt);

int		ft_dispatcher(t_fmt *fmt, va_list args);

int		ft_print_char(va_list args, t_fmt *fmt);
int		ft_print_str(va_list args, t_fmt *fmt);
int		ft_print_int(va_list args, t_fmt *fmt);
int		ft_print_unsigned(va_list args, t_fmt *fmt);
int		ft_print_hex(va_list args, t_fmt *fmt);
int		ft_print_ptr(va_list args, t_fmt *fmt);
int		ft_print_percent(t_fmt *fmt);

char	ft_itoa_printf(int n);
char	ft_utoa_base(unsigned long n, char *base);
char	ft_ptrtoa(void *ptr);

char	ft_apply_precision(char *str, t_fmt *fmt);
char	ft_apply_sign(char *str, t_fmt *fmt);
char	ft_apply_hash(char *str, t_fmt	*fmt);
char	ft_apply_width(char *str, t_fmt *fmt);

int		ft_putchar_count(char c);
int		ft_putstr_count(char *str);

size_t	ft_strlen_printf(const char *str);
int		ft_isdigit_printf(int c);

#endif
