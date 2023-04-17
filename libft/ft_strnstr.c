/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:08:28 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/05 16:19:45 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char		*tmp_h;
	const char		*tmp_n;

	if (ft_strncmp(needle, "", 1) == 0)
		return ((char *) haystack);
	if (len == SIZE_MAX)
		len = ft_strlen(haystack);
	while (len > 0 && *haystack != '\0')
	{
		if (*haystack == *needle)
		{
			tmp_n = needle;
			tmp_h = haystack;
			while (*tmp_n++ == *tmp_h++ && len-- > 0)
				if (*tmp_n == '\0')
					return ((char *) haystack);
			len += (ft_strlen(needle) - ft_strlen(tmp_n) - 2);
		}
		else
			len--;
		haystack++;
	}
	return (NULL);
}
