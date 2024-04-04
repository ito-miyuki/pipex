/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:04:04 by mito              #+#    #+#             */
/*   Updated: 2024/04/04 15:34:10 by mito             ###   ########.fr       */
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

#include "pipex.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd_in;
	int fd_out;
	
	if (argc != 5)
		return (0); //odify the return value according to the subject
	
	fd_in = open(argv[1], O_RDONLY);
}