/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:43:04 by drarlean          #+#    #+#             */
/*   Updated: 2020/12/25 15:52:21 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf.h"

t_format_info			*g_format_info;
va_list					g_opa;
char					*g_hex_base_lowercase = "0123456789abcdef";
char					*g_hex_base_uppercase = "0123456789ABCDEF";
char					*g_dec = "0123456789";

void			detect_type(int *length)
{
	char c;

	c = g_format_info->type;
	if (c == 'c')
		char_output(va_arg(g_opa, int), length);
	else if (c == 's')
		string_output(va_arg(g_opa, char *), length);
	else if (c == 'd' || c == 'i')
		decimal_output(va_arg(g_opa, int), length);
	else if (c == 'p')
		ptr_output(va_arg(g_opa, unsigned long long), length);
	else if (c == 'x')
		x_output(va_arg(g_opa, unsigned int), length, g_hex_base_lowercase);
	else if (c == 'X')
		x_output(va_arg(g_opa, unsigned int), length, g_hex_base_uppercase);
	else if (c == 'u')
		u_output(va_arg(g_opa, unsigned int), length, g_dec);
	else
		char_output(c, length);
}

static void		init_struct(void)
{
	g_format_info->minus = 0;
	g_format_info->zero = 0;
	g_format_info->width = 0;
	g_format_info->precision = -1;
	g_format_info->type = '0';
}

void			parse(const char *format, int *length)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			init_struct();
			while (read_flags(&format) || read_width(&format))
				;
			if (!(g_format_info->type = *format))
				break ;
			format++;
			detect_type(length);
		}
		else
		{
			ft_putchar_fd(*format++, 1);
			++(*length);
		}
	}
}

int				ft_printf(const char *format, ...)
{
	int length;

	length = 0;
	if (!(g_format_info = malloc(sizeof(t_format_info))))
		return (-1);
	va_start(g_opa, format);
	parse(format, &length);
	free((g_format_info));
	va_end(g_opa);
	return (length);
}
