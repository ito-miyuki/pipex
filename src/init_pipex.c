/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:30:38 by mito              #+#    #+#             */
/*   Updated: 2024/04/30 17:35:45 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	***init_commands(char **av_cmds, int num_cmds, t_pipex *pipex)
{
	char	***commands;
	int		i;

	i = 0;
	commands = (char ***)ft_calloc(num_cmds + 1, sizeof(char **));
	if (commands == NULL)
		return (NULL);
	while (i < num_cmds)
	{
		commands[i] = ft_parse_cmd(av_cmds[i]);
		if (commands[i] == NULL)
		{
			clean_up(pipex);
			return (NULL);
		}
		i++;
	}
	return (commands);
}

static int	init_pids(t_pipex *pipex, int num_processes)
{
	pipex->pids = (pid_t *)malloc(num_processes * sizeof(pid_t));
	if (pipex->pids == NULL)
		return (-1);
	pipex->num_processes = num_processes;
	return (0);
}

int	init_pipex(t_pipex *pipex, int argc, char **argv, char **paths)
{
	pipex->infile = argv[0];
	pipex->outfile = argv[argc - 1];
	pipex->here_doc = 0;
	if (ft_strncmp(argv[0], "here_doc", 8) == 0)
	{
		pipex->here_doc = 1;
		pipex->limiter = argv[1];
		argc--;
	}
	pipex->paths = paths;
	pipex->num_cmds = argc - 2;
	if (init_pids(pipex, argc - 2) < 0)
		return (-1);
	pipex->num_pipes = (pipex->num_processes - 1);
	pipex->commands = init_commands(argv + pipex->here_doc + 1,
			pipex->num_cmds, pipex);
	if (pipex->commands == NULL)
		return (-1);
	pipex->pipes = malloc(sizeof(int *) * (pipex->num_pipes));
	if (!pipex->pipes)
		return (-1);
	pipex->status = 0;
	return (0);
}
