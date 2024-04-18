/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:54:36 by mito              #+#    #+#             */
/*   Updated: 2024/04/18 11:03:04 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * PATH=/Users/mito/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki
 * get_paths should return data with 2d array amd it looks like below;
 * 
 *  "/Users/mito/.brew/bin",
 *  "/usr/local/bin", /usr/bin",
 *  ...,
 *  "/Users/mito/.brew/bin"
 * 
 * return NULL if envp is NULL
*/
#include <stdio.h>
#include <string.h>

char	**get_path(char **envp)
{
	int i;
	char **temp;
	char **path;

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