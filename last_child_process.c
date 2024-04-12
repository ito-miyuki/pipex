/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:40:33 by mito              #+#    #+#             */
/*   Updated: 2024/04/12 17:06:31 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	last_child_process(t_pipex *pipex, int cmd_index)
// {
// 	int	out_fd;

// 	out_fd = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0777); //Is permission code correct
// 	if (out_fd < 0)
// 	{
// 		clean_up(pipex);
// 		exit (EXIT_FAILURE);
// 	}
// }