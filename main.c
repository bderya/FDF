/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:09:56 by bderya            #+#    #+#             */
/*   Updated: 2022/08/19 18:40:09 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./lib/mlx/mlx.h"

int	deal_key(int key, t_fdf *data)
{
	if (key == 126 || key == 13)
		data->shift_y -= 10;
	if (key == 125 || key == 1)
		data->shift_y += 10;
	if (key == 123 || key == 0)
		data->shift_x -= 10;
	if (key == 124 || key == 2)
		data->shift_x += 10;
	if (key == 12)
		data->zoom += 2;
	if (key == 14)
		data->zoom -= 2;
	if (key == 53)
	{
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2)
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		read_file(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
		data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
		init(data);
		draw(data);
		mlx_key_hook(data->win_ptr, &deal_key, data);
		mlx_hook(data->win_ptr, 2, 1L << 17, &deal_key, data);
		mlx_hook(data->win_ptr, 17, 1L << 17, &kills, data);
		mlx_loop(data->mlx_ptr);
		return (0);
	}
	else
		write(1, "Please Enter only 1 file\n", 26);
}
