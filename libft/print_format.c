/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:25:36 by mito              #+#    #+#             */
/*   Updated: 2024/01/24 10:56:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg(ap, int), 10);
	else if (specifier == 'u')
		count += print_u_int((long)va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += print_digit((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		count += print_hexa_upper((long)va_arg(ap, unsigned int), 16);
	else if (specifier == '%')
		count += print_char('%');
	else if (specifier == 'p')
		count += print_ptr((unsigned long)va_arg(ap, void *));
	else
		count += write(1, &specifier, 1);
	if (count == -1)
		return (-1);
	return (count);
}
