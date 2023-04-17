/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:45 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/16 21:04:51 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_move(t_vars *vars)
{
	vars->player += vars->move;
	if (vars->buf[vars->player] == 'C')
		vars->flag++;
	else if (vars->buf[vars->player] == 'E' && vars->flag == vars->cnt_c)
		sl_close(vars);
	vars->buf[vars->player] = 'P';
	if (vars->exit == vars->player - vars->move)
		vars->buf[vars->player - vars->move] = 'E';
	else
		vars->buf[vars->player - vars->move] = '0';
	ft_printf("Step: %d\n", ++vars->step);
}

int	sl_key_hook(int keycode, t_vars *vars)
{
	if (keycode == 0xFF1B)
		sl_close(vars);
	vars->player = 0;
	while (vars->buf[vars->player] != 'P')
		vars->player++;
	vars->move = 0;
	if (keycode == 0x077 && \
		vars->buf[vars->player - (vars->info->col + 1)] != '1')
		vars->move -= vars->info->col + 1;
	else if (keycode == 0x061 && vars->buf[vars->player - 1] != '1')
		vars->move--;
	else if (keycode == 0x064 && vars->buf[vars->player + 1] != '1')
		vars->move++;
	else if (keycode == 0x073 && \
		vars->buf[vars->player + (vars->info->col + 1)] != '1')
		vars->move += vars->info->col + 1;
	else
		return (0);
	sl_move(vars);
	return (0);
}
