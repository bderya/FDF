/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:56:44 by bderya            #+#    #+#             */
/*   Updated: 2022/03/30 20:20:37 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
	{
		i++;
	}
	if ('+' == str[i] || '-' == str[i])
	{
		if ('-' == str[i])
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && '9' >= str[i])
	{
		res = res * 10 + ((str[i] - '0'));
		i++;
	}
	return (sign * (res));
}
