/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:45 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/13 18:35:18 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*sl_make_img(void *mlx)
{
	t_sl_img	*img;
	int			img_len;

	img_len = IMG_LEN;
	img = (t_sl_img *) malloc(sizeof(t_sl_img));
	if (img == NULL)
		return (NULL);
	img->w = mlx_xpm_file_to_image(mlx, "./textures/1.xpm", &img_len, &img_len);
	if (img->w == NULL)
		return (NULL);
	img->s = mlx_xpm_file_to_image(mlx, "./textures/0.xpm", &img_len, &img_len);
	if (img->s == NULL)
		return (NULL);
	img->c = mlx_xpm_file_to_image(mlx, "./textures/C.xpm", &img_len, &img_len);
	if (img->c == NULL)
		return (NULL);
	img->p = mlx_xpm_file_to_image(mlx, "./textures/P.xpm", &img_len, &img_len);
	if (img->p == NULL)
		return (NULL);
	img->e = mlx_xpm_file_to_image(mlx, "./textures/E.xpm", &img_len, &img_len);
	if (img->e == NULL)
		return (NULL);
	return (img);
}

void	sl_put_img(char *buf, t_sl_img *img, t_vars *vars)
{
	int		x;
	int		y;

	y = 0;
	while (y != vars->win_h)
	{
		x = 0;
		while (x != vars->win_w)
		{
			if (ft_strncmp("1", buf, 1) == 0)
				mlx_put_image_to_window(vars->mlx, vars->win, img->w, x, y);
			else if (ft_strncmp("0", buf, 1) == 0)
				mlx_put_image_to_window(vars->mlx, vars->win, img->s, x, y);
			else if (ft_strncmp("P", buf, 1) == 0)
				mlx_put_image_to_window(vars->mlx, vars->win, img->p, x, y);
			else if (ft_strncmp("C", buf, 1) == 0)
				mlx_put_image_to_window(vars->mlx, vars->win, img->c, x, y);
			else if (ft_strncmp("E", buf, 1) == 0)
				mlx_put_image_to_window(vars->mlx, vars->win, img->e, x, y);
			x += IMG_LEN;
			buf++;
		}
		y += IMG_LEN;
		buf++;
	}
}
