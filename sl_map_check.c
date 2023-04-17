/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:45 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/16 22:28:02 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_check(char *buf, size_t col, size_t idx, t_sl_file *info)
{
	if (!(buf[idx] == '1' || buf[idx] == '0' || \
		buf[idx] == 'P' || buf[idx] == 'C' || buf[idx] == 'E'))
		sl_exit_failure_2(info, info->buf);
	if (buf[idx] == 'P' || buf[idx] == 'C' || buf[idx] == 'E')
	{
		if (buf[idx + 1] == '1' && buf[idx - 1] == '1' && \
			buf[idx + (col + 1)] == '1' && buf[idx - (col + 1)] == '1')
			sl_exit_failure_2(info, info->buf);
	}
}

static void	sl_check_col(char *buf, size_t col, size_t row, t_sl_file *info)
{
	size_t	idx;

	idx = 0;
	if (info->ch == '1')
	{
		while (idx + (col + 1) * row < (col + 1) * (row + 1) - 1)
			if (buf[idx++ + (col + 1) * row] != info->ch)
				sl_exit_failure_2(info, info->buf);
	}
	else
	{
		while (idx + (col + 1) * row < (col + 1) * (row + 1) - 1)
		{
			sl_check(buf, col, idx + (col + 1) * row, info);
			if (buf[idx + (col + 1) * row] == info->ch && info->ch == 'C')
				info->cnt_c++;
			else if (buf[idx + (col + 1) * row] == info->ch && info->ch == 'P')
				info->cnt_p++;
			else if (buf[idx + (col + 1) * row] == info->ch && info->ch == 'E')
				info->cnt_e++;
			idx++;
		}
	}
}

void	sl_check_map(char *buf, size_t col, size_t row, t_sl_file *info)
{
	size_t	i_c;
	size_t	i_r;

	i_r = 0;
	while (i_r <= row)
	{
		if (buf[(col + 1) * i_r] != '1' && buf[col + (col + 1) * i_r] != '1')
			sl_exit_failure_2(info, info->buf);
		i_c = 0;
		if (i_r == 0 || i_r == row)
		{
			info->ch = '1';
			sl_check_col(buf, col, i_r, info);
		}
		else
		{
			info->ch = 'C';
			sl_check_col(buf, col, i_r, info);
			info->ch = 'P';
			sl_check_col(buf, col, i_r, info);
			info->ch = 'E';
			sl_check_col(buf, col, i_r, info);
		}
		i_r++;
	}
}
