/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:59:01 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/04 13:55:59 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_d;
	const unsigned char	*tmp_s = src;

	tmp_d = (unsigned char *) dst;
	if (dst > src)
		while (len-- > 0)
			tmp_d[len] = tmp_s[len];
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
