/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:23:21 by mito              #+#    #+#             */
/*   Updated: 2024/02/09 12:20:36 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

static char	*read_line(int fd, char *remainder)
{
	int		chars_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;

	while (!(ft_strchr(remainder, '\n')))
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
			return (free_str(&remainder));
		if (chars_read == 0)
			break ;
		buffer[chars_read] = '\0';
		temp = ft_strjoin(remainder, buffer);
		if (!temp)
		{
			if (remainder)
				return (free_str(&remainder));
		}
		if (remainder)
			free_str(&remainder);
		remainder = temp;
	}
	return (remainder);
}

static char	*find_newline(char **buffer)
{
	char		*newline;
	char		*line;
	int			line_len;
	char		*temp;

	newline = ft_strchr(*buffer, '\n');
	if (newline)
		line_len = newline - *buffer + 1;
	else
		line_len = ft_strlen(*buffer);
	line = ft_strndup(*buffer, line_len);
	if (!line)
		return (free_str(buffer));
	if (newline && *(newline + 1) != '\0')
	{
		temp = ft_strndup(newline + 1, ft_strlen(newline + 1));
		free_str(buffer);
		if (!temp)
			return (free_str(&line));
		*buffer = temp;
	}
	else
		free_str(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder[1024];

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder[fd])
	{
		remainder[fd] = ft_strndup("", 0);
		if (!remainder[fd])
			return (NULL);
	}
	remainder[fd] = read_line(fd, remainder[fd]);
	if (!remainder[fd] || *remainder[fd] == '\0')
	{
		return (free_str(&remainder[fd]));
	}
	return (find_newline(&remainder[fd]));
}
