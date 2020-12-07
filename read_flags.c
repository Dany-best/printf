/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:15:20 by drarlean          #+#    #+#             */
/*   Updated: 2020/12/07 17:21:13 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			read_precision(const char **format)
{
	char c;

	c = **format;
	if (c == '*')
	{
		g_format_info->precision = va_arg(g_opa, int);
		++(*format);
		return (1);
	}
	if (ft_isdigit(c))
	{
		g_format_info->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			++(*format);
	}
	else
		return (0);
	return (1);
}

int			read_width(const char **format)
{
	char c;

	c = **format;
	if (c == '*')
	{
		g_format_info->width = va_arg(g_opa, int);
		if (g_format_info->width < 0)
		{
			g_format_info->minus = 1;
			g_format_info->width *= -1;
		}
		++(*format);
		return (1);
	}
	if (ft_isdigit(c))
	{
		g_format_info->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			++(*format);
	}
	else
		return (0);
	return (1);
}

int			read_flags(const char **format)
{
	char c;

	c = **format;
	if (c == '-')
	{
		g_format_info->minus = 1;
		++(*format);
	}
	else if (c == '0' && g_format_info)
	{
		g_format_info->zero = 1;
		++(*format);
	}
	else if (c == '.')
	{
		g_format_info->precision = 0;
		++(*format);
		read_precision(format);
	}
	else
		return (0);
	return (1);
}
