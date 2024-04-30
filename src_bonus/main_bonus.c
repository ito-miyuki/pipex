/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:38 by mito              #+#    #+#             */
/*   Updated: 2024/04/30 14:24:02 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	if (argc < 5)
		return (ft_putendl_fd("Invalid number of arguments.", 2), 1);
	pipex.envp = envp;
	if (init_pipex(&pipex, argc - 1, argv + 1, get_path(envp)) < 0)
		return (write_and_clean_up(&pipex), 1);
	if (create_pipes(&pipex) < 0)
		return (write_and_clean_up(&pipex), 1);
	if (start_process(&pipex) < 0)
		return (write_and_clean_up(&pipex), 1);
	wait_processes(&pipex);
	status = pipex.status;
	clean_up(&pipex);
	return (status);
}
