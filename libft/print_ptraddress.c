/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptraddress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:01:47 by mito              #+#    #+#             */
/*   Updated: 2024/01/24 10:56:54 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_ptraddress(unsigned long n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_digit(-n, 16) + 1);
	}
	else if (n < 16)
		return (print_char(symbols[n]));
	else
	{
		count = print_ptraddress(n / 16);
		return (count + print_ptraddress(n % 16));
	}
	return (count);
}
