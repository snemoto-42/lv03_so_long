/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:45:57 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/24 21:24:54 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putx(unsigned int ud, int pad, int c, int res)
{
	int	base;

	base = 16;
	if (c == 'u')
		base = 10;
	while (pad-- > 0)
		res += ft_putchar_int('0');
	if (ud / base)
		res = ft_putx(ud / base, pad, c, res);
	if (c != 'u' && (ud % base) >= 10)
	{
		if (c == 'x')
			res += ft_putchar_int((ud % base) - 10 + 'a');
		else if (c == 'X')
			res += ft_putchar_int((ud % base) - 10 + 'A');
	}
	else
		res += ft_putchar_int((ud % base) + '0');
	return (res);
}

int	ft_put_x(t_args *args, unsigned int ud, int res)
{
	int	len;
	int	putlen;

	len = ft_get_digits_base(ud, args->spec);
	if (args->has_prec && args->prec == 0 && ud == 0)
		len = 0;
	if (args->prec > len)
		args->pad = args->prec - len;
	putlen = len + args->pad;
	if (args->flag == 0 || (args->flag == '0' && args->has_prec) \
		|| (args->flag == '-' && args->has_prec && args->prec == 0 && ud == 0))
		while (args->width-- > putlen)
			res += ft_putchar_int(' ');
	if (args->has_prec && args->prec == 0 && ud == 0)
		return (res);
	while (args->has_prec == 0 && args->flag == '0' && args->width-- > putlen)
		res += ft_putchar_int('0');
	if (args->spec == 'u' && (args->flag == ' ' || args->flag == '+'))
		res += ft_putchar_int(args->flag);
	else if (ud != 0 && args->flag == '#' && ft_strchr("xX", args->spec))
		res += ft_putchar_int('0') + ft_putchar_int(args->spec);
	res = ft_putx(ud, args->pad, args->spec, res);
	while (args->flag == '-' && args->width-- > putlen)
		res += ft_putchar_int(' ');
	return (res);
}
