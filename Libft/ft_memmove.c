/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:07:53 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/12 17:24:51 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	void *ret;

	if (!destination && !source)
		return (0);
	ret = destination;
	if (source < destination)
	{
		source += n;
		destination += n;
		while (n--)
		{
			*(char*)--destination = *(char*)--source;
		}
	}
	else
		while (n--)
			*(char*)destination++ = *(char*)source++;
	return (ret);
}
