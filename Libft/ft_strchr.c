/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:34:07 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/12 17:40:40 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = -1;
	while (++i < (int)ft_strlen(str) + 1)
	{
		if (*(str + i) == (char)ch)
			return ((char*)str + i);
	}
	return (0);
}
