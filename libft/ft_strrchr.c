/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:16:32 by m.chiri           #+#    #+#             */
/*   Updated: 2024/10/07 19:22:27 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_time;

	last_time = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_time = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last_time);
}
