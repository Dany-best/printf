/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:29:44 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/12 17:22:19 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	void *point;

	point = (void*)arr;
	while (n--)
	{
		if (*(char*)point == (char)c)
			return (point);
		++point;
	}
	return (0);
}
