/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:58:19 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/12 16:59:35 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *mem;

	if (!(mem = (char*)malloc(nmemb * size)))
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
