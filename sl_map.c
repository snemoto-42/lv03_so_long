/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:45 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/16 22:27:39 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_init_info(t_sl_file *info)
{
	info->buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + (size_t)1);
	if (info->buf == NULL)
		sl_exit_failure(info);
	while (info->n != 0)
	{
		info->n = read(info->fd, info->buf, BUFFER_SIZE);
		if (info->n == -1)
			sl_exit_failure(info);
		info->buf[info->n] = '\0';
		while (*info->buf != '\0')
		{
			if (*info->buf != '\n')
				info->col++;
			if (*info->buf == '\n')
			{
				info->n = info->col;
				if (info->row != 0 && info->col != (size_t)info->n)
					sl_exit_failure(info);
				info->col = 0;
				info->row++;
			}
			info->buf++;
		}
	}
}

static void	sl_check_init(char *file, t_sl_file *info)
{
	size_t	len;

	len = ft_strlen(file);
	if (!(file[len - 4] == '.' && file[len - 3] == 'b' \
		&& file[len - 2] == 'e' && file[len - 1] == 'r' && file[len] == '\0'))
		sl_exit_failure(info);
	info->col = 0;
	info->row = 0;
	info->cnt_p = 0;
	info->cnt_e = 0;
	info->cnt_c = 0;
}

t_sl_file	*sl_check_file(char *file, t_sl_file *info)
{
	sl_check_init(file, info);
	info->fd = open(file, O_RDONLY);
	if (info->fd < 0 || OPEN_MAX < info->fd)
		sl_exit_failure(info);
	info->n = BUFFER_SIZE;
	sl_init_info(info);
	close(info->fd);
	info->n = 0;
	if (info->col < 5 || info->row < 2)
		sl_exit_failure_2(info, info->buf);
	info->buf = info->buf - ((info->col + 1) * info->row + info->col);
	sl_check_map(info->buf, info->col, info->row, info);
	if (!(0 < info->cnt_c && info->cnt_p == 1 && info->cnt_e == 1))
		sl_exit_failure_2(info, info->buf);
	return (info);
}
