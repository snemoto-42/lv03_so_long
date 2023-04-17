/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:45:50 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/24 23:34:05 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_put_per(t_args *args, int res)
{
	while (args->flag == 0 && args->width-- > 1)
		res += ft_putchar_int(' ');
	while (args->flag == '0' && args->width-- > 1)
		res += ft_putchar_int('0');
	res += ft_putchar_int(args->spec);
	while (args->flag == '-' && args->width-- > 1)
		res += ft_putchar_int(' ');
	return (res);
}

int	ft_put_c(t_args *args, char c, int res)
{
	while (args->flag != '0' && args->spec == 0 && args->width-- > 1)
		res += ft_putchar_int(' ');
	while (args->flag == '0' && args->width-- > 1)
		res += ft_putchar_int('0');
	if (args->spec == 0)
		return (res);
	while (args->flag != '-' && args->width-- > 1)
		res += ft_putchar_int(' ');
	res += ft_putchar_int(c);
	while (args->flag == '-' && args->width-- > 1)
		res += ft_putchar_int(' ');
	return (res);
}

static int	ft_putstrl(char *str, int len)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] && i < len)
		res += ft_putchar_int(str[i++]);
	return (res);
}

int	ft_put_s(t_args *args, char *s, int res)
{
	int		putlen;
	size_t	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (len > INT_MAX)
		return (-1);
	putlen = len;
	if (args->has_prec && putlen > args->prec)
		putlen = args->prec;
	while (args->flag != '-' && args->flag != '0' && args->width-- > putlen)
		res += ft_putchar_int(' ');
	while (args->flag == '0' && args->width-- > putlen)
		res += ft_putchar_int('0');
	res += ft_putstrl(s, putlen);
	while (args->flag == '-' && args->width-- > putlen)
		res += ft_putchar_int(' ');
	return (res);
}
