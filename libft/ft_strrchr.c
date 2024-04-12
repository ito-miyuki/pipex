/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:09:05 by mito              #+#    #+#             */
/*   Updated: 2023/11/15 14:35:51 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	char	*new_str;

	ptr = NULL;
	new_str = (char *)str;
	while (*new_str)
	{
		if (*new_str == (char)c)
			ptr = new_str;
		new_str++;
	}
	if (*new_str == (char)c)
		return (new_str);
	else
		return (ptr);
}
