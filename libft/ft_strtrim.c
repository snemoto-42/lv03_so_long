/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:24:45 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/05 11:58:02 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_error(char const *s1, char const *set, int *check)
{
	*check = 0;
	if (s1 == NULL)
	{
		*check = 1;
		return (NULL);
	}
	else if (*s1 == '\0')
	{
		*check = 1;
		return (ft_strdup("\0"));
	}
	else if (*set == '\0')
	{
		*check = 1;
		return (ft_strdup(s1));
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*tmp_sub;
	size_t		len;
	int			check;

	tmp_sub = check_error(s1, set, &check);
	if (check == 1)
		return ((char *)tmp_sub);
	while (*s1 != '\0' && tmp_sub == NULL)
	{
		if (ft_strchr(set, *s1) == NULL)
			tmp_sub = s1;
		s1++;
	}
	if (tmp_sub == NULL)
		tmp_sub = s1;
	len = ft_strlen(tmp_sub);
	while (len > 0)
	{
		if (ft_strchr(set, tmp_sub[len - 1]) == NULL)
			break ;
		len--;
	}
	return (ft_substr(tmp_sub, 0, len));
}
