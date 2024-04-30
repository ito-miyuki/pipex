/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_strings_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:21:52 by mito              #+#    #+#             */
/*   Updated: 2024/04/30 17:21:55 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static size_t	count_total_bytes(va_list args, int args_length)
{
	int		i;
	size_t	bytes;

	i = 0;
	bytes = 0;
	while (i < args_length)
	{
		bytes += ft_strlen(va_arg(args, char *));
		i++;
	}
	return (bytes);
}

static void	fill(char *string, va_list args, int args_length)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < args_length)
	{
		temp = va_arg(args, char *);
		while (*temp != '\0')
		{
			*string = *temp;
			string++;
			temp++;
		}
		i++;
	}
	*string = '\0';
}

char	*ft_join_strings(int num_of_strings, ...)
{
	va_list		args_1;
	va_list		args_2;
	size_t		bytes;
	char		*string;

	va_start(args_1, num_of_strings);
	va_copy(args_2, args_1);
	bytes = count_total_bytes(args_1, num_of_strings);
	string = (char *)malloc(sizeof(char) * (bytes + 1));
	if (string == NULL)
		return (NULL);
	fill(string, args_2, num_of_strings);
	va_end(args_1);
	va_end(args_2);
	return (string);
}
