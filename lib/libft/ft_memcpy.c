/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:46:51 by bderya            #+#    #+#             */
/*   Updated: 2022/04/05 20:46:51 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return ((void *)dst);
}
