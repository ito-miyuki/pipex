/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:03:14 by mito              #+#    #+#             */
/*   Updated: 2024/04/23 16:46:58 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	run_process(t_pipex *pipex, int process_idx)
{
	if (process_idx == 0)
		first_child_process(pipex, process_idx);
	else if (process_idx == pipex->num_processes - 1)
		last_child_process(pipex, process_idx);
	else
		middle_child_process(pipex, process_idx);
}

int	start_process(t_pipex *pipex)
{
	int	pid;
	int	i;

	i = 0;
	while (i < pipex->num_processes)
	{
		pid = fork();
		if (pid < 0)
		{
			write_and_clean_up(pipex);
			close_pipes(pipex);
			wait_processes(pipex);
			return (-1);
		}
		if (pid == 0)
			run_process(pipex, i);
		i++;
	}
	if (close_pipes(pipex) < 0)
		return (-1);
	return (0);
}
