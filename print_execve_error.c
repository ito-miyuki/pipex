/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_execve_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:23:14 by mito              #+#    #+#             */
/*   Updated: 2024/04/23 17:36:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_file_error(t_pipex *pipex)
{
	const char *error_message;
	error_message = strerror(errno);

	write(2, "pipex: ", 7);
	write(2, error_message, ft_strlen(error_message));
	write(2, ": ", 2);
	write(2, pipex->infile, ft_strlen(pipex->infile));
	write(2, "\n", 1);
}

void	print_execve_error(char *cmd_name)
{
	const char *error_message;
	error_message = strerror(errno);

	if (errno == ENOENT) // "No such file or directory"
	{
		if ((ft_starts_with(cmd_name, "/"))
			|| (ft_starts_with(cmd_name, "./"))
			|| (ft_ends_with(cmd_name, "/")))
			{
				write(2, error_message, ft_strlen(error_message));
				write(2, "\n", 1);
				exit(1); //temp
			}
		else
		{
			write(2, "pipex: command not found: ", 26);
			write(2, cmd_name, ft_strlen(cmd_name));
			write(2, "\n", 1);
		 	exit(1); //temp
		}
	}
	if (errno == EACCES || errno == EISDIR) //No access || the path is a directory
	{
			write(2, error_message, ft_strlen(error_message)); // need to write in stderror
			write(2, "\n", 1);
			exit(1); //temp
	}
	write(2, error_message, ft_strlen(error_message)); // need to write in stderror
	write(2, "\n", 1);
	exit(1); //temp
}