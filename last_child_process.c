/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:40:33 by mito              #+#    #+#             */
/*   Updated: 2024/04/29 14:39:33 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	last_child_process(t_pipex *pipex, int cmd_index)
{
	int	out_fd;

	out_fd = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644); // check 0644
	if (out_fd < 0)
		print_outfile_error(pipex);
	if (dup2(pipex->pipes[pipex->num_pipes - 1][0], STDIN_FILENO) < 0)
	{
		close(out_fd);
		ft_exit(pipex, NULL, 1, 1);
	}
	if (close_pipes(pipex) < 0)
		ft_exit(pipex, "pipex: last_child_process(): close_pipes() fail", 0, 1);
	if (dup2(out_fd, STDOUT_FILENO) < 0)
		ft_exit(pipex, "pipex: last_child_process(): dup2() fail", 0, 1);
	if (close(out_fd) == -1)
		ft_exit(pipex, "pipex: first_child_process(): close_pipes() fail", 0, 1);
	call_execve(pipex->envp, pipex->paths, pipex->commands[cmd_index]);
	print_execve_error(pipex, *pipex->commands[cmd_index]);
}
