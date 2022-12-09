/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:07:12 by bderya            #+#    #+#             */
/*   Updated: 2022/08/19 14:54:56 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		close (fd);
		error_exit("Error: ****", data);
	}
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	free(line);
	close (fd);
	return (height);
}

int	ft_wdcount(char *line, char ch)
{
	int	count_words;

	count_words = 0;
	while (*line == ch && *line)
		++line;
	while (*line)
	{
		++count_words;
		while (*line != ch && *line)
			++line;
		while (*line == ch && *line)
			++line;
	}
	return (count_words);
}

int	get_width(char *file_name, t_fdf *data)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		close (fd);
		error_exit("Error: ****", data);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		close (fd);
		error_exit("Error: ****", data);
		exit (0);
	}
	width = ft_wdcount(line, ' ');
	free(line);
	close (fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	if (!nums)
		error_exit_2("Error: file");
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;	

	data->height = get_height(file_name, data);
	data->width = get_width(file_name, data);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data -> height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close (fd);
}
