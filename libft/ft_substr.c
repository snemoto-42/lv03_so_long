/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:10:21 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/04 11:28:39 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*rv;
	size_t			size;
	size_t			s_size;

	if (s == NULL)
		return (NULL);
	s_size = ft_strlen(s);
	if (start > s_size)
	{
		size = 0;
		start = s_size;
	}
	else if (len < s_size - start)
		size = len;
	else
		size = s_size - start;
	rv = (char *) malloc(sizeof(char) * (size + 1));
	if (rv == NULL)
		return (NULL);
	ft_strlcpy(rv, s + start, size + 1);
	return (rv);
}
