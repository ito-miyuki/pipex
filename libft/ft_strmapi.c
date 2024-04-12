/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:43:42 by mito              #+#    #+#             */
/*   Updated: 2023/11/19 10:23:41 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	res = NULL;
	if (s && f)
	{
		res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		i = 0;
		if (res == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
