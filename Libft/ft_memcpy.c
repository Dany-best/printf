/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:57:46 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/12 17:23:56 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	void *ptr;

	ptr = destination;
	if (!destination && !source)
		return (0);
	while (n--)
		*(char*)destination++ = *(char*)source++;
	return (ptr);
}
