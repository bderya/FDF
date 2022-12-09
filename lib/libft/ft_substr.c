/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:02:18 by bderya            #+#    #+#             */
/*   Updated: 2022/03/30 11:09:11 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen((const char *)s);
	if (len > len_s)
		len = len_s;
	if (start >= len_s)
		return ((char *)ft_calloc(sizeof(char), 1));
	i = 0;
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (len-- && s[i + (int)start])
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
