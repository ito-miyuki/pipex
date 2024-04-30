/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:45:16 by mito              #+#    #+#             */
/*   Updated: 2024/04/30 16:28:35 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wait_processes(t_pipex *pipex)
{
	pid_t	pid;
	int		wstatus;

	while (1)
	{
		pid = wait(&wstatus);
		if (pid == -1 && errno == ECHILD)
			break ;
		if (WIFEXITED(wstatus) && pid == pipex->pids[pipex->num_processes - 1])
			pipex->status = WEXITSTATUS(wstatus);
	}
}
