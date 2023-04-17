/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:56:20 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/21 13:45:39 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar_int(char c)
{
	return (write(STDOUT_FILENO, &c, sizeof(char)));
}

static void	init_args(t_args *args)
{
	args->flag = 0;
	args->spec = 0;
	args->has_prec = 0;
	args->width = 0;
	args->prec = 0;
	args->pad = 0;
}

static const char	*read_args(t_args *args, const char *itr)
{
	while (*itr)
	{
		if (ft_strchr(FLAG, *itr))
		{
			args->flag = *itr++;
			if (args->flag == '0' && *itr == '-')
				args->flag = '-';
		}
		if (ft_isdigit(*itr))
			itr += ft_get_digits_base((args->width = ft_atoi(itr)), 10);
		if (*itr == '.')
		{
			args->has_prec = 1;
			itr++;
		}
		if (ft_isdigit(*itr))
			itr += ft_get_digits_base((args->prec = ft_atoi(itr)), 10);
		if (ft_strchr(CONV, *itr) || *itr == '%')
			args->spec = *itr++;
		if (args->spec != 0 || itr++ == '\0')
			break ;
	}
	return (itr);
}

static int	ft_put_conv(t_args *args, va_list ap, int res)
{
	if (args->spec == 0 || args->spec == 'c')
		return (ft_put_c(args, va_arg(ap, int), res));
	else if (args->spec == '%')
		return (ft_put_per(args, res));
	else if (args->spec == 's')
		return (ft_put_s(args, va_arg(ap, char *), res));
	else if (args->spec == 'p')
		return (ft_put_p(args, va_arg(ap, void *), res));
	else if (args->spec == 'd' || args->spec == 'i')
		return (ft_put_d(args, va_arg(ap, int), res));
	else if (args->spec == 'u' || args->spec == 'x' || args->spec == 'X')
		return (ft_put_x(args, va_arg(ap, unsigned int), res));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	t_args	args;
	va_list	ap;

	va_start(ap, format);
	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			init_args(&args);
			format = read_args(&args, format);
			res = ft_put_conv(&args, ap, res);
			if (res == -1)
				return (-1);
			continue ;
		}
		else
			res += ft_putchar_int(*format++);
	}
	va_end(ap);
	return (res);
}
