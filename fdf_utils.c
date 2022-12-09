/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:25:19 by bderya            #+#    #+#             */
/*   Updated: 2022/08/19 00:08:52 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	abs2(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod(float a)
{
	if (0 > a)
		return (-a);
	else
		return (a);
}

float	color(float a, float b)
{
	if (a > 0 || b > 0)
		return (0xE80C0C);
	if (a < 0 || b < 0)
		return (0x1DE327);
	else
		return (0xFFFFFF);
}
