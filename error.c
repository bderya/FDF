/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 00:08:57 by bderya            #+#    #+#             */
/*   Updated: 2022/08/19 14:57:20 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(char *str, t_fdf *data)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	free(data);
	exit(0);
}

void	error_exit_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	exit(0);
}

int	kills(t_fdf *data)
{
	free(data);
	exit(0);
	return (0);
}
