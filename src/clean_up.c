/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:34:03 by mito              #+#    #+#             */
/*   Updated: 2024/05/02 17:38:17 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_pipes(t_pipex *pipex, int **pipes)
{
	int	i;

	i = 0;
	if (pipes == NULL)
		return ;
	while (i < pipex->num_pipes)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	free_grid(char **grid)
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
	free(pipex->pids);
	if (pipex->commands)
		delete_commands(pipex);
	if (pipex->paths)
		free_grid(pipex->paths);
	if (pipex->pipes)
		free_pipes(pipex, pipex->pipes);
}
