/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:09:56 by bderya            #+#    #+#             */
/*   Updated: 2022/08/19 14:59:04 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"
# include "./get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct coords
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}				t_coords;

typedef struct fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;

	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;

	char	*addr;
}			t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	bresnham(t_coords coords, t_fdf *data);
void	draw(t_fdf *data);
void	init(t_fdf *data);
void	error_exit(char *str, t_fdf *data);
void	error_exit_2(char *str);
float	mod(float a);
float	abs2(float a, float b);
float	color(float a, float b);
int		kills(t_fdf *data);

#endif