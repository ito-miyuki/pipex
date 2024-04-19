/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:46:35 by mito              #+#    #+#             */
/*   Updated: 2024/04/19 16:49:25 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	msg_incorrect_cmd(char *command)
{
	char *message;

	message = "command not found: ";
	write(2, message, ft_strlen(message));
	write(2, command, ft_strlen(command));
	write(2, "\n", 1);
}