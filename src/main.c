/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:57:38 by mito              #+#    #+#             */
/*   Updated: 2024/05/02 19:35:10 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	if (argc != 5)
		return (ft_putendl_fd("Invalid number of arguments: 4 required", 2), 1);
	pipex.envp = envp;
	if (init_pipex(&pipex, argc - 1, argv + 1, get_path(envp)) < 0)
	{
		write_and_clean_up(&pipex);
		return (EXIT_FAILURE);
	}
	if (create_pipes(&pipex) < 0)
	{
		write_and_clean_up(&pipex);
		return (EXIT_FAILURE);
	}
	if (start_process(&pipex) < 0)
	{
		write_and_clean_up(&pipex);
		return (EXIT_FAILURE);
	}
	wait_processes(&pipex);
	status = pipex.status;
	clean_up(&pipex);
	return (status);
}
