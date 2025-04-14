/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:25:58 by machirin          #+#    #+#             */
/*   Updated: 2024/10/09 19:38:34 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*copy_word(const char *input, int start, int end)
{
	char	*new_word;

	new_word = malloc(end - start + 1);
	if (!new_word)
		return (NULL);
	ft_strlcpy(new_word, input + start, end - start + 1);
	return (new_word);
}

static int	handle_memory_error(char **split, int j)
{
	while (j > 0)
		free(split[--j]);
	free(split);
	return (0);
}

static int	split_array(char **split, const char *s, char c)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && index >= 0)
		{
			split[j] = copy_word(s, index, i);
			if (!split[j])
				return (handle_memory_error(split, j));
			j++;
			index = -1;
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!split_array(split, s, c))
		return (NULL);
	split[count_words(s, c)] = NULL;
	return (split);
}
