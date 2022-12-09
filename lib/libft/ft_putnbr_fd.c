/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:06:21 by bderya            #+#    #+#             */
/*   Updated: 2022/03/29 17:06:21 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	abs_val(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	ret[13];
	int		is_negative;
	int		str_idx;
	int		last_digit;

	is_negative = n < 0;
	ft_bzero(ret, 13);
	if (n == 0)
		ret[0] = '0';
	str_idx = 0;
	while (n != 0)
	{
		last_digit = abs_val(n % 10);
		n /= 10;
		ret[str_idx++] = '0' + last_digit;
	}
	if (is_negative)
		ret[str_idx] = '-';
	else if (str_idx > 0)
		str_idx--;
	while (str_idx >= 0)
		write(fd, &ret[str_idx--], 1);
}
