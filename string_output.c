/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:27:06 by drarlean          #+#    #+#             */
/*   Updated: 2020/12/07 17:57:28 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		width_str_check(char *s, int *width, int *length)
{
	*width = (g_format_info->width) - (int)ft_strlen(s);
	width_output(length, *width);
	ft_putstr_fd(s, 1);
	*length += ft_strlen(s);
}

void			minus_output(int width, int *length, char *s)
{
	if (g_format_info->minus == 1 && s)
	{
		while (width-- > 0)
		{
			ft_putchar_fd(' ', 1);
			++(*length);
		}
	}
}

void			string_output(char *s, int *length)
{
	int		width;
	int		precision;

	width = g_format_info->width;
	precision = g_format_info->precision;
	if (!s)
		s = "(null)";
	if (precision >= 0 && precision <= (int)ft_strlen(s))
	{
		if (g_format_info->width > 0)
		{
			width = g_format_info->width - g_format_info->precision;
			width_output(length, width);
		}
		*length += g_format_info->precision;
		if (!s)
			s = ft_substr("(null)", 0, g_format_info->precision);
		else
			s = ft_substr(s, 0, g_format_info->precision);
		ft_putstr_fd(s, 1);
		free(s);
	}
	else
		width_str_check(s, &width, length);
	minus_output(width, length, s);
}
