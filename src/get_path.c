/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:54:36 by mito              #+#    #+#             */
/*   Updated: 2024/05/02 18:07:46 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	**temp;
	char	**path;

	i = 0;
	while (envp && envp[i] != NULL)
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			temp = ft_split(envp[i], '=');
			if (temp == NULL)
				return (NULL);
			path = ft_split(temp[1], ':');
			if (path == NULL)
				return (NULL);
			free_grid(temp);
			return (path);
		}
		i++;
	}
	return (NULL);
}
