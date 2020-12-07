/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:24:20 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/12 16:57:44 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		my_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int				ft_atoi(const char *str)
{
	int						is_negative;
	unsigned long long int	result;

	result = 0;
	is_negative = 1;
	while (my_isspace(*str + '\0'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = -1;
		str++;
	}
	while (ft_isdigit(*str + '\0'))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	if (result > 9223372036854775807)
		return (is_negative == 1 ? -1 : 0);
	return ((int)(result * is_negative));
}
