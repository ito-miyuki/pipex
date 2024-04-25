/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:28:50 by mito              #+#    #+#             */
/*   Updated: 2024/04/25 14:59:51 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int ft_starts_with(const char *string, const char *search_string)
{
    size_t  string_len;
    size_t  search_string_len;
    size_t  i;
    
    if (*search_string == '\0')
        return (1);
    string_len = ft_strlen(string);
    search_string_len = ft_strlen(search_string);
    if (string_len < search_string_len)
        return (0);
    i = 0;
    while (i < search_string_len)
    {
        if (string[i] != search_string[i])
            return (0);
            i++;
    }
    return (1);
}

int	ft_ends_with(const char *string, const char *search_string)
{
	size_t		ss_length;
	size_t		string_length;
	const char	*temp;

	ss_length = ft_strlen(search_string);
	if (ss_length == 0)
		return (1);
	string_length = ft_strlen(string);
	if (ss_length > string_length)
		return (0);
	temp = string + string_length - ss_length;
	while (*temp != '\0' && *search_string != '\0')
	{
		if (*temp != *search_string)
			return (0);
		temp++;
		search_string++;
	}
	return (1);
}

static int    try_read(const char *pathname)
{
    int        fd;
    char    buf;

    fd = open(pathname, O_RDONLY);
    if (fd < 0)
        return (-1);
    if (read(fd, &buf, 1) < 0) // if it can read, then it is a file
    {
        close(fd);
        return (-1);
    }
    if (close(fd) < 0)
        return (-1);
    return (0);
}

static int    handle_pathname(char **command)
{
    if (command[0][0] == '\0')
        return (execve(command[0], command, NULL));
    if (ft_starts_with(command[0], "/") || ft_starts_with(command[0], "./"))
    {
        if (try_read(command[0]) < 0 && errno == EISDIR)
            return (-1);
        return (execve(command[0], command, NULL));
    }
    return (0);
}

int    call_execve(char **paths, char **command)
{
    char    *cmd_path;
    int        status;

    if (handle_pathname(command) < 0)
        return (-1);
    status = 0;
    while (paths != NULL && *paths != NULL)
    {
        cmd_path = ft_join_strings(3, *paths, "/", command[0]);
        if (cmd_path == NULL)
            return (-1);
        if (access(cmd_path, X_OK) == 0)
            status = execve(cmd_path, command, NULL);
        free(cmd_path);
        if (status == -1)
            return (-1);
        paths++;
    }
    return (execve(command[0], command, NULL));
}