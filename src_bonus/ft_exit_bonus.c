/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:21:29 by mito              #+#    #+#             */
/*   Updated: 2024/04/30 17:21:32 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exit(t_pipex *pipex, const char *err_msg,
			int should_close_pipes, int exit_code)
{
	if (err_msg != NULL)
		ft_putendl_fd((char *)err_msg, 2);
	if (should_close_pipes == 1)
		close_pipes(pipex);
	clean_up(pipex);
	exit(exit_code);
}
