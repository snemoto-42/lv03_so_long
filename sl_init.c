/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:45 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/16 22:28:44 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_exit_failure(t_sl_file *info)
{
	free(info);
	write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
	exit(EXIT_FAILURE);
}

void	sl_exit_failure_2(t_sl_file *info, char *buf)
{
	free(buf);
	free(info);
	write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
	exit(EXIT_FAILURE);
}

int	sl_open(t_vars *vars)
{
	sl_put_img(vars->buf, vars->img, vars);
	return (0);
}

int	sl_close(t_vars *vars)
{
	if (vars->buf[vars->player] == 'E')
		ft_printf("Success!!!\n");
	mlx_destroy_image(vars->mlx, vars->img->w);
	mlx_destroy_image(vars->mlx, vars->img->s);
	mlx_destroy_image(vars->mlx, vars->img->c);
	mlx_destroy_image(vars->mlx, vars->img->p);
	mlx_destroy_image(vars->mlx, vars->img->e);
	free(vars->img);
	free(vars->buf);
	free(vars->info);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	sl_exit_success();
	return (0);
}

void	sl_init(t_vars *vars, t_sl_file *info)
{
	vars->win_w = IMG_LEN * info->col;
	vars->win_h = IMG_LEN * (info->row + 1);
	vars->flag = 0;
	vars->step = 0;
	vars->cnt_c = info->cnt_c;
	vars->buf = info->buf;
	vars->info = info;
	vars->exit = 0;
	while (vars->buf[vars->exit] != 'E')
		vars->exit++;
}
