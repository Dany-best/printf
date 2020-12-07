/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:06:49 by drarlean          #+#    #+#             */
/*   Updated: 2020/12/07 17:12:23 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		minus_print(int *length, int arg)
{
	if (arg < 0)
	{
		ft_putchar_fd('-', 1);
		++(*length);
	}
}

static void		print_width(int arg, int *length, int *width, char *str)
{
	if (arg < 0)
		--(*width);
	if (g_format_info->minus == 1)
	{
		minus_print(length, arg);
		ft_putstr_fd(str, 1);
		while ((*width)-- > 0)
		{
			ft_putchar_fd(' ', 1);
			++(*length);
		}
	}
	else
	{
		while ((*width)-- > 0)
		{
			ft_putchar_fd(' ', 1);
			++(*length);
		}
		minus_print(length, arg);
		ft_putstr_fd(str, 1);
	}
}

void			decimal_output(int arg, int *length)
{
	char	*str;
	int		num_len;
	int		width;
	int		diff;
	int		flag;

	str = ft_itoa(arg);
	num_len = ft_strlen(str);
	diff = 0;
	flag = 0;
	check_precision(&str, &diff, &num_len, &flag);
	width = (g_format_info->width) - (int)ft_strlen(str);
	if (g_format_info->zero == 1 && g_format_info->width > num_len && !flag
			&& g_format_info->minus != 1)
	{
		if (arg < 0)
			g_format_info->width -= 1;
		create_zero_str(&diff, &str, num_len, g_format_info->width);
		width = 0;
	}
	print_width(arg, length, &width, str);
	*length += num_len + diff;
	free(str);
}
