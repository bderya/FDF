/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:09:56 by bderya            #+#    #+#             */
/*   Updated: 2022/08/19 14:57:58 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	isometric(t_coords *coords, int z, int z1)
{
	coords->x = (coords->x - coords->y) * cos(0.523599);
	coords->y = (coords->x + coords->y) * sin(0.523599) - z;
	coords->x1 = (coords->x1 - coords->y1) * cos(0.523599);
	coords->y1 = (coords->x1 + coords->y1) * sin(0.523599) - z1;
}

void	zoom(t_coords *coords, t_fdf *data)
{
	coords->x *= data->zoom;
	coords->y *= data->zoom;
	coords->x1 *= data->zoom;
	coords->y1 *= data->zoom;
}

void	shifted(t_coords *coords, t_fdf *data)
{
	coords->x += data->shift_x;
	coords->y += data->shift_y;
	coords->x1 += data->shift_x;
	coords->y1 += data->shift_y;
}

void	bresnham(t_coords coords, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)coords.y][(int)coords.x];
	z1 = data->z_matrix[(int)coords.y1][(int)coords.x1];
	zoom(&coords, data);
	data->color = (color(z, z1));
	isometric(&coords, z, z1);
	shifted(&coords, data);
	x_step = coords.x1 - coords.x;
	y_step = coords.y1 - coords.y;
	max = abs2(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(coords.x - coords.x1) || (int)(coords.y - coords.y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, coords.x,
			coords.y, data->color);
		coords.x += x_step;
		coords.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	t_coords	coords;

	coords.y = 0;
	while (coords.y < data->height)
	{
		coords.x = 0;
		while (coords.x < data->width)
		{
			if (coords.x < data->width - 1)
			{
				coords.x1 = coords.x + 1;
				coords.y1 = coords.y;
				bresnham(coords, data);
			}
			if (coords.y < data->height - 1)
			{
				coords.x1 = coords.x;
				coords.y1 = coords.y + 1;
				bresnham(coords, data);
			}
			(coords.x)++;
		}
		(coords.y)++;
	}
}
