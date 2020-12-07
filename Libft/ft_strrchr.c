/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:49:05 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/12 18:26:25 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = (int)ft_strlen(str) + 1;
	while (i--)
	{
		if (*(str + i) == (char)ch)
			return ((char*)str + i);
	}
	return (0);
}
