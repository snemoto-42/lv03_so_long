/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:37:29 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/03 19:52:31 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	n_dst;
	size_t	n_src;

	n_src = ft_strlen(src);
	if (dstsize == 0)
		return (n_src);
	n_dst = ft_strlen(dst);
	if (dstsize <= n_dst)
		return (n_src + dstsize);
	ft_strlcpy(dst + n_dst, src, dstsize - n_dst);
	return (n_src + n_dst);
}
