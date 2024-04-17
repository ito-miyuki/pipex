/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:30:38 by mito              #+#    #+#             */
/*   Updated: 2024/04/17 19:15:30 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// typedef struct s_pipex
// {
// 	char	*input;
// 	char	*output;
// 	char	***commands;
// 	int		**pipes; // to point each pipes
// 	int		num_cmds;
// 	int		num_processes;
// 	int		num_pipes;
// 	int		status; // to store execve's return value
//  char	**paths;
// }				t_pipex;

//  for example,
// ./pipex infile "ls -l" "wc -l" outfile
//$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
//
// ./pipex here_doc LIMITER cmd cmd1 file


static char	***init_commands(char **av_cmds, int num_cmds, t_pipex *pipex)
{
	char	***commands;
	int i;

	i = 0;
	commands = (char ***)ft_calloc(num_cmds + 1, sizeof(char **));
	if (commands == NULL)
		return (NULL);
	while (i < num_cmds)
	{
		commands[i] = ft_split(av_cmds[i], ' ');
		if (commands[i] == NULL)
		{
			clean_up(pipex);
			return (NULL);	
		}
		i++;
	}
	return (commands);
}

int		init_pipex(t_pipex *pipex, int argc, char **argv, char **paths) //argv here starts from infile
{
	pipex->infile = argv[0];
	pipex->outfile = argv[argc - 1];
	pipex->here_doc = 0;
	pipex->limiter = NULL;
	if (ft_strncmp(argv[0], "here_doc", 8) == 0)
	{
		pipex->here_doc = 1;
		pipex->limiter = argv[1];
		argc--;
	}	
	pipex->paths = paths;
	pipex->num_cmds = argc - 2; // argc - infile - outfile
	pipex->num_processes = argc - 2;
	pipex->num_pipes = (pipex->num_processes - 1);
	pipex->commands = init_commands(argv + pipex->here_doc + 1, pipex->num_cmds, pipex); //start from cmd1
	if (pipex->commands == NULL)
		return (-1);
	pipex->pipes = malloc(sizeof(int *) * (pipex->num_pipes));
	if (!pipex->pipes)
		return (-1);
	pipex->status = 0;
	return (0);
}



