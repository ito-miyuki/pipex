/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:03:14 by mito              #+#    #+#             */
/*   Updated: 2024/04/12 17:06:39 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	start_process(t_pipex *pipex)
{
	int pid;
	int	i;

	i = 0;
	while (i < pipex->num_processes)
	{
		pid = fork();
		// if (pid < 0) // means fork failed
		// {
		// 	close_pipes()
		// 	wait_all_running_processes_to_finish()
		// 	clean_u
		// 	return (-1);
		// }
		if (pid == 0)
		{
			if (i == 0) // for the first one, we need to open file
				first_child_process(pipex, i); // this i links to num_commands
			// else if (i == pipex->num_processes - 1)
			// 	last_child_process(pipex, i); // for the last one, we need to write output to file
			// else
			// 	middle_task(pipex, i);
		}
		i++;
	}
	// close pipe
	return (0);
}
