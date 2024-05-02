/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:56:27 by mito              #+#    #+#             */
/*   Updated: 2024/05/02 18:38:51 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	***commands;
	pid_t	*pids;
	int		**pipes;
	int		num_cmds;
	int		num_processes;
	int		num_pipes;
	int		status;
	char	**envp;
	char	**paths;
	int		here_doc;
	char	*limiter;
}				t_pipex;

int		init_pipex(t_pipex *pipex, int argc, char **argv, char **paths);
char	**get_path(char **envp);
int		create_pipes(t_pipex *pipex);
void	free_grid(char **grid);
void	clean_up(t_pipex *pipex);
void	write_and_clean_up(t_pipex *pipex);

int		start_process(t_pipex *pipex);
void	first_child_process(t_pipex *pipex, int cmd_index);
void	last_child_process(t_pipex *pipex, int cmd_index);
void	middle_child_process(t_pipex *pipex, int cmd_index);

char	*ft_join_strings(int num_of_strings, ...);
int		call_execve(char **envp, char **paths, char **command);
int		ft_starts_with(const char *string, const char *search_string);
int		ft_ends_with(const char *string, const char *search_string);

int		close_pipes(t_pipex *pipex);
void	wait_processes(t_pipex *pipex);

char	**split_space_quote(char *str);

void	print_execve_error(t_pipex *pipex, char *cmd_name);
void	print_infile_error(t_pipex *pipex);
void	print_outfile_error(t_pipex *pipex);

void	ft_exit(t_pipex *pipex, const char *err_msg,
			int should_close_pipes, int exit_code);

char	**ft_parse_cmd(const char *cmd);

void	ft_trim(char *str, int c);
bool	ft_has_spaces_only(const char *str);
int		ft_isspace(int c);
char	*find_quote(char *str);

#endif
