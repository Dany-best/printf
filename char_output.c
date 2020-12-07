/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:59:17 by drarlean          #+#    #+#             */
/*   Updated: 2020/12/07 17:01:29 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_output(char c, int *length)
{
	int width;

	width = g_format_info->width - 1;
	width_output(length, width);
	ft_putchar_fd(c, 1);
	++(*length);
	if (g_format_info->minus == 1)
	{
		width += 1;
		while (--width > 0)
		{
			ft_putchar_fd(' ', 1);
			++(*length);
		}
	}
}
