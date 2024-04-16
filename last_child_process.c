/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:40:33 by mito              #+#    #+#             */
/*   Updated: 2024/04/16 10:47:35 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	last_child_process(t_pipex *pipex, int cmd_index)
{
	int	out_fd;
	dup2(pipex->pipes[pipex->num_pipes - 1][0], STDIN_FILENO); //STDIN_FILENO is pointing the last pipes
	close_pipes(pipex);

	out_fd = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644); // check 0644
	if (out_fd < 0)
	{
		clean_up(pipex);
		exit (EXIT_FAILURE);
	}
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	call_execve(pipex->paths, pipex->commands[cmd_index]);
	clean_up(pipex);
	exit(1); // need to modify it later depends on error type
}