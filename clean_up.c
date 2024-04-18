/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:34:03 by mito              #+#    #+#             */
/*   Updated: 2024/04/18 12:50:41 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_grid(char **grid)
{
	size_t	i;

	i = 0;
	if (grid == NULL)
		return ;
	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static void	delete_commands(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->commands != NULL && pipex->commands[i] != NULL)
	{
		free_grid(pipex->commands[i]);		
		i++;
	}
	free(pipex->commands);
	pipex->commands = NULL;
}

void	write_and_clean_up(t_pipex *pipex)
{
	write(2, "Error", 5);
	clean_up(pipex);
}
void	clean_up(t_pipex *pipex)
{
	delete_commands(pipex);
}