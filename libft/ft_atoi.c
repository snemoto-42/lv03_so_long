/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:17:37 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/19 18:09:41 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' \
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	check_sign(const char *str)
{
	if (*str == '-')
		return (-1);
	return (1);
}

static int	check_long(unsigned long ret, const char str, int sign)
{
	unsigned long	div;
	unsigned long	mod;

	div = LONG_MAX / 10;
	mod = LONG_MAX % 10;
	if (sign == -1)
		mod++;
	if (ret > div && str)
		return (sign);
	else if (ret == div && (unsigned long)(str - '0') > mod)
		return (sign);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	ret;
	int				sign;

	ret = 0;
	while (ft_isspace(*str))
		str++;
	sign = check_sign(str);
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		if (check_long(ret, *str, sign) == 1)
			return ((int)LONG_MAX);
		else if (check_long(ret, *str, sign) == -1)
			return ((int)LONG_MIN);
		ret = ret * 10 + (*str++ - '0');
	}
	return ((int)(sign * ret));
}
