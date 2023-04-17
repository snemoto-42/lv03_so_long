/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:40:23 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/05 16:17:57 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	arraylen(char const *s, char c, size_t len)
{
	size_t	len_array;
	size_t	i;

	i = 0;
	len_array = 0;
	while (i < len)
	{
		if (s[i] != c)
		{
			len_array++;
			while (s[i] != c && i < len)
				i++;
		}
		else
			i++;
	}
	len_array++;
	return (len_array);
}

static char	**make_free(char **s_array, size_t j)
{
	size_t	i;

	i = 0;
	while (i <= j)
		free(s_array[i++]);
	free(s_array);
	return (NULL);
}

static char	**make_it(char const *s, char c, size_t len, char **s_array)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c)
				if (i++ >= len)
					break ;
			s_array[j] = ft_substr(s + start, 0, i - start);
			if (s_array[j] == NULL)
				return (make_free(s_array, j));
			j++;
		}
		else
			i++;
	}
	s_array[j] = NULL;
	return (s_array);
}

char	**ft_split(char const *s, char c)
{
	char	**s_array;
	size_t	len;
	size_t	len_array;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	len_array = arraylen(s, c, len);
	s_array = (char **) malloc(sizeof(char *) * len_array);
	if (s_array == NULL)
		return (NULL);
	return (make_it(s, c, len, s_array));
}
