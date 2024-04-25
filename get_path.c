/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:54:36 by mito              #+#    #+#             */
/*   Updated: 2024/04/23 14:13:39 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_path(char **envp)
{
	int		i;
	char	**temp;
	char	**path;

	i = 0;
	while (envp && envp[i] != NULL) // pointer itself in not null and element is also not null
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			temp = ft_split(envp[i], '='); //first, split like PATH and /Users/mito/.brew/bin:/usr/.....
			// if (temp == NULL) // do I need this part?
			// 	return (NULL);
			path = ft_split(temp[1], ':'); // then split by ';'. "/Users/mito/.brew/bin" "/usr/local/bin" ...
			//if(!path)
			// do error handlimgs for failing malloc
			return (path);
		}
		i++;
	}
	return (NULL);
}
