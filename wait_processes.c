/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:45:16 by mito              #+#    #+#             */
/*   Updated: 2024/04/29 19:32:20 by mito             ###   ########.fr       */
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
		if (wait(&wstatus) == -1 && errno == ECHILD)
			break ;
		if (WIFEXITED(wstatus))
		{
			pipex->status = WEXITSTATUS(wstatus);
			//write(2, "WEXITSTATUS(wstatus) = ", 23);
			//ft_putnbr_fd(WEXITSTATUS(wstatus), 2);
			//write(2, "\n", 1);
		}
		i++;
	}
}
