/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:42:45 by bderya            #+#    #+#             */
/*   Updated: 2022/08/17 10:58:50 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_line(int fd, char *string)
{
	char	*temp;
	int		byte_size;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	byte_size = 1;
	while (!ft_strchr_gnl(string, '\n') && (byte_size != 0))
	{
		byte_size = read(fd, temp, BUFFER_SIZE);
		if (byte_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[byte_size] = '\0';
		string = ft_strjoin_gnl(string, temp);
	}
	free(temp);
	return (string);
}

char	*get_line(char *string)
{
	int		i;
	char	*line;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		line[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		line[i] = string[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *string)
{
	char	*restof;
	int		i;
	int		j;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	restof = (char *)malloc(sizeof(char) * (ft_strlen_gnl(string) - i + 1));
	if (!restof)
		return (NULL);
	i++;
	j = 0;
	while (string[i])
		restof[j++] = string[i++];
	restof[j] = '\0';
	free(string);
	return (restof);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (read(fd, 0, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	string = get_read_line(fd, string);
	if (!string)
		return (NULL);
	line = get_line(string);
	string = get_rest(string);
	return (line);
}
