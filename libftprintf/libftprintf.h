/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:58:49 by snemoto           #+#    #+#             */
/*   Updated: 2023/02/24 23:08:26 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define CONV "cspdiuxX"
# define FLAG "#-+ 0"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_args
{
	int	flag;
	int	spec;
	int	width;
	int	has_prec;
	int	prec;
	int	pad;
}	t_args;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
int		ft_put_per(t_args *args, int res);
int		ft_put_c(t_args *args, char va_arg, int res);
int		ft_put_s(t_args *args, char *s, int res);
int		ft_put_p(t_args *args, void *ptr, int res);
int		ft_put_d(t_args *args, int d, int res);
int		ft_put_x(t_args *args, unsigned int ud, int res);
int		ft_putchar_int(char c);
int		ft_get_digits_base(unsigned int ud, int c);

#endif
