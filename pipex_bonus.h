/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:56:27 by mito              #+#    #+#             */
/*   Updated: 2024/04/17 18:46:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <fcntl.h> // for open
# include <stdio.h> // for printf/testing. delete it if you don't need it!
# include <unistd.h> // for pipe function
# include <errno.h>

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	***commands;
	int		**pipes;
	int		num_cmds;
	int		num_processes;
	int		num_pipes;
	int		status; // to store execve's return value
	char	**paths;
	int		here_doc;
	char	*limiter;
}				t_pipex;

int		init_pipex(t_pipex *pipex, int argc, char **argv, char **paths);
char	**get_path(char **envp);
int		create_pipes(t_pipex *pipex);
void	clean_up(t_pipex *pipex);

int		start_process(t_pipex *pipex);
void	first_child_process(t_pipex *pipex, int cmd_index);
void	last_child_process(t_pipex *pipex, int cmd_index);
void	middle_child_process(t_pipex *pipex, int cmd_index);

char	*ft_join_strings(int num_of_strings, ...);
int		call_execve(char **paths, char **command);

int		close_pipes(t_pipex *pipex);
void	wait_processes(t_pipex *pipex);

#endif