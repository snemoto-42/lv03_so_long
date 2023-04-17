/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:44:48 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/04 13:59:51 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rv;
	size_t	idx;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	rv = (char *) malloc(sizeof(char) * (size + 1));
	if (rv == NULL)
		return (NULL);
	idx = 0;
	while (size-- > 0)
	{
		rv[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	rv[idx] = '\0';
	return (rv);
}
