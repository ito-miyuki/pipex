/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:38 by mito              #+#    #+#             */
/*   Updated: 2024/04/12 16:06:33 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Your program will be executed as follows:
./pipex file1 cmd1 cmd2 file2

argv[0]: pipex
argv[1]: file1
argv[2]: cmd1(ex, "ls -l")
argv[3]: cmd2(ex, "wc -l")
argv[4]: file2  

例えば、$> ./pipex infile "ls -l" "wc -l" outfile
*/

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	// int		status;

	if (argc < 5)
		return (write(2, "Error", 5), 1); //modify it according to the subject
	if (init_pipex(&pipex, argc - 1, argv + 1, get_path(envp)) < 0) // initialize structs, argv + 1 means move pointer to next one
		return (write(2, "Error", 5), 1); //modify it according to the subject
	if (create_pipes(&pipex) < 0)
		return (write(2, "Error", 5), 1); //modify it according to the subject
	if (start_process(&pipex) < 0) //call fork function
		return (clean_up(&pipex), 1); 
	// wait_all_processes(&pipex); // will return exit status code of every childs
	// status = pipex.status;
	// cleanup(&pipex);
	return (0);
}