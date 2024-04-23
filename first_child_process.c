/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:40:36 by mito              #+#    #+#             */
/*   Updated: 2024/04/23 17:34:15 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	here_doc(t_pipex *pipex, int cmd_index)
{
	int		fd[2];
	char	buf[1024];
	ssize_t	bytes_read;

	if (pipe(fd) == -1) // create one pipe
	{
		write_and_clean_up(pipex);
		exit(1);
	}
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1); // write to stdout
		bytes_read = read(STDIN_FILENO, buf, 1023);
		buf[bytes_read] = '\0';
		if (bytes_read < 0)
		{
			close_pipes(pipex); 
			clean_up(pipex);
			exit(1);
		}
		if ((size_t)bytes_read - 1 == ft_strlen(pipex->limiter)
			&& ft_strncmp(buf, pipex->limiter, (size_t)bytes_read - 1) == 0)
			break;
		write(fd[1], buf, bytes_read);
	}
	dup2(pipex->pipes[0][1], STDOUT_FILENO);
	close_pipes(pipex);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	call_execve(pipex->paths, pipex->commands[cmd_index]);
	print_execve_error(*pipex->commands[cmd_index]);
	clean_up(pipex);
	exit(1); // need to modify it later depends on error type
}

void	first_child_process(t_pipex *pipex, int cmd_index)
{
	int in_fd;

	if (pipex->here_doc == 1)
		here_doc(pipex, cmd_index); 
	else
	{
		dup2(pipex->pipes[0][1], STDOUT_FILENO);
		close_pipes(pipex);
		in_fd = open(pipex->infile, O_RDONLY);
		if (in_fd < 0)
		{
			print_file_error(pipex);
			close_pipes(pipex); 
			clean_up(pipex);
			exit (EXIT_FAILURE);
		}
		dup2(in_fd, STDIN_FILENO); // STDIN_FILENO is now poiting to in_fd
		close(in_fd);
		call_execve(pipex->paths, pipex->commands[cmd_index]);
		print_execve_error(*pipex->commands[cmd_index]);
		clean_up(pipex);
		exit (EXIT_FAILURE);; // need to modify it later depends on error type
	}
}
