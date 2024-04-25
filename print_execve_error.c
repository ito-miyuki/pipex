/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_execve_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:23:14 by mito              #+#    #+#             */
/*   Updated: 2024/04/25 14:47:25 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"


void	print_outfile_error(t_pipex *pipex)
{
	//printf("print_outfile_error func\n");
	const char *error_message;
	error_message = strerror(errno);

	write(2, "pipex: ", 7);
	write(2, pipex->outfile, ft_strlen(pipex->infile));
	write(2, ": ", 2);
	write(2, error_message, ft_strlen(error_message));
	write(2, "\n", 1);
}

void	print_infile_error(t_pipex *pipex)
{
	//printf("print_infile_error func\n");
	const char *error_message;
	error_message = strerror(errno);

	write(2, "pipex: ", 7);
	write(2, pipex->infile, ft_strlen(pipex->infile));
	write(2, ": ", 2);
	write(2, error_message, ft_strlen(error_message));
	write(2, "\n", 1);
}

void	print_execve_error(t_pipex *pipex, char *cmd_name)
{
	//printf("print_execve_error func\n");
	const char *error_message;
	
	error_message = strerror(errno);
	write(2, "pipex: ", 7);
	write(2, cmd_name, ft_strlen(cmd_name));
	write(2, ": ", 2);
	if (errno == ENOENT) // "No such file or directory"
	{
		if ((ft_starts_with(cmd_name, "/"))
			|| (ft_starts_with(cmd_name, "./"))
			|| (ft_ends_with(cmd_name, "/")))
			{
				write(2, error_message, ft_strlen(error_message));
				write(2, "\n", 1);
				ft_exit(pipex, 127);
			}
		else
		{
			write(2, "command not found\n", 18);
			ft_exit(pipex, 127);
		}
	}
	else if (errno == EACCES || errno == EISDIR) //No access || the path is a directory
	{
			write(2, error_message, ft_strlen(error_message)); // need to write in stderror
			write(2, "\n", 1);
			ft_exit(pipex, 126);
	}
	else
	{
		write(2, error_message, ft_strlen(error_message)); // need to write in stderror
		write(2, "\n", 1);
		ft_exit(pipex, 1);
	}
}

// void	ft_exit(t_pipex *pipex, const char *err_msg,
// 				t_bool should_close_pipes, int exit_code)
// {
// 	if (err_msg != NULL)
// 		ft_putendl_fd((char *)err_msg, 2);
// 	if (should_close_pipes)
// 		close_pipes(pipex->pipes);
// 	cleanup(pipex);
// 	exit(exit_code);
// }