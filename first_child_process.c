/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:40:36 by mito              #+#    #+#             */
/*   Updated: 2024/04/30 14:27:53 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	read_user_input(t_pipex *pipex, int fd_out)
{
	char	buf[1024];
	ssize_t	bytes_read;

	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		bytes_read = read(STDIN_FILENO, buf, 1023);
		buf[bytes_read] = '\0';
		if (bytes_read < 0)
			ft_exit(pipex, "pipex: here_doc(): read fail", 1, 1);
		if ((size_t)bytes_read - 1 == ft_strlen(pipex->limiter)
			&& ft_strncmp(buf, pipex->limiter, (size_t)bytes_read - 1) == 0)
			break ;
		write(fd_out, buf, bytes_read);
	}
}

static void	here_doc(t_pipex *pipex, int cmd_index)
{
	int		fd[2];

	if (pipe(fd) == -1)
		ft_exit(pipex, "pipex: here_doc() fail", 1, 1);
	read_user_input(pipex, fd[1]);
	if (close(fd[1]) < 0)
	{
		close(fd[0]);
		ft_exit(pipex, "pipex: here_doc(): close(fd[1]) fail", 0, 1);
	}
	if (dup2(pipex->pipes[0][1], STDOUT_FILENO) < 0)
	{
		close(fd[0]);
		ft_exit(pipex, "pipex: here_doc(): dup2 stdout fail", 1, 1);
	}
	if (close_pipes(pipex) == -1)
		ft_exit(pipex, "pipex: here_doc(): close_pipes() fail", 0, 1);
	if (dup2(fd[0], STDIN_FILENO) < 0)
		ft_exit(pipex, "pipex: here_doc(): dup2 stdin fail", 0, 1);
	if (close(fd[0]) < 0)
		ft_exit(pipex, "pipex: here_doc(): close(fd[0]) fail", 0, 1);
	call_execve(pipex->envp, pipex->paths, pipex->commands[cmd_index]);
	print_execve_error(pipex, *pipex->commands[cmd_index]);
}

void	first_child_process(t_pipex *pipex, int cmd_index)
{
	int	in_fd;

	if (pipex->here_doc == 1)
		here_doc(pipex, cmd_index);
	else
	{
		if (dup2(pipex->pipes[0][1], STDOUT_FILENO) < 0)
			ft_exit(pipex, "first_child_process(): dup2() STDOUT fail", 1, 1);
		if (close_pipes(pipex) == -1)
			ft_exit(pipex, "first_child_process(): close_pipes() fail", 0, 1);
		in_fd = open(pipex->infile, O_RDONLY);
		if (in_fd < 0)
			print_infile_error(pipex);
		if (dup2(in_fd, STDIN_FILENO) < 0)
		{
			close(in_fd);
			ft_exit(pipex, "first_child_process(): dup2() STDIN fail", 0, 1);
		}
		if (close(in_fd) < 0)
			ft_exit(pipex, "first_child_process(): close(in_fd) fail", 1, 1);
		call_execve(pipex->envp, pipex->paths, pipex->commands[cmd_index]);
		print_execve_error(pipex, *pipex->commands[0]);
	}
}
