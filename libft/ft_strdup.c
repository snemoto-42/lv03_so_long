/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:16:36 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/04 14:04:06 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*rv;

	size = ft_strlen(s1);
	rv = (char *) malloc(sizeof(char) * (size + 1));
	if (rv == NULL)
		return (NULL);
	ft_strlcpy(rv, s1, size + 1);
	return (rv);
}
