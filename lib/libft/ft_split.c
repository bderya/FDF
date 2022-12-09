/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:06:29 by bderya            #+#    #+#             */
/*   Updated: 2022/03/29 17:06:29 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (i < len)
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}

static int	split_separate2(char **arr, const char *str, char c, size_t w)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			len = 0;
			while (str[i + len] && str[i + len] != c)
				++len;
			arr[w] = (char *)malloc(sizeof(**arr) * (len + 1));
			if (!arr[w])
				return (0);
			arr[w] = my_strncpy(arr[w], &(str[i]), len);
			arr[w][len] = '\0';
			++w;
			i += len;
		}
		if (str[i])
			++i;
	}
	arr[w] = NULL;
	return (1);
}

static int	split_separate(char **arr, const char *str, char c)
{
	size_t	w;

	w = 0;
	split_separate2(arr, str, c, w);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	w;
	size_t	i;

	if (s == NULL)
		return (NULL);
	w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (!s[i + 1] || s[i + 1] == c))
			++w;
		++i;
	}
	arr = (char **)malloc(sizeof(char *) * (w + 1));
	if (!arr)
		return (NULL);
	if (!split_separate(arr, s, c))
		return (NULL);
	return (arr);
}
