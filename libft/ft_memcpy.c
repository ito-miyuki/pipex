/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:19:31 by mito              #+#    #+#             */
/*   Updated: 2023/11/15 14:12:13 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*char_dest;
	char	*char_src;	
	size_t	i;

	char_dest = (char *)dest;
	char_src = (char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (char_dest);
}
