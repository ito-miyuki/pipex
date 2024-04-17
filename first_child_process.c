/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:59:18 by mito              #+#    #+#             */
/*   Updated: 2024/04/17 19:25:38 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:40:36 by mito              #+#    #+#             */
/*   Updated: 2024/04/17 17:18:15 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"


static void	here_doc(t_pipex *pipex, int cmd_index)
{
	int		fd[2];
	char	buf[1024];
	ssize_t	bytes_read;

	// argc count check
	if (pipe(fd) == -1) // create one pipe
	{
		write(2, "Error", 5); //modify it according to the subject
		exit(1);
	}
	while (1)
	{
		write(STDOUT_FILENO, "heredoc> ", 9);
		// ft_putstr_fd("pipe heredoc> ", 1); // write to stdout
		bytes_read = read(STDIN_FILENO, buf, 1023);
		buf[bytes_read] = '\0';
		// if (bytes_read < 0)
		// {
		// 	// error handlings
		// // 	// close_pipes(pipex); 
		// // 	// clean_up(pipex);
		// }
		if (
			(size_t)bytes_read - 1 == ft_strlen(pipex->limiter)
			&& ft_strncmp(buf, pipex->limiter, (size_t)bytes_read - 1) == 0
		)
			break;
		write(fd[1], buf, bytes_read);
	}
	dup2(pipex->pipes[0][1], STDOUT_FILENO);
	close_pipes(pipex);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	call_execve(pipex->paths, pipex->commands[cmd_index]);
	// From this line, error already happened in execve()
	clean_up(pipex);
	exit(1); // need to modify it later depends on error type
}

void	first_child_process(t_pipex *pipex, int cmd_index)
{
	int in_fd;

	ft_printf("heredoc == %d\n", pipex->here_doc);
	if (pipex->here_doc == 1)
	{
		//ft_printf("heredoc");
		here_doc(pipex, cmd_index); 
	}
	else
	{
		dup2(pipex->pipes[0][1], STDOUT_FILENO);
		close_pipes(pipex);
		in_fd = open(pipex->infile, O_RDONLY);
		if (in_fd < 0)
		{
			clean_up(pipex);
			exit (EXIT_FAILURE);
		}
		dup2(in_fd, STDIN_FILENO); // STDIN_FILENO is now poiting to in_fd
		close(in_fd);
		call_execve(pipex->paths, pipex->commands[cmd_index]);
		// From this line, error already happened in execve()
		clean_up(pipex);
		exit(1); // need to modify it later depends on error type
	}
}
