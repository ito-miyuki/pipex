/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:21:03 by mito              #+#    #+#             */
/*   Updated: 2024/04/30 17:36:30 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	middle_child_process(t_pipex *pipex, int cmd_index)
{
	if (dup2(pipex->pipes[cmd_index][1], STDOUT_FILENO) < 0)
		ft_exit(pipex,
			"middle_child_process(): dup2() STDOUT_FILENO fail", 1, 1);
	if (dup2(pipex->pipes[cmd_index - 1][0], STDIN_FILENO) < 0)
		ft_exit(pipex,
			"middle_child_process(): dup2() STDIN_FILENO fail", 1, 1);
	if (close_pipes(pipex) < 0)
		ft_exit(pipex,
			"middle_child_process(): close_pipes() fail", 0, 1);
	call_execve(pipex->envp, pipex->paths, pipex->commands[cmd_index]);
	print_execve_error(pipex, *pipex->commands[cmd_index]);
}
