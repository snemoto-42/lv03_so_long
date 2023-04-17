/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:59:45 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/05 11:57:52 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rv;

	rv = NULL;
	while (*s)
	{
		if (*s == (char)c)
			rv = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (rv);
}
