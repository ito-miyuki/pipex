/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:38 by mito              #+#    #+#             */
/*   Updated: 2024/04/16 16:13:28 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/*
error handlings:
-file permission
-invalid command
-empty command ""
*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	if (argc < 5)
		return (write(2, "Error", 5), 1); //modify it according to the subject
	if (init_pipex(&pipex, argc - 1, argv + 1, get_path(envp)) < 0) // initialize structs, argv + 1 means move pointer to next one
		return (write(2, "Error", 5), 1); //modify it according to the subject
	if (create_pipes(&pipex) < 0)
		return (write(2, "Error", 5), 1); //modify it according to the subject
	if (start_process(&pipex) < 0) //call fork function
		return (clean_up(&pipex), 1); 
	wait_processes(&pipex); // will return exit status code of every childs
	status = pipex.status;
	clean_up(&pipex);
	return (0);
}