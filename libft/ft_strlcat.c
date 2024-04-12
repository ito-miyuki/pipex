/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:35:14 by mito              #+#    #+#             */
/*   Updated: 2023/11/17 14:44:22 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	total_len;

	i = 0;
	j = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	while (dst[i] != '\0' && i < dstsize)
		i++;
	if (i < dstsize)
		total_len = i + ft_strlen(src);
	else
		return (dstsize + ft_strlen(src));
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (total_len);
}
