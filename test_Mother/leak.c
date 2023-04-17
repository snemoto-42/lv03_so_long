/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c-leak.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:45 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/16 22:17:26 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
__attribute__((destructor))
void    destructor(void)
{
    int     status;
    char    buf[50];

    snprintf(buf, 50, "leaks %d &> leaksout", getpid());
    status = system(buf);
    if (status)
    {
        write(2, "leak!!!\n", 8);
        system("cat leaksout >/dev/stderr");
        exit(1);
    }
}

void	sl_exit_failure_1(t_sl_file *info)
{
	free(info);
	write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
	exit(EXIT_FAILURE);
}

void	sl_exit_failure_2(void)
{
	write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
	exit(EXIT_FAILURE);
}

void	sl_exit_success(void)
{
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_sl_file	*info;

	info = (t_sl_file *)malloc(sizeof(t_sl_file));
	if (argc != 2 || info == NULL)
		sl_exit_failure_1(info);
	info = sl_check_file(argv[1], info);
	sl_init(&vars, info);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		sl_exit_failure_2();
	vars.win = mlx_new_window(vars.mlx, vars.win_w, vars.win_h, "so_long");
	if (vars.win == NULL)
		sl_exit_failure_2();
	vars.img = sl_make_img(vars.mlx);
	if (vars.img == NULL)
		sl_exit_failure_2();
	sl_put_img(vars.buf, vars.img, &vars);
	mlx_key_hook(vars.win, sl_key_hook, &vars);
	mlx_hook(vars.win, 33, 1L << 17, sl_close, &vars);
	mlx_loop_hook(vars.mlx, sl_open, &vars);
	mlx_loop(vars.mlx);
}
