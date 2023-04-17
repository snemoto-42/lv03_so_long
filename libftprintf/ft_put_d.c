/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:45:44 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/24 23:06:02 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_get_digits_base(unsigned int ud, int c)
{
	int	digits;
	int	base;

	base = 10;
	if (c == 'x' || c == 'X')
		base = 16;
	digits = 0;
	while (ud / base)
	{
		digits++;
		ud /= base;
	}
	digits++;
	return (digits);
}

static int	ft_put_unbr(unsigned int ud, int res)
{
	if (ud / 10)
		res = ft_put_unbr(ud / 10, res);
	res += ft_putchar_int((ud % 10) + '0');
	return (res);
}

static int	ft_putd(t_args *args, int d, int res, int putlen)
{
	if (d < 0)
		res += ft_putchar_int('-');
	while (args->has_prec == 0 && args->flag == '0' && args->width-- > putlen)
		res += ft_putchar_int('0');
	if (0 <= d && (args->flag == ' ' || args->flag == '+'))
		res += ft_putchar_int(args->flag);
	while (args->pad-- > 0)
		res += ft_putchar_int('0');
	if (d < 0)
		res = ft_put_unbr(-d, res);
	else
		res = ft_put_unbr(d, res);
	return (res);
}

int	ft_put_d(t_args *args, int d, int res)
{
	int	len;
	int	putlen;

	len = ft_get_digits_base(d, 10);
	if (d < 0)
		len = ft_get_digits_base(-d, 10);
	if (args->has_prec && args->prec == 0 && d == 0)
		len = 0;
	if (args->prec > len)
		args->pad = args->prec - len;
	if (d < 0)
		len++;
	putlen = len + args->pad;
	if (args->flag == 0 || (args->flag == '0' && args->has_prec) \
		|| (args->flag == '-' && args->has_prec && args->prec == 0 && d == 0))
		while (args->width-- > putlen)
			res += ft_putchar_int(' ');
	if (args->has_prec && args->prec == 0 && d == 0)
		return (res);
	res = ft_putd(args, d, res, putlen);
	while (args->flag == '-' && args->width-- > putlen)
		res += ft_putchar_int(' ');
	return (res);
}
