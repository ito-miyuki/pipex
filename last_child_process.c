/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:40:33 by mito              #+#    #+#             */
/*   Updated: 2024/04/25 14:51:22 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	last_child_process(t_pipex *pipex, int cmd_index)
{
	int	out_fd;

	out_fd = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644); // check 0644
	if (out_fd < 0)
	{
		close_pipes(pipex);
		print_outfile_error(pipex);
		ft_exit(pipex, 1);
	}
	if (dup2(pipex->pipes[pipex->num_pipes - 1][0], STDIN_FILENO) < 0) //STDIN_FILENO is pointing the last pipes
	{
		write_and_clean_up(pipex);
		exit(1);
		//should I close pipes?
	}
	close_pipes(pipex);
	if (dup2(out_fd, STDOUT_FILENO) < 0)
	{
		write_and_clean_up(pipex);
		exit(1);
		//should I close pipes?
	}
	close(out_fd);
	call_execve(pipex->paths, pipex->commands[cmd_index]);
	print_execve_error(pipex, *pipex->commands[cmd_index]);
}
