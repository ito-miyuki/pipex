/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:58:02 by mito              #+#    #+#             */
/*   Updated: 2024/04/15 18:56:31 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	close_pipes(t_pipex *pipex)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < pipex->num_pipes)
	{
		if (close(pipex->pipes[i][0]) < 0)
			status = -1;
		if (close(pipex->pipes[i][1]) < 0)
			status = -1;
		i++;
	}
	return (status);
}
