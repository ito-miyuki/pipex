/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:15:25 by mito              #+#    #+#             */
/*   Updated: 2024/01/24 10:56:48 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa_upper(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		if (write (1, "-", 1) < 0)
			return (-1);
		return (print_digit(-n, base) - 1);
	}
	else if (n < base)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_hexa_upper(n / base, base);
		if (count < 0)
			return (-1);
		return (count + print_hexa_upper(n % base, base));
	}
}
