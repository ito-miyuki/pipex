/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:21:03 by mito              #+#    #+#             */
/*   Updated: 2024/04/16 16:25:50 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	middle_child_process(t_pipex *pipex, int cmd_index)
{
	int	i;
	// int	j;

	// //printf("command idx is %d\n", cmd_index);
	i = cmd_index - 1;
	// //printf("i in middle process is %d\n", i);
	// j = cmd_index + 1;
	dup2(pipex->pipes[cmd_index][1], STDOUT_FILENO); // write for the next pipe
	dup2(pipex->pipes[i][0], STDIN_FILENO); // read from previous pipe
	close_pipes(pipex);
	call_execve(pipex->paths, pipex->commands[cmd_index]);
	clean_up(pipex);
	exit(1); // need to modify it later depends on error type
}