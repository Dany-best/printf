/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:21:03 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/12 17:21:16 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	while (n--)
	{
		*(char*)destination++ = *(char*)source++;
		if (*(char*)(destination - 1) == (char)c)
			return (destination);
	}
	return (0);
}
