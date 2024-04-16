/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:45:16 by mito              #+#    #+#             */
/*   Updated: 2024/04/16 15:48:46 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wait_processes(t_pipex *pipex)
{
	int	i;
	int	wstatus;

	i = 0;
	while (i < pipex->num_processes)
	{
		if (wait(&wstatus) < 0 || errno == ECHILD)
			break ;
		if (WIFEXITED(wstatus))
			pipex->status = WEXITSTATUS(wstatus);
		i++;
	}
}
