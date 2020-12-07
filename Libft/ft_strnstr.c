/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:46:10 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/16 17:32:58 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	len_needle;

	if (!*needle)
		return ((char*)haystack);
	len_needle = ft_strlen(needle);
	if (!ft_strlen(haystack) || len < len_needle)
		return (0);
	len -= --len_needle;
	while (len-- && *haystack)
	{
		a = (char*)haystack;
		b = (char*)needle;
		while (*b && *a == *b)
		{
			++a;
			++b;
		}
		if (*b == 0)
			return ((char*)haystack);
		++haystack;
	}
	return (0);
}
