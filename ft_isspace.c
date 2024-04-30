/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:45:35 by mito              #+#    #+#             */
/*   Updated: 2024/04/30 14:30:10 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

bool	ft_has_spaces_only(const char *str)
{
	while (*str != '\0')
	{
		if (!ft_isspace(*str))
			return (false);
		str++;
	}
	return (true);
}

void	ft_trim(char *str, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

char	*find_quote(char *str)
{
	char	prev;

	prev = '\0';
	while (*str != '\0')
	{
		if ((*str == 34 || *str == 39) && prev != '\\')
			return (str);
		prev = *str;
		str++;
	}
	return (NULL);
}
