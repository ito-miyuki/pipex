/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:20:42 by mito              #+#    #+#             */
/*   Updated: 2024/04/30 17:20:44 by mito             ###   ########.fr       */
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
