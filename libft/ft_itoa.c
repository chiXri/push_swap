/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machirin <machirin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:11:56 by machirin          #+#    #+#             */
/*   Updated: 2024/10/07 17:12:56 by machirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(int n)
{
	int	count;

	if (n <= 0)
		count = 1;
	else
		count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	len = count_char(n);
	str = malloc(len + 1);
	nbr = n;
	if (!str)
		return (0);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (--len >= (n < 0))
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}
