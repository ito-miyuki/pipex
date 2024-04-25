/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:21:03 by mito              #+#    #+#             */
/*   Updated: 2024/04/25 10:23:18 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	middle_child_process(t_pipex *pipex, int cmd_index)
{
	if (dup2(pipex->pipes[cmd_index][1], STDOUT_FILENO) < 0) // write for the next pipe
	{
		write_and_clean_up(pipex);
		exit(1);
		//should I close pipes?
	}
	if (dup2(pipex->pipes[cmd_index - 1][0], STDIN_FILENO) < 0) // read from previous pipe
	{
		write_and_clean_up(pipex);
		exit(1);
		//should I close pipes?
	}
	close_pipes(pipex);
	call_execve(pipex->paths, pipex->commands[cmd_index]);
	print_execve_error(pipex, *pipex->commands[cmd_index]);
}
