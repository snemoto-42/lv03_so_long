/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:45 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/16 22:32:30 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		sl_exit_failure(info);
	info = sl_check_file(argv[1], info);
	sl_init(&vars, info);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		sl_exit_failure(info);
	vars.win = mlx_new_window(vars.mlx, vars.win_w, vars.win_h, "so_long");
	if (vars.win == NULL)
		sl_exit_failure(info);
	vars.img = sl_make_img(vars.mlx);
	if (vars.img == NULL)
		sl_exit_failure(info);
	sl_put_img(vars.buf, vars.img, &vars);
	mlx_key_hook(vars.win, sl_key_hook, &vars);
	mlx_hook(vars.win, 33, 1L << 17, sl_close, &vars);
	mlx_loop_hook(vars.mlx, sl_open, &vars);
	mlx_loop(vars.mlx);
}
