/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:54:59 by mito              #+#    #+#             */
/*   Updated: 2023/11/16 16:22:45 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*new_hay;
	size_t	needle_len;

	i = 0;
	new_hay = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (len == 0 && (!haystack || !needle))
		return (NULL);
	if (!*needle)
		return (new_hay);
	while (*new_hay != '\0' && i < len && (i + needle_len <= len))
	{
		if (*new_hay == *needle)
		{
			if (ft_strncmp(new_hay, needle, needle_len) == 0)
				return (new_hay);
		}
		new_hay++;
		i++;
	}
	return (NULL);
}
