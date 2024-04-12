/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:22:42 by mito              #+#    #+#             */
/*   Updated: 2023/11/15 14:51:19 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	ft_n_len(int n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*new_str(size_t n)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_n_len(n) + 1));
	if (!res)
		return (NULL);
	return (res);
}

static char	*ft_array(char *res, unsigned int nb, long i)
{
	while (nb > 0)
	{
		res[i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int			n_len;
	char		*res;
	int			i;
	long		nb;

	nb = n;
	n_len = ft_n_len(n);
	res = new_str(nb);
	i = 0;
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[i] = '-';
		nb = -nb;
	}
	if (nb > 0)
	{
		i = n_len;
		res = ft_array(res, nb, i);
	}
	res[n_len] = '\0';
	return (res);
}
