/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:35:52 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/13 15:37:30 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			get_word_cnt(char const *s, char c)
{
	size_t cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static const char		*ptr_return(char const *s, char c)
{
	while (*s && *s != c)
		++s;
	return (s);
}

static void				*ft_free(char **s, int length)
{
	while (--length)
	{
		free(s[length]);
	}
	free(s[length]);
	return (0);
}

char					**ft_split(char const *s, char c)
{
	char	**ret;
	char	*from;
	size_t	idx;
	size_t	size;

	if (!s || (!(ret = (char**)malloc(sizeof(char*) *
						(get_word_cnt(s, c) + 1)))))
		return (NULL);
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char*)s;
			s = ptr_return(s, c);
			size = s - from + 1;
			if (!(ret[idx] = (char*)malloc(sizeof(char) * size)))
				return (ft_free(ret, idx));
			ft_strlcpy(ret[idx++], from, size);
		}
		else
			++s;
	}
	ret[idx] = 0;
	return (ret);
}
