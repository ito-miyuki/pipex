/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_execve_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:23:14 by mito              #+#    #+#             */
/*   Updated: 2024/04/29 14:24:25 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_outfile_error(t_pipex *pipex)
{
	const char	*error_message;

	error_message = strerror(errno);
	write(2, "pipex: ", 7);
	write(2, pipex->outfile, ft_strlen(pipex->infile));
	write(2, ": ", 2);
	write(2, error_message, ft_strlen(error_message));
	write(2, "\n", 1);
	ft_exit(pipex, NULL, 1, 1);
}

void	print_infile_error(t_pipex *pipex)
{
	const char	*error_message;

	error_message = strerror(errno);
	write(2, "pipex: ", 7);
	write(2, pipex->infile, ft_strlen(pipex->infile));
	write(2, ": ", 2);
	write(2, error_message, ft_strlen(error_message));
	write(2, "\n", 1);
	ft_exit(pipex, NULL, 1, 1); // close pipes
}

void	print_execve_error(t_pipex *pipex, char *cmd_name)
{
	const char	*error_message;

	error_message = strerror(errno);
	write(2, "pipex: ", 7);
	write(2, cmd_name, ft_strlen(cmd_name));
	write(2, ": ", 2);
	if (errno == ENOENT) // "No such file or directory"
	{
		if (pipex->paths == NULL) // path doesn't exisit
			ft_exit(pipex, error_message, 0, 127);
		else // path is wrong
		{
			if ((ft_starts_with(cmd_name, "/"))
				|| (ft_starts_with(cmd_name, "./"))
				|| (ft_ends_with(cmd_name, "/")))
				ft_exit(pipex, error_message, 0, 127);
			else
				ft_exit(pipex, "command not found", 0, 127);
		}
	}
	else if (errno == EACCES || errno == EISDIR)
		ft_exit(pipex, error_message, 0, 126); // close pipes?
	else
		ft_exit(pipex, error_message, 0, 1);
}
