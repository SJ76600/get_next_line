/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:28:23 by sjupille          #+#    #+#             */
/*   Updated: 2025/01/17 10:06:49 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_read_line(int fd, char *line)
{
	ssize_t	bytes;
	char	*stash;

	stash = (char *)malloc(BUFFER_SIZE + 1);
	if (!stash)
		return (NULL);
	bytes = 1;
	while (!line || ((!ft_strchr(line, '\n')) && bytes > 0))
	{
		bytes = read(fd, stash, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(stash);
			free(line);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		stash[bytes] = '\0';
		line = ft_strjoin2(line, stash);
	}
	free(stash);
	return (line);
}

char	*ft_extract_line(char *line)
{
	char	*newline;
	int		i;

	i = 0;
	if (!line[i] || !line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	newline = (char *)malloc(i + 2);
	if (!newline)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		newline[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		newline[i++] = '\n';
	newline[i] = '\0';
	return (newline);
}

char	*ft_next_line(char *line)
{
	char	*data;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	data = (char *)malloc(sizeof(char) * (ft_strlen(line) - i) + 1);
	if (!data)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		data[j++] = line[i++];
	data[j] = '\0';
	free(line);
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	buffer = ft_read_line(fd, buffer);
	if (buffer == NULL)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_extract_line(buffer);
	buffer = ft_next_line(buffer);
	if (!line)
		free(buffer);
	return (line);
}
