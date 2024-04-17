/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:21:03 by mito              #+#    #+#             */
/*   Updated: 2024/04/17 10:29:08 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	middle_child_process(t_pipex *pipex, int cmd_index)
{
	dup2(pipex->pipes[cmd_index][1], STDOUT_FILENO); // write for the next pipe
	dup2(pipex->pipes[cmd_index - 1][0], STDIN_FILENO); // read from previous pipe
	close_pipes(pipex);
	call_execve(pipex->paths, pipex->commands[cmd_index]);
	clean_up(pipex);
	exit(1); // need to modify it later depends on error type
}