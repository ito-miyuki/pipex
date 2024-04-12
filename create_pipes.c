/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:29:21 by mito              #+#    #+#             */
/*   Updated: 2024/04/12 11:26:19 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	create_pipes(t_pipex *pipex)
{
	int i;
	
	i = 0;
	while (i < pipex->num_pipes)
	{
		if (pipe(pipex->pipes[i]) < 0)
		{
			clean_up(pipex);
			return (-1);
		}
		i++;
	}
	return (0);
}