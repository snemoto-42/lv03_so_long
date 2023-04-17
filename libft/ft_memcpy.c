/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:08:59 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/04 13:56:03 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp_d;
	const unsigned char	*tmp_s = src;

	if (dst == NULL && src == NULL)
		return (dst);
	tmp_d = (unsigned char *) dst;
	while (n-- > 0)
		*tmp_d++ = *tmp_s++;
	return (dst);
}
