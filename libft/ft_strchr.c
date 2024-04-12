/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:15:54 by mito              #+#    #+#             */
/*   Updated: 2023/11/15 14:33:19 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*newstr;

	newstr = (char *)str;
	while (*newstr != (char)c)
	{
		if (*newstr == '\0')
			return (NULL);
		newstr++;
	}
	return (newstr);
}
