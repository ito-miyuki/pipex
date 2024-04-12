/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:45:33 by mito              #+#    #+#             */
/*   Updated: 2024/01/29 10:19:15 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		subcount;

	va_start(ap, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			subcount = print_format(*(++str), ap);
		else
			subcount = write(1, str, 1);
		if (subcount < 0)
		{
			count = -1;
			break ;
		}
		count += subcount;
		str++;
	}
	va_end(ap);
	return (count);
}
