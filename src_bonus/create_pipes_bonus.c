/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:20:56 by mito              #+#    #+#             */
/*   Updated: 2024/04/30 17:20:59 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->num_pipes)
	{
		pipex->pipes[i] = malloc(sizeof(int) * 2);
		if (!pipex->pipes[i])
		{
			clean_up(pipex);
			return (-1);
		}
		if (pipe(pipex->pipes[i]) < 0)
		{
			clean_up(pipex);
			return (-1);
		}
		i++;
	}
	return (0);
}
