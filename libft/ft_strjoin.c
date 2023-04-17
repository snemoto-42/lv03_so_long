/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:12:33 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/03 19:27:31 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*rv;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	rv = (char *) malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (rv == NULL)
		return (NULL);
	ft_strlcpy(rv, s1, size_s1 + 1);
	ft_strlcat(rv, s2, size_s1 + size_s2 + 1);
	return (rv);
}
