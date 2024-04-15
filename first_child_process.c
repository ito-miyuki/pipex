/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:59:18 by mito              #+#    #+#             */
/*   Updated: 2024/04/15 18:36:42 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child_process(t_pipex *pipex, int cmd_index)
{
	int in_fd;

	dup2(pipex->pipes[0][1], STDOUT_FILENO);
	close_pipes(pipex);

	in_fd = open(pipex->infile, O_RDONLY);
	if (in_fd < 0)
	{
		clean_up(pipex);
		exit (EXIT_FAILURE);
	}
	dup2(in_fd, STDIN_FILENO); // STDIN_FILENO is now poiting to in_fd
	close(in_fd);
	/*
	execve() function will always read input from STDIN_FILENO and write output to STDOUT_FILENO
	so what we have to do is we tell execve() to read from in_fd and write output to write-end pipe.
	Therefore we will redirect STDIN_FILE to in_fd so execve() will now read data directly from in_fd
	and we also need to redirect STDOUT_FILE to write-end pipe so other process and read output of execve
	from read-end pipe
	*/
	call_execve(pipex->paths, pipex->commands[cmd_index]);
	// From this line, error already happened in execve()
	clean_up(pipex);
	exit(1); // need to modify it later depends on error type
}
