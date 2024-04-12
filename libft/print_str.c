/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:23:34 by mito              #+#    #+#             */
/*   Updated: 2024/01/24 10:56:57 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += write(1, "(null)", 6);
		if (count < 0)
			return (-1);
	}
	else
	{
		while (*str != '\0')
		{
			count += print_char((int)*str);
			if (count < 0)
				return (-1);
			str++;
		}
	}
	return (count);
}
