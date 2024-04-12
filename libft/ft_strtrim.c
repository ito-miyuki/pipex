/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:23:22 by mito              #+#    #+#             */
/*   Updated: 2023/11/15 14:49:40 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static size_t	char_checker(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

static char	*mem_alloc(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;
	int		i;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while ((s1[start] != '\0') && (char_checker(set, s1[start]) == 1))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_checker(set, s1[end - 1]))
		end--;
	trim = mem_alloc(end - start);
	if (!trim)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
