/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:59:18 by mito              #+#    #+#             */
/*   Updated: 2024/04/12 17:24:02 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child_process(t_pipex *pipex, int cmd_index)
{
	int in_fd;

	in_fd = open(pipex->infile, O_RDONLY);
	if (in_fd < 0)
	{
		clean_up(pipex);
		exit (EXIT_FAILURE);
	}
	//int execve(const char *pathname, char *const argv[], char *const envp[]);
	// "/bin/pipex->commands[cmd_index]"
	call_execve(pipex->paths, pipex->commands[cmd_index]);
}
