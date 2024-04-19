/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:38 by mito              #+#    #+#             */
/*   Updated: 2024/04/19 16:42:09 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/*
error handlings:
-DONE argc check
-invalid command
-file permission
-empty command ""

*/

int	main(int argc, char **argv, char **envp) // main for bonus parts
{
	t_pipex	pipex;
	int		status;

	if (argc < 5)
		return (ft_putstr_fd("Invalid number of arguments.\n", 2), 1);
	if (init_pipex(&pipex, argc - 1, argv + 1, get_path(envp)) < 0) // argv + 1 means move pointer to next one
		return (write_and_clean_up(&pipex), 1);
	if (create_pipes(&pipex) < 0)
		return (write_and_clean_up(&pipex), 1);
	if (start_process(&pipex) < 0)
		return (write_and_clean_up(&pipex), 1);
	wait_processes(&pipex); // will return exit status code of every childs
	status = pipex.status;
	clean_up(&pipex);
	return (0);
}
