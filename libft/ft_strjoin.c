/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:54:31 by mito              #+#    #+#             */
/*   Updated: 2024/03/07 18:37:24 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	res = NULL;
	if (s1 && s2)
	{
		res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		i = 0;
		j = 0;
		if (!res)
			return (NULL);
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			res[i++] = s2[j++];
		res[i] = '\0';
	}
	return (res);
}
