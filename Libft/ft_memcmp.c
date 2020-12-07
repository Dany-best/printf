/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:30:41 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/12 17:22:52 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	while (n--)
	{
		if ((*(unsigned char*)arr1) != (*(unsigned char*)arr2))
			return (*(unsigned char*)arr1 - *(unsigned char*)arr2);
		arr1++;
		arr2++;
	}
	return (0);
}
