/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:26:46 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/13 16:07:29 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_set(char a, char const *set)
{
	while (*set)
	{
		if (a == *set++)
			return (1);
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*start;
	char	*end;
	size_t	length;

	if (!s1)
		return (0);
	start = (char*)s1;
	end = start + ft_strlen(s1);
	while (*start && is_set(*start, set))
		++start;
	while (start < end && is_set(*(end - 1), set))
		--end;
	length = end - start + 1;
	if (!(str = (char*)malloc(sizeof(char) * length)))
		return (0);
	ft_strlcpy(str, start, length);
	return (str);
}
