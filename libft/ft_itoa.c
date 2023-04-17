/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:38:10 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/04 13:09:31 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_str(int n, char *str, unsigned int size)
{
	unsigned int	tmp;

	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		*str = '-';
	}
	str += size;
	*str-- = '\0';
	while (1)
	{
		*str-- = (tmp % 10) + '0';
		tmp /= 10;
		if (tmp == 0)
			break ;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	tmp;
	unsigned int	size;
	char			*str;

	tmp = n;
	size = 0;
	if (n < 0)
	{
		tmp = -n;
		size++;
	}
	while (1)
	{
		size++;
		tmp /= 10;
		if (tmp == 0)
			break ;
	}
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	make_str(n, str, size);
	return (str);
}
