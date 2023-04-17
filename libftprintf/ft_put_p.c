/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:45:57 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/24 23:05:25 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_get_digits_ptr(uintptr_t ud, int base)
{
	int	digits;

	digits = 0;
	while (ud / base)
	{
		digits++;
		ud /= base;
	}
	digits++;
	return (digits);
}

static int	ft_putp(uintptr_t ud, int pad, int c, int base)
{
	int	res;

	res = 0;
	if (ud / base)
		res += ft_putp(ud / base, pad, c, base);
	if (c == 'p' && (ud % base) >= 10)
		res += ft_putchar_int((ud % base) - 10 + 'a');
	else
		res += ft_putchar_int((ud % base) + '0');
	return (res);
}

int	ft_put_p(t_args *args, void *ptr, int res)
{
	uintptr_t	d;
	int			putlen;

	d = (uintptr_t)ptr;
	putlen = ft_get_digits_ptr(d, 16) + 2;
	while (args->flag != '-' && args->width-- > putlen)
		res += ft_putchar_int(' ');
	res += ft_putchar_int('0') + ft_putchar_int('x');
	res += ft_putp(d, args->pad, args->spec, 16);
	while (args->flag == '-' && args->width-- > putlen)
		res += ft_putchar_int(' ');
	return (res);
}
