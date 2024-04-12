/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:28:50 by mito              #+#    #+#             */
/*   Updated: 2024/04/12 17:18:55 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"


static int    ft_starts_with(const char *string, const char *search_string)
{
    size_t    string_len;
    size_t    search_string_len;
    size_t    i;

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


int    call_execve(char **paths, char **command)
{
    char    *cmd_path;
    int        status;

    if (paths == NULL || ft_starts_with(command[0], "/"))
        return (execve(command[0], command, NULL));
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