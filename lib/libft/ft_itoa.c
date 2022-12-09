/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:06:03 by bderya            #+#    #+#             */
/*   Updated: 2022/03/29 17:06:03 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_cipher(int n)
{
	size_t	cipher;

	cipher = 0;
	if (n <= 0)
		cipher++;
	while (n)
	{
		n = n / 10;
		cipher++;
	}
	return (cipher);
}

char	*str_numb(char *number, unsigned int n, int cipher)
{
	while (n > 0)
	{
		number[cipher--] = n % 10 + '0';
		n = n / 10;
	}
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number_str;
	int		cipher;

	cipher = count_cipher(n);
	number_str = (char *)malloc(sizeof(char) * cipher + 1);
	if (!number_str)
		return (NULL);
	number_str[cipher--] = '\0';
	if (n == 0)
	{
		number_str[cipher] = '0';
		return (number_str);
	}
	if (n < 0)
	{
		n = -n;
		number_str[0] = '-';
	}
	number_str = str_numb(number_str, (unsigned int)n, cipher);
	return (number_str);
}
