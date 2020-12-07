/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_output.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:39:40 by drarlean          #+#    #+#             */
/*   Updated: 2020/12/07 17:43:16 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_width(int *length, int *width, char *str)
{
	if (g_format_info->minus == 1)
	{
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
		ft_putstr_fd(str, 1);
	}
}

void			u_output(unsigned int arg, int *length, const char *base)
{
	char	*str;
	int		num_len;
	int		width;
	int		diff;
	int		flag;

	str = ft_utoa(arg, base);
	num_len = ft_strlen(str);
	diff = 0;
	flag = 0;
	check_precision(&str, &diff, &num_len, &flag);
	width = (g_format_info->width) - (int)ft_strlen(str);
	if (g_format_info->zero == 1 && g_format_info->width > num_len && !flag
			&& g_format_info->minus != 1)
	{
		create_zero_str(&diff, &str, num_len, g_format_info->width);
		width = 0;
	}
	print_width(length, &width, str);
	*length += num_len + diff;
	free(str);
}
